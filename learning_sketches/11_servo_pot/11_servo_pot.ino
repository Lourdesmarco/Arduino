#include <Servo.h>

Servo miServo;

const int pinServo = 9;
const int pinPot = A0;

void setup() {
  miServo.attach(pinServo);
}

void loop() {
  int valorPot = analogRead(pinPot);

  // Convertir 0-1023 del potenciómetro a 0-180 grados
  int angulo = map(valorPot, 0, 1023, 0, 180);

  miServo.write(angulo);

  delay(15);
}