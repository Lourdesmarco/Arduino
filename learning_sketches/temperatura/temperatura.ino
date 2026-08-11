
int temperatura; //variable para la temperatura
 
void setup(){

 Serial.begin (9600); //inicia comunicacion serial
}
 
void loop(){
  //Calcula la temperatura usando como referencia 5v
  temperatura = (5.0 * analogRead(A0) * 100)/1023.0;
  Serial.write (temperatura); //escribe la temperatura en el serial
  delay (2000); //espera 2 segundos para la siguiente medicion
}
