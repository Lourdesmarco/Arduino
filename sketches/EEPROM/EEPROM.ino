#include <EEPROM.h> //Incluimos librería EEPROM
#include "Servo.h" //Incluimos librería Servo
 
int PotPin = 0; //Pin analógico del potenciómetro 
 
int valPot = 0; 
 
// Byte to hold data read from EEPROM
byte readVal = 0; //variable byte donde iremos guardando los datos leidos de la EEPROM

int maxaddress = EEPROM.length(); //Definimos el espacio de memoria
 
Servo myservo; //Declaramos variable servo

 
void setup(){
  attachInterrupt(digitalPinToInterrupt(),boton,RISING);
  Serial.begin(9600);

  myservo.attach(9); // Servo al pin9
 
  Serial.println("Empieza a escribir en la EEPROM...");
 
  for (int address = 0; address <= maxaddress; address++) { //Iteramos para pasar por cada celda de memoria guardando el valor del potenciómetro

    valPot = map(analogRead(PotPin), 0, 1023, 0, 180); //Mapeamos los valores del pot a los del servo
 
    myservo.write(valPot); //Mandamos la posición a dónde se tiene que colocar el servo
    delay(15); //Pequeño delay para que se ajuste la posición
 
    EEPROM.write(address, valPot); //Escribimos en memoria los valores del pot
    delay(5); //Pequeño delay para que de tiempo a salvar en cada celda (3,3ms)

    //Vamos mostrando por monitor serie el valor que se va guardando en cada dirección de la eeprom
    Serial.print("ADDR = ");
    Serial.print(address);
    Serial.print("\t");
    Serial.println(valPot);
 
  }
 
  Serial.println("Grabación terminada! 5s para el playback");
 
  delay(5000);
 
  Serial.println("Ahora comienza el playback...");
 
 
  for (int address = 0; address <= maxaddress; address++) { //Iteración para leer los valores en cada dirección de la eeprom

    readVal = EEPROM.read(address); //pasamos las lecturas a la variable readVal
 
    myservo.write(readVal); //pasa la lectura al servo
    delay(15);
 
    Serial.print("ADDR = ");
    Serial.print(address);
    Serial.print("\t");
    Serial.print(readVal,DEC); //con DEC le decimos que muestre el valor en decimal
    Serial.println();
 
  }
 
  Serial.println("Playback terminado!");

  
 
}
 
void loop()
{
 
}
