
/* Defino variables para los pines y el valor del potenciómetro */
int potPin = A0;
int ledPin = 9;
int potValue = 0;

void setup() {
  /* Configuro el pin del led como tipo output  */
  pinMode(ledPin, OUTPUT);
  /* Configuro el monitor de serie  */
  Serial.begin(9600);
}

void loop() {
  /* Leo el valor del potenciometro  */
 potValue = analogRead(potPin);
 /* Pinto en el monitor serie el valor  */
 Serial.println(potValue);

}
