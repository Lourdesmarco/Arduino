int trigger = 2;
int echo = 3;

int led = 5;
int brillo = 0;

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

  pinMode(led, OUTPUT);
  digitalWrite(trigger, LOW);

   // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Sensor");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print("de distancia");
  // Esperar un segundo
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
long t;
long d;

digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);

t = pulseIn(echo, HIGH);
d = t * 0.034 / 2;

brillo = map(d, 2, 400, 0, 255);
if(d <= 20 && d > 2){
  digitalWrite(led, HIGH);
  delay(10*d);
  digitalWrite(led, LOW);
  delay(10*d);
}


Serial.println(brillo);

lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Distancia:");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print(d);
  lcd.print("cm       ");

  
Serial.print("Distancia: ");
Serial.print(d);
Serial.print(" cm");

Serial.println();




}
