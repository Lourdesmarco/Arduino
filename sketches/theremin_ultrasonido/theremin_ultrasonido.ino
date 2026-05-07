int trigger = 2;
int echo = 3;
int buzz = 8;
int Hz = 0;
long tiempo;
long distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
  //digitalWrite(trigger, LOW);
  delay(1000);
}

void loop() {
  digitalWrite(trigger, HIGH); //envío pulso 10 microsec
  delayMicroseconds(10);
  digitalWrite(trigger, LOW); 
  
  tiempo = pulseIn(echo, HIGH);  //esperamos respuesta del pulso
  distancia = tiempo / 58;
  
  Hz = map(distancia, 5, 100,  0, 5000);
  
  if(distancia <= 100 && distancia >= 5){
    tone(buzz, Hz);
    delay(50);
  } else{
    noTone(buzz);
  }
}
