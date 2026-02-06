# RGB-LED

This module controls an RGB LED with four pins:

- **R**: red color control pin
- **G**: green color control pin
- **B**: blue color control pin
- **GND**: ground pin

## How It Works

PWM (Pulse Width Modulation) is a way to control how bright each color is by turning the LED on and off really fast. By changing how long the LED stays on compared to off, you can mix different amounts of red, green, and blue light to create lots of colors.

## Wiring

Connect the R, G, and B pins to your board’s PWM-capable pins(i used pins 11, 10 and 9), and connect the GND pin to the board’s ground.

## Serial Monitor

To make things easier, there’s a function that lets you send RGB values through the Serial Monitor. This way, you can change the LED color without uploading new code every time.

- Set the baud rate in the Serial Monitor to **115200**.
- Send RGB values in the format: `R,G,B` (for example: `255,100,50`).
- Each value should be between 0 and 255.
