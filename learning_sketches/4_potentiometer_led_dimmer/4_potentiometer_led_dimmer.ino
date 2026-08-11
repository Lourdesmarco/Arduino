/*
  Potentiometer to adjust the blinking led time

  Reads the analog value from a potentiometer on pin A0 and uses it to adjust the blinking delay, repeatedly.
*/

const int potPin = A0; // Pin number connected to the potentiometer --> 14 internally
const int ledPin = 3; // Pin number connected to the LED

int potValue = 0; // Variable to store the raw analog value from the potentiometer (0 to 1023)
int mapPotValue = 0; // Variable to store the mapped value -> from potentiometer (0 to 1023) to LED (0 to 255)

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT); //Initialise LED pin (OUTPUT type)
}

// the loop function runs over and over again forever
void loop() {
 potValue = analogRead(potPin); // Reads the voltage level on pin A0

/*
Maps potValue (raw analog value from the potentiometer)
potentiometer MIN, MAX to LED MIN, MAX
*/
 mapPotValue = map(potValue, 0, 1023, 0, 255); 

/* Turns on the LED and assigns the mapped value of the potentiometer to it.
  IMPORTANT: it must be an analog write for the dimmer to work */
 analogWrite(ledPin, mapPotValue);
}
