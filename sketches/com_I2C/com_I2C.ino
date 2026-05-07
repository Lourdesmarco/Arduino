#include <Wire.h>

#define SLAVE_ADDR 9
 
int LED = 13;
 
int rd; // Variable para los datos recibidos
int br; // Variable para la freq del blink

void setup() {
 
  pinMode(LED, OUTPUT);
 
  Wire.begin(SLAVE_ADDR);
   
  // Funcion que se ejecuta cuando recibe datos desde el Master
  Wire.onReceive(receiveEvent);
 
  Serial.begin(9600);
  Serial.println("I2C Slave");
}



void loop() {
   delay(50);
 
  // Calculate blink value
  br = map(rd, 1, 255, 100, 2000);
 
  digitalWrite(LED, HIGH);
  delay(br);
  digitalWrite(LED, LOW);
  delay(br);
 
}

void receiveEvent(int) {
  rd = Wire.read();
  Serial.println(rd);
}
