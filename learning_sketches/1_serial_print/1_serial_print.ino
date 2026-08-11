/*
  Serial Print

  Prints the word "Hola" to the Serial Monitor, followed by a newline, repeatedly. 
  
  To see the output data and messages sent by the Arduino board, 
  you need to open the built-in Serial Monitor in the Arduino IDE (Ctrl + Shift + M)

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // Opens the serial port and sets the data rate to 9600 bits per second
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  // Sends the word "Hola" followed by a newline character to the Serial Monitor
  Serial.println("Hola");
}
