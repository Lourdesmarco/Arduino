
const int SENSOR_PIN = 34;

float referencia = 0;
float amplitud = 0;

unsigned long ultimoLatido = 0;
unsigned long ultimoMensaje = 0;

bool subiendo = false;
int bpm = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetPinAttenuation(SENSOR_PIN, ADC_11db);

  Serial.println("Coloca el dedo y mantenlo quieto.");
}

void loop() {
  int senal = analogRead(SENSOR_PIN);
  unsigned long ahora = millis();

  // Adaptar la referencia lentamente a la señal
  if (referencia == 0) {
    referencia = senal;
  }

  referencia += (senal - referencia) * 0.01;

  // Medir la variación respecto a la referencia
  float variacion = senal - referencia;

  // Detectar el pico de cada pulso
  if (variacion > 35) {
    subiendo = true;
  }

  if (subiendo && variacion < 10) {
    subiendo = false;

    if (ultimoLatido != 0) {
      unsigned long intervalo = ahora - ultimoLatido;

      if (intervalo >= 300 && intervalo <= 2000) {
        bpm = 60000 / intervalo;

        Serial.print("BPM: ");
        Serial.println(bpm);
      }
    }

    ultimoLatido = ahora;
  }

  // Mensaje si todavía no se detectan pulsos
  if (ahora - ultimoMensaje >= 1000) {
    ultimoMensaje = ahora;
    Serial.print("Lectura: ");
    Serial.println(senal);
  }

  delay(5);
}
