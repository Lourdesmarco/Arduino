/*
  LDR (photocell) read & print

  Reads the analog value from a LDR on pin A0 and prints it to the Serial Monitor, repeatedly.
*/

int ldrPin = A0; // Pin number connected to the analog sensor --> 14 internally
int ldrValue = 0; // Variable to store the raw analog value (0 to 1023)

// the setup function runs once when you press reset or power the board
void setup() {
  // Opens the serial port and sets the data rate to 9600 bits per second
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
 ldrValue = analogRead(ldrPin);  // Reads the voltage level on pin A0
 Serial.println(ldrValue); // Sends the value followed by a newline to the Serial Monitor

 delay(500); // Waits for 500 milliseconds before the next reading
}
