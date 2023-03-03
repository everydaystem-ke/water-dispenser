# Automatic Water Dispenser
## Overview
![](/attachments/Dispenser.jpg)

## Demonstration 
![](/attachments/Dispenser.gif)

## Requirements

### Hardware
1. Arduino board
1. Water pump
1. 5V DC power supply
1. Relay (acts as waterpump 12v switch)
1. Ultrasonic distance sensor
1. Waterlevel sensor
1. Breadboard 
1. RGB led
1. Arduino USB cable
1. Jumper cables
1. Tools : Screw driver, gluegun, soldering iron etc...

### Software
1. [Arduino IDE](https://www.arduino.cc/en/software/)

## Instructions
Hardware assembly will be supervised by your teachers in class.

Copy the following code to your IDE windows

```c++
#define SIGNAL_PIN A5
int value;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(2, OUTPUT); //relay
  pinMode(7, OUTPUT); //rgb green
  pinMode(6, OUTPUT); //rgb red
}

void loop()
{

  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  Serial.print("Sensor value: ");
  Serial.println(value);
    
  if (0.01723 * readUltrasonicDistance(8, 9) < 30  && value < 100) {
    digitalWrite(2, HIGH); //relay on
    digitalWrite(7, HIGH); //rgb green on
    digitalWrite(6, LOW); //rgb red off
  } else {
    digitalWrite(2, LOW); //relay off
    digitalWrite(7, LOW); //rgb green off
    digitalWrite(6, HIGH); //rgb red on
  }
  delay(10); // Delay a little bit to improve performance
}
```

Upload the code to your boards 

If successfully uploaded device tests may now be conducted with the permission of your teacher.

In case of any problem do not hesitate to ask for clarification

Pull requests for new features using this hardware are welcome. Students are encouraged to participate and ask questions.
