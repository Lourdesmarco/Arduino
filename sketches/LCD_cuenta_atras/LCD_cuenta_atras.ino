

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("Comienza la ");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print("cuenta atras");
  // Esperar un segundo
  delay(1000);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  contar(10); //cantidad de minutos de la cuenta atrás
}

void contar(byte minutos) { // Esta función bloquerará el programa hasta que el while muera
  const unsigned long regresiva = minutos * 60000; // Calculo de la duración de la cuenta regresiva, en milisegundos.
  unsigned int segundosRestantes = minutos * 60; // Calculo de la cuenta regresiva para mostrar en la LCD, en segundos.

  unsigned long tAnterior = 0;
  const unsigned long inicio = millis(); // para la cuenta usaremos el famoso millis. Guarda el momento en que se inició la cuenta.

  while (millis() - inicio < regresiva) {
    // El ciclo se mantiene vivo hasta que la diferencia del tiempo actual e inicial supere la duración requerida.

    unsigned long tActual = millis();
    if (tActual - tAnterior >= 1000) { // Actualizar el temporizador en la LCD cada segundo.
      tAnterior = tActual;
      imprimirTiempo(segundosRestantes);
      segundosRestantes--;
    }
  }
}

void imprimirTiempo(unsigned int s) {
  byte minuto = s / 60;
  byte segundo = s % 60;

  if (minuto < 10) {
    lcd.print('0');
    lcd.print(minuto);
  } else {
    lcd.print(minuto);
  }

  lcd.print(':');

  if (segundo < 10) {
    lcd.print('0');
    lcd.print(segundo);
  } else {
    lcd.print(segundo);
  }
  lcd.setCursor(0, 1);
}
