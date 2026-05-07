
/* Defino variables para los pines y el valor del potenciómetro */
int potPin = A0;
int ledPin = 9;
int potValue = 0;
int mapPotValue = 0;

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

  /* Mapeo (escalo) el valor recibido del potenciometro  */
  /* MIN, MAX del potenciometro a MIN, MAX del LED  */
  mapPotValue = map(potValue, 0, 1023, 0, 255);
  
  /* Enciendo el LED y le atribuyo el valor mapeado del pot.
  IMPORTANTE: tengo que cambiar a escritura analógica */
  analogWrite(ledPin, mapPotValue);

}
