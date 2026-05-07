
int sensor = 2;
int rele = 3;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(rele,OUTPUT);
  
  Serial.println("Comienza calibrado");
  for(int i = 0; i < 60; i++){ //Utilizamos un for para calibrar el sensor, depende del tipo de sensor 
    //delay(1000);                //que utilicemos va a cambiar el tiempo de calibración
  }
  Serial.println("Fin calibración");
  
  delay(50);
}

void loop() {
  value = digitalRead(sensor);
  if(value == HIGH) //Si el sensor se activa
  {
    digitalWrite(rele,HIGH); //Activa la alarma
    delay(500); //Espera el tiempo definido en la variable "tiempo"
    digitalWrite(rele,LOW); //Desconecta la alarma
  }
 
   Serial.println(value);
}
