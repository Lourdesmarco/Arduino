unsigned long comienzo = 0;
unsigned long tiempoTotal = 0;
unsigned long tiempoLed = 500; //LED blinker time
boolean estado=true;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  comienzo = millis();
}

void loop() {
  
  tiempoTotal = millis();
  
  if(tiempoTotal - comienzo >= tiempoLed){
    estado = !estado;
    digitalWrite(LED_BUILTIN,estado);    
    comienzo = tiempoTotal;
  }


}
