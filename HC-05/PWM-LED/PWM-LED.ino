#include <SoftwareSerial.h>

const int rxPin = 2;  // HC-05 TX pin
const int txPin = 3;  // HC-05 RX pin
const int LEDPin = 9;
int value = 0;
String message = "";

SoftwareSerial BTSerial(rxPin, txPin); 

void setup() {
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);

  // serial monitor baudrate
  Serial.begin(115200);  
  
  // Bluetooth module connection baudrate
  BTSerial.begin(38400);  
  
  Serial.println("Bluetooth Started. Receiving messages...");
}

void loop() {
  // read received messge until reaching new line
  if (BTSerial.available()) {
      String message = BTSerial.readStringUntil('\n');
      message.trim();

      // Check received message and control output accordingly
      if (message == "OFF") {
        digitalWrite(LEDPin, LOW);
      } else if (message == "ON") {
        digitalWrite(LEDPin, HIGH);
      } else {
        int value = message.toInt();
        if (value >= 0 && value <= 255) {
          analogWrite(LEDPin, value);
        } else {
          Serial.println("Invalid value. It must be between 0 and 255.");
        }
      }
      //print message in serial monitor
      Serial.println(message);
    }
}