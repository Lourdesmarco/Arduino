

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int foto = A0;
int value;

int led = 13;
int conv;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int puntos = 0;

void setup()
{
   pinMode(foto, INPUT);
   pinMode(led, OUTPUT);

   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
   
  lcd.begin(16, 2);
  lcd.home ();
  lcd.print("Basket");
  lcd.setCursor ( 0, 1 );
  lcd.print("play");
  // Esperar un segundo
  delay(1000);

    mostrarnum(puntos);

}

void loop()
{
  value = analogRead(foto);

  if(value < 700){
    if(puntos < 5){
    puntos++;
    apagar();
    mostrarnum(puntos);
    delay(2000);  
     }else{
      puntos = 0;
      }
    
    };
  conv = map(value,190, 869, 0, 255);


  lcd.clear ();
  lcd.home ();
  lcd.print("Luz recibida");
  lcd.setCursor ( 0, 1 );
  lcd.print(value);
  delay(100);

  
}

void apagar(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  }

void mostrarnum(int num){

    switch (num) {
    case 1:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      break;
    case 4:
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      break;
    default:
    //cero
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
    break;
  }
}
