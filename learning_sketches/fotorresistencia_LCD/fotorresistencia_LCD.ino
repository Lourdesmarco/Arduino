

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int foto = A0;
int value;
void setup()
{
   pinMode(foto, INPUT);
  
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Foto-");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print("rresistencia");
  // Esperar un segundo
  delay(1000);
}

void loop()
{
  value = analogRead(foto);
  lcd.clear ();
  lcd.home ();
  lcd.print("Luz recibida");
  lcd.setCursor ( 0, 1 );
  lcd.print(value);
  delay(100);
}
