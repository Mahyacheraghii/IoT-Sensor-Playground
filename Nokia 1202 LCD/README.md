# Nokia 1202 LCD Display

The Nokia 1202 LCD display is a simple and low-power display used in the old Nokia 1202 phone models. س

## Display Model

The exact model of this display is usually known as Nokia 1202 LCD. This display typically has a resolution of 96x65 pixels and uses the SPI interface for communication with the microcontroller.

## Voltage Issue

One common problem when using this display is the difference between its operating voltage and the Arduino operating voltage. The Nokia 1202 display usually operates at 3 volts, while many Arduino boards such as Arduino UNO operate at 5 volts. This voltage difference can damage the display.

### Solutions:

1. Use a Level Shifter: To reduce the Arduino signal voltage from 5 volts to 3.3 volts, a level shifter can be used.
2. Use a Voltage Divider: By using two resistors, the signal voltage can be reduced.
3. Use an Arduino board with 3.3 volts operating voltage such as Arduino Due or boards based on ESP8266/ESP32.

## SPI Connection with Arduino

The Nokia 1202 LCD display communicates using the SPI protocol but does not have a dedicated DC (Data/Command) pin. Instead, it requires a 9-bit SPI communication format where the first bit indicates whether the following 8 bits are a command (0) or data (1). Since standard SPI hardware on Arduino UNO supports only 8-bit frames, it cannot directly handle this 9-bit data format.

To overcome this, the 9-bit SPI communication must be implemented in software using a technique called bit-banging. This involves manually controlling the clock and data lines in code to send the extra bit before the standard 8 data bits. By doing so, the Arduino can emulate the required 9-bit SPI protocol, allowing it to distinguish commands from data correctly and communicate effectively with the Nokia 1202 LCD despite the hardware limitations.

### Pin Connection Table to Arduino UNO

| Nokia 1202 LCD Display Pin | Arduino UNO Pin | Description          |
| -------------------------- | --------------- | -------------------- |
| VCC                        | 3.3V            | Display power supply |
| GND                        | GND             | Ground               |
| SCK (Clock)                | 13              | SPI clock            |
| MOSI (Data)                | 11              | SPI data             |
| CS (Chip Select)           | 10              | Chip select          |
| RESET                      | 9               | Display reset        |
| DC (Data/Command)          | 8               | Data/command select  |

![firmware](./firmware.jpeg)
