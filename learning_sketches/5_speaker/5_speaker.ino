/***********************/
/* recorrido de octava */
/***********************/

int speakerPin=13;
int frequency=220;    // frecuencia correspondiente a la nota La
int counter;          // variable para el contador
float m=1.059;         // constante para multiplicar frecuencias

void setup()
{
}

void loop()
{
    for(counter=0,frequency=220;counter<12;counter++)
    {
        frequency=frequency*m;     // actualiza la frecuencia
        tone(speakerPin,frequency); // emite el tono
        delay(1500);                 // lo mantiene 1.5 segundos
        noTone(speakerPin);          // para el tono
        delay(500);                  // espera medio segundo
    }
}
