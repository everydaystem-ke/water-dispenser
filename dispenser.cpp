// C++ code
//
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

