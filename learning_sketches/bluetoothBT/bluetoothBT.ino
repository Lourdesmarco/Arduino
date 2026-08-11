#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX

char dato = 0;
int led1 = 3;    
int led2 = 5;   

int brilloLed;

boolean state = false;
boolean state2 = false;

void setup(){
  miBT.begin(38400); 
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
}

void loop(){
  if (miBT.available()){  // si hay informacion disponible desde modulo
    dato = miBT.read();   // almacena en dato el caracter recibido desde modulo
  
    if( dato == '1') { //on/off led 1
      state = !state;
      digitalWrite(led1, state);
    }

    if( dato == '2' ) {//on/off led 2
      state2 = !state2;
      digitalWrite(led2, state2);
    }

    if( dato == '3' ) { //baja intensidad del led 1
      
          brilloLed = brilloLed-10;
      if (brilloLed < 0){
        brilloLed=0;
      }
      analogWrite(led1,brilloLed);
    }
    if( dato == '4' ) { //sube intensidad del led 1
      brilloLed = brilloLed+10;
      if (brilloLed > 255){
        brilloLed=255;
      }
      analogWrite(led1,brilloLed);
      
    }


  }
}
