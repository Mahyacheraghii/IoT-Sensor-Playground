const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

int r, g, b;

void setup()
{
    // serial protocol setup
    Serial.begin(115200);
    Serial.println("Type R,G,B (0-255) and press Enter");

    // make pins output
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // turn LED off
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}

void getColor()
{
    Serial.println("Type RGB values (0-255) separated by commas:");

    while (Serial.available() == 0)
    {
    } // wait for input
    String input = Serial.readStringUntil('\n');

    // parse input
    int comma1 = input.indexOf(',');
    int comma2 = input.lastIndexOf(',');

    if (comma1 != -1 && comma2 != -1 && comma1 != comma2)
    {
        // read input
        r = constrain(input.substring(0, comma1).toInt(), 0, 255);
        g = constrain(input.substring(comma1 + 1, comma2).toInt(), 0, 255);
        b = constrain(input.substring(comma2 + 1).toInt(), 0, 255);

        // print recieved value
        Serial.print("Color set to: ");
        Serial.print(r);
        Serial.print(",");
        Serial.print(g);
        Serial.print(",");
        Serial.println(b);
    }
    else
    {
        Serial.println("Invalid input! Use format: R,G,B");
    }
}

void loop()
{

    // get color from serial monitor
    getColor();

    // write input values in pins
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}
