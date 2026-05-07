
#include <dht11.h>
     
#define SensorDHT11 7
     
dht11 ValorDHT11;

int R = 6;
int G = 5;
int B = 3;
       
void setup(){
  Serial.begin(9600);   
  pinMode(B, OUTPUT);  
  pinMode(G, OUTPUT);  
  pinMode(R, OUTPUT); 
}
      
void loop(){
        
   Serial.println("\n");
      
   ValorDHT11.read(SensorDHT11);
                             
      
   float h =ValorDHT11.humidity;
   Serial.print("Humidity (%): ");
   Serial.println(h);
      
   float t =ValorDHT11.temperature;
   Serial.print("Temperature (C): ");
   Serial.println(t);

//azul
   if(t <= 20){
   analogWrite(R, 0);
   analogWrite(G, 0);
   analogWrite(B, 255);
    }
 //naranja
    if(t > 20 && t <= 30){
   analogWrite(R, 228);
   analogWrite(G, 158);
   analogWrite(B, 67);
   //228, 158, 67
   
    }
 //rojo
    if(t > 30){
   analogWrite(R, 255);
   analogWrite(G, 0);
   analogWrite(B, 0);
   
    }
   
   delay(2000);
}
