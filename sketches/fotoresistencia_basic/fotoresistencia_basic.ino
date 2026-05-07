
/* Defino variables  */
int fotoPin = A0;
int fotoValue = 0;

void setup() {
  /* Configuro el monitor de serie  */
  Serial.begin(9600);
}

void loop() {
 /* Leo el valor del sensor de luz  */
 fotoValue = analogRead(fotoPin);
 
 /* Envío el valor por el puerto serie  */
 Serial.write(fotoValue);
 
 delay(100);
}
