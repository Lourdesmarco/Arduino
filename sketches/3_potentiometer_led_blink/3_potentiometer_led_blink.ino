/*
  Potentiometer to adjust the blinking led time

  Reads the analog value from a potentiometer on pin A0 and uses it to adjust the blinking delay, repeatedly.
*/

const int potPin = A0; // Pin number connected to the potentiometer --> 14 internally
const int ledPin = 3; // Pin number connected to the LED

int potValue = 0; // Variable to store the raw analog value from the potentiometer (0 to 1023)


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT); //Initialise LED pin (OUTPUT type)
  Serial.begin(9600); // Opens the serial port and sets the data rate to 9600 bits per second
}

// the loop function runs over and over again forever
void loop() {
 potValue = analogRead(potPin); // Reads the voltage level on pin A0
 Serial.println(potValue); // Sends the value followed by a newline to the Serial Monitor

 digitalWrite(ledPin, HIGH); // Turns on the LED
 delay(potValue); // Waits for the duration defined by the potentiometer value
 digitalWrite(ledPin, LOW); // Turns off the LED
 delay(potValue); // Waits for the duration defined by the potentiometer value
}
