
#include <Servo.h>
Servo servoMotor1;
Servo servoMotor2;


int val;

// Joystick
//int bt = 2;
//int joyX = A2;
//int joyY = A3;
//
//int xpos = 0;
//int ypos = 0;

//servos

int valuemap1;
int valuemap2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoMotor1.attach(10);
  servoMotor2.attach(9);
}

void loop() {

//  xpos = analogRead(joyX);
//  delay(50);
//  ypos = analogRead(joyY);
//  delay(50);
//  
//  Serial.println(xpos);
//  Serial.println(ypos);
//
//valuemap1 = map(xpos, 0, 1020, 0, 180);
//valuemap2= map(ypos, 0, 1020, 0, 180);
  val = 0;
  for(val = 0; val < 360; val + 10){
      servoMotor1.write(val);
      servoMotor2.write(val);
      delay(1000);
  }

  
}
