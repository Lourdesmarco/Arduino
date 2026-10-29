int sensorValue = 0;
int sensorHigh = 0;
int sensorLow = 0;

void setup() {
  /* Configuración del theremin (5 primeros seg. del programa) */
  /* ------------------------------------------------------------ */
  while(millis() < 5000){
    /* Leo el valor de la fotocélula */
    sensorValue = analogRead(A0);

    /* Cuando el valor sea el máximo registrado */
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    /* Cuando el valor sea el mínimo registrado */
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
   }
   /* Fin cofiguración (cuando pasan 5 seg.) */
  /* ------------------------------------------------------------ */
}

void loop() {
  /* Leo el valor de la fotocélula */
  sensorValue = analogRead(A0);

  /* Mapeo el valor para convertirlo a Mhz */
  int mapped = map(sensorValue, sensorLow, sensorHigh, 50, 2000);
  
  /* Con la función tone() hago que suene el altavoz */
  tone(9 , mapped, 20);

  delay(10);
}
