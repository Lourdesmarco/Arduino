#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_D1  37
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_G1  49
#define NOTE_A1  55
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_D2  73
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_G2  98
#define NOTE_A2  110
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_G6  1568
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G7  2937
#define NOTE_A7  3520
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_D8  4699

const int pinSpeaker = 8;

// MODIFICA ESTE VALOR: Un número mayor hace la canción MÁS LENTA
// Un número menor la hace MÁS RÁPIDA (Prueba entre 120 y 160)
const int tempo = 120; 

int melodia[] = {
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, 
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_G4, NOTE_F4, NOTE_C5, NOTE_A4,
  NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_A4, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4
};

// Duraciones (Valores negativos representan notas con puntillo: ej. -4 es negra con puntillo)
int duraciones[] = {
  4, 4, 4, 8, 16, 4, 8, 16, 2,
  4, 4, 4, 8, 16, 4, 8, 16, 2,
  4, 8, 16, 4, 8, 16, 16, 16, 16,
  8, 16, 4, 8, 16, 4, 8, 16, 2
};

// Calcula automáticamente el total de notas en el array
int totalNotas = sizeof(melodia) / sizeof(melodia[0]);

void setup() {
  // El setup queda vacío ya que el código se ejecutará de forma continua
}

void loop() {
  for (int estaNota = 0; estaNota < totalNotas; estaNota++) {
    
    // Calcula la base rítmica usando el tempo configurado
    int baseDuracion = (60000 * 4) / tempo;
    int duracionNota = 0;

    // Maneja la duración si la nota es normal o con puntillo
    if (duraciones[estaNota] > 0) {
      duracionNota = baseDuracion / duraciones[estaNota];
    } else if (duraciones[estaNota] < 0) {
      duracionNota = baseDuracion / abs(duraciones[estaNota]);
      duracionNota *= 1.5; // Incrementa el tiempo en un 50% para el puntillo
    }

    // Reproduce la nota musical en el pin asignado
    tone(pinSpeaker, melodia[estaNota], duracionNota * 0.9);

    // Pausa técnica para separar acústicamente una nota de otra
    int pausaEntreNotas = duracionNota;
    delay(pausaEntreNotas);
    
    noTone(pinSpeaker);
  }

  // Pausa de 5 segundos antes de volver a empezar toda la canción
  delay(5000); 
}
