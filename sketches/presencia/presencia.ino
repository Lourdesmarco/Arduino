
int sensor = 2;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  Serial.println("Comienza calibrado");
  for(int i = 0; i < 60; i++){ //Utilizamos un for para calibrar el sensor, depende del tipo de sensor 
    delay(1000);                //que utilicemos va a cambiar el tiempo de calibración
  }
  Serial.println("Fin calibración");
  delay(50);
}

void loop() {
  value = digitalRead(sensor);
  /*if (value == HIGH){
    digitalWrite(led, HIGH);
    
    }else{
    digitalWrite(led, LOW);
      }
  */
   Serial.println(value);
}
