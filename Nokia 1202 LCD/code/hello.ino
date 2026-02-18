#include <Arduino.h>

#define CS 10
#define RST 9
#define SDA 11
#define SCL 13
#define BL 3.3 // بک‌لایت وصل به 3.3V

// فرستادن بیت تکی روی نرم‌افزار (bit-banging)
void sendBit(bool bit)
{
    digitalWrite(SDA, bit);
    digitalWrite(SCL, HIGH);
    delayMicroseconds(1);
    digitalWrite(SCL, LOW);
}

// فرستادن ۹ بیت: بیت ۹ مشخص‌کننده نوع (0 = command, 1 = data)
void send9Bit(bool isData, uint8_t value)
{
    // بیت 9
    sendBit(isData);

    // 8 بیت دیتا
    for (int i = 7; i >= 0; i--)
    {
        sendBit(bitRead(value, i));
    }
}

void lcdCommand(uint8_t cmd)
{
    digitalWrite(CS, LOW);
    send9Bit(0, cmd); // 0 = command
    digitalWrite(CS, HIGH);
}

void lcdData(uint8_t data)
{
    digitalWrite(CS, LOW);
    send9Bit(1, data); // 1 = data
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
        lcdCommand(0xB0 | page); // set page
        lcdCommand(0x10);        // column high
        lcdCommand(0x00);        // column low
        for (int col = 0; col < 96; col++)
        {
            lcdData(0x00);
        }
    }
}

// فونت ساده 5x7 برای HELLO
const uint8_t font_H[5] = {0x7F, 0x08, 0x08, 0x08, 0x7F};
const uint8_t font_E[5] = {0x7F, 0x49, 0x49, 0x49, 0x41};
const uint8_t font_L[5] = {0x7F, 0x40, 0x40, 0x40, 0x40};
const uint8_t font_O[5] = {0x3E, 0x41, 0x41, 0x41, 0x3E};

void printChar(const uint8_t *ch)
{
    for (int i = 0; i < 5; i++)
    {
        lcdData(ch[i]);
    }
    lcdData(0x00); // فاصله بین حروف
}

void setup()
{
    pinMode(CS, OUTPUT);
    pinMode(RST, OUTPUT);
    pinMode(SDA, OUTPUT);
    pinMode(SCL, OUTPUT);

    digitalWrite(SDA, LOW);
    digitalWrite(SCL, LOW);

    // بک‌لایت روشن (اگه وصل به پین دیگه)
    // digitalWrite(BL, HIGH);

    lcdInit();
    lcdClear();

    // چاپ HELLO روی صفحه
    lcdCommand(0xB0); // page 0
    lcdCommand(0x10);
    lcdCommand(0x00);

    printChar(font_H);
    printChar(font_E);
    printChar(font_L);
    printChar(font_L);
    printChar(font_O);
}

void loop()
{
}