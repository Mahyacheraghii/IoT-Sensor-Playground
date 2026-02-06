## Introduction

This project controls an RGB LED by setting its color through specified RGB values. It allows changing the LED color by sending the desired color values, which the LED then displays. The setup provides a straightforward way to experiment with different colors on an RGB LED.

## Wiring

Connect the R, G, and B pins to your board’s PWM-capable pins(i used pins 11, 10 and 9), and connect the GND pin to the board’s ground.

## Serial Monitor

To make things easier, there’s a function that lets you send RGB values through the Serial Monitor. This way, you can change the LED color without uploading new code every time.

## usage

The RGB LED receives color values through the Serial Monitor. Arduino reads the input, parses the R, G, and B values, and updates the LED using PWM signals.

## Note

- Set the baud rate in the Serial Monitor to **115200**.
- Send RGB values in the format: `R,G,B` (for example: `255,100,50`).
- Each value should be between 0 and 255.

![firmware](./firmware.jpg)
