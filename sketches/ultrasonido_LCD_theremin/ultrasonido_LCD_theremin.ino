int trigger = 2;
int echo = 3;

int buzz = 5;
int Hz = 0;

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzz, OUTPUT);
  digitalWrite(trigger, LOW);

   // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Theremin");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print("****************");
  // Esperar un segundo
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
long t;
long d = 500;

digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);

t = pulseIn(echo, HIGH);
d = t * 0.034 / 2;

Hz = map(d, 5, 70, 261.63, 1046.50);


if(d <= 70 && d > 5){
  
  tone(buzz, Hz);
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Nota:      ");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print(Hz);
  lcd.print("Hz         ");
}
if(d > 70 ){
  noTone(buzz);
  lcd.clear(); 
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Venga!");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print("pon las manos!");
}
//Serial.println(Hz);

//Serial.println(d);

if(d < 2 && d != 0){
  melod();
 }else{
 noTone(buzz); //finaliza la melodía 
 }
  lcd.print("fin            ");
 



}
