int rojo = 7;
int azul = 8;
int entrada = 2;

int tiempo = 30;
int pulsador = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(azul, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(entrada, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(azul, HIGH);
  delay(tiempo);
  digitalWrite(azul, LOW);
  delay(tiempo);
  digitalWrite(azul, HIGH);
  delay(tiempo);
  digitalWrite(azul, LOW);
  delay(150);

    digitalWrite(rojo, HIGH);
  delay(tiempo);
  digitalWrite(rojo, LOW);
  delay(tiempo);
  digitalWrite(rojo, HIGH);
  delay(tiempo);
  digitalWrite(rojo, LOW);
  delay(150);

  pulsador = digitalRead(entrada);
  if(pulsador == HIGH){
    tiempo = 30;
    }else{
      tiempo = 200;
      }
}
