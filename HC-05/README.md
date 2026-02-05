# HC-05 Bluetooth Module

## Overview

The HC-05 is a popular Bluetooth serial module used for wireless communication between microcontrollers and other Bluetooth devices. It works in both master and slave modes and is often used in projects for wireless data transfer.

## Operating Modes

The HC-05 has two main modes:

- **Data Mode:** This is for regular wireless data transfer. After pairing with another Bluetooth device, the module sends and receives serial data.
- **AT Mode:** This mode lets you configure the module using AT commands, like changing the device name, baud rate, or role.

## AT Mode Setup

To get into AT mode on the HC-05:

1. Connect the KEY (or EN) pin to 3.3V before turning on the module.
2. Power on the module; the LED will blink slowly (about every 2 seconds) showing it’s in AT mode.
3. Use a serial terminal at 38400 baud (the default AT mode speed) to send AT commands.

Note: Some modules might need a different way to enter AT mode; check your module’s datasheet (more details in PWM-LED project).

## Common AT Commands

Here are some common AT commands to configure the HC-05:

- `AT` - Test command; should reply with "OK".
- `AT+NAME=name` - Set the Bluetooth device name.
- `AT+ROLE=0/1` - Set device role (0 = slave, 1 = master).
- `AT+UART=baud,stop,parity` - Set UART settings like baud rate.
- `AT+PSWD=xxxx` - Set pairing password.
- `AT+ADDR?` - Check device address.
- `AT+VERSION?` - Check firmware version.

## Electrical Notes

- The module’s VCC pin needs either 3.3V or 5V power depending on your module version; check your specific one.
- The KEY pin is for enabling AT mode; leave it disconnected or low for normal data mode.

## General Notes

- The HC-05 defaults to 9600 baud in data mode and 38400 baud in AT mode.
- When talking to the module, make sure your serial terminal or microcontroller UART settings match the module’s baud rate.
- After configuring, disconnect the KEY pin and restart the module to go back to data mode.
