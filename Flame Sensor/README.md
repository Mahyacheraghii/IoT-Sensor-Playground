# Flame Sensor

The infrared (IR) flame sensor is designed to detect the presence of a flame or fire source. It senses the IR light emitted by flames. When it detects a flame, the IR receiver picks up the IR light and triggers the output pins to change state.

The sensor specifically detects infrared wavelengths between 760nm and 1100nm, which are emitted by flames but not by normal visible light. This allows the sensor to distinguish flames from other light sources and avoid false detections caused by visible light.

## Pins and Connections

The sensor module usually comes with three pins:

- **VCC**: Connect to 3.3V or 5V power supply.
- **GND**: Connect to ground.
- **DO (Digital Output)**: Outputs HIGH or LOW depending on flame detection.
- **AO (Analog Output)**: Outputs an analog voltage proportional to the flame intensity.

> Note: Some modules have both AO and DO pins; others may only have DO.

- **Digital Output (DO):**  
  This pin gives a simple HIGH or LOW signal. When a flame is detected, the DO pin typically goes LOW (or HIGH depending on the sensor's configuration). This is useful for simple yes/no flame detection.

- **Analog Output (AO):**  
  This pin outputs a voltage that changes with the flame's intensity. You can read this value with an analog input pin on your microcontroller to get more detailed information about the flame.

## Note:

- **Distance:**  
  The sensor works best within a range of about 0 to 80 cm from the flame. Keep in mind safety precautions when testing with real flames.

- **Avoid Interference:**  
  IR light from other sources (like sunlight or incandescent bulbs) can affect readings. Test in a controlled environment if possible.
