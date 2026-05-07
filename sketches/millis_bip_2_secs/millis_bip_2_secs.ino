int buzzer = 5;   
int presion = A0; 
int value = 0;  
boolean state= false;

boolean hasonado= false;

unsigned long comienzo = 0;
unsigned long tiempoTotal = 0;
unsigned long tiempoPitido = 2000; //Tiempo que tiene que estar pitando

void setup()
{
Serial.begin (9600);
pinMode(presion,INPUT); 
pinMode(buzzer,OUTPUT);   

//comienzo = millis(); // recojo el 0 del comienzo
}


void loop()
{
value = analogRead(presion);
  Serial.println(value);
  
  if(value > 500){

      tiempoTotal = millis();
      if((tiempoTotal - comienzo > tiempoPitido) && (hasonado == false)){
          comienzo = tiempoTotal;
        
         if(state == true){
            state = false;
            noTone(buzzer);
            hasonado = true;
          }else{
            state = true;
            tone(buzzer,1000);    
          }
      }  
    
  
  }else{
    noTone(buzzer);
    hasonado = false;
  }
}
