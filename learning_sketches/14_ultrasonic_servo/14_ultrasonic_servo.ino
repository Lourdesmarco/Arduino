
#include <Servo.h>

const int trigPin = 6;
const int echoPin = 7;
const int servoPin = 8;

const int distanciaMaxima = 50; // Activación a 50 cm (especificar lo que quieras)
const int distanciaMinima = 10; // Giro máximo a 10 cm (especificar lo que quieras)

Servo miServo;

float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Tiempo máximo de espera: 30 ms
  long duracion = pulseIn(echoPin, HIGH, 30000);

  // Si no hay eco, devolver distancia inválida
  if (duracion == 0) {
    return -1;
  }

  return duracion * 0.0343 / 2.0;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  miServo.attach(servoPin);
  miServo.write(0);

  Serial.begin(9600);
}

void loop() {
  float distancia = medirDistancia();

  if (distancia > 0) {
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    int angulo;

    if (distancia >= distanciaMaxima) {
      angulo = 0;
    } 
    else if (distancia <= distanciaMinima) {
      angulo = 180;
    } 
    else {
      // Convierte la distancia en un ángulo
      angulo = map(
        (int)(distancia * 10),
        distanciaMaxima * 10,
        distanciaMinima * 10,
        0,
        180
      );
    }

    miServo.write(angulo);

    Serial.print("Angulo del servo: ");
    Serial.println(angulo);
  }

  delay(50);
}
