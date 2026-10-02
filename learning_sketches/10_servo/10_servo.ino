#include <Servo.h>
Servo servoMotor1;


void setup() {
  servoMotor1.attach(9);
}

void loop() {
  servoMotor1.write(0); 
  delay(1000);

  servoMotor1.write(90); 
  delay(1000);

  servoMotor1.write(180); 
  delay(1000);
}
