#include <CapacitiveSensor.h>
int pinsalida=13;
int pinzumbador = 12; 
CapacitiveSensor misensor=CapacitiveSensor(2,3);

void setup() {
  Serial.begin(9600);
  pinMode(pinsalida, OUTPUT);  
  misensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
   
   long valorled = misensor.capacitiveSensor(30);
   if (valorled > 0){
    digitalWrite(pinsalida, LOW);
    noTone(pinzumbador);   
   } else {
    digitalWrite(pinsalida, HIGH);
    
    tone(pinzumbador,80); 
   }
   
    Serial.println(valorled); 
    delay(10);
}
