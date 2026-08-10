/*
  Potentiometer read & print


*/
int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
 sensorValue = analogRead(sensorPin);
 Serial.println(sensorValue);
 digitalWrite(ledPin, HIGH);
 delay(sensorValue);
 digitalWrite(ledPin, LOW);
  
 delay(sensorValue);
}
