#include <Arduino.h>

#define CS 10
#define RST 9
#define SDA 11
#define SCL 13

void sendBit(bool bit)
{
    digitalWrite(SDA, bit);
    digitalWrite(SCL, HIGH);
    delayMicroseconds(1);
    digitalWrite(SCL, LOW);
}

void send9Bit(bool isData, uint8_t value)
{
    sendBit(isData);
    for (int i = 7; i >= 0; i--)
    {
        sendBit(bitRead(value, i));
    }
}

void lcdCommand(uint8_t cmd)
{
    digitalWrite(CS, LOW);
    send9Bit(0, cmd);
    digitalWrite(CS, HIGH);
}

void lcdData(uint8_t data)
{
    digitalWrite(CS, LOW);
    send9Bit(1, data);
    digitalWrite(CS, HIGH);
}

void lcdInit()
{
    digitalWrite(RST, LOW);
    delay(50);
    digitalWrite(RST, HIGH);
    delay(50);

    lcdCommand(0xE2); // soft reset
    lcdCommand(0xA4); // normal display
    lcdCommand(0x2F); // power control
    lcdCommand(0xA0); // segment direction
    lcdCommand(0xAF); // display ON
}

void lcdClear()
{
    for (int page = 0; page < 9; page++)
    {
        lcdCommand(0xB0 | page);
        lcdCommand(0x10);
        lcdCommand(0x00);
        for (int col = 0; col < 96; col++)
        {
            lcdData(0x00);
        }
    }
}

void lcdPattern(uint8_t pattern)
{
    for (int page = 0; page < 9; page++)
    {
        lcdCommand(0xB0 | page);
        lcdCommand(0x10);
        lcdCommand(0x00);
        for (int col = 0; col < 96; col++)
        {
            lcdData(pattern);
        }
    }
}

void setup()
{
    pinMode(CS, OUTPUT);
    pinMode(RST, OUTPUT);
    pinMode(SDA, OUTPUT);
    pinMode(SCL, OUTPUT);

    digitalWrite(SDA, LOW);
    digitalWrite(SCL, LOW);

    lcdInit();
    lcdClear();
}

void loop()
{
    lcdPattern(0xFF); // همه روشن
    delay(500);
    lcdPattern(0x00); // همه خاموش
    delay(500);
    lcdPattern(0xAA); // الگوی چشمک زن 101010
    delay(500);
    lcdPattern(0x55); // الگوی چشمک زن 010101
    delay(500);
}