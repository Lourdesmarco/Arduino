unsigned long tiempo = 0;
unsigned long tiempoLed = 0; //verde
unsigned long tiempoLed2 = 250; //amarillo
unsigned long tiempoLed3 = 500; //rojo

int blinker=500;

boolean estado=true;
boolean estado2=false;
boolean estado3=false;

int led2 = 12;
int led3 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiempo = millis();
  if(tiempo >= tiempoLed+blinker){
    tiempoLed=tiempo;  
    estado = !estado;
    digitalWrite(LED_BUILTIN,estado);
    
  }

  if(tiempo >= tiempoLed2+blinker){
    tiempoLed2=tiempo;  
    estado2 = !estado2;
    
    digitalWrite(led2,estado2); 
  }

  if(tiempo >= tiempoLed3+blinker){
    tiempoLed3=tiempo;  
    estado3 = !estado3;
    
    digitalWrite(led3,estado3); 
  }
}
