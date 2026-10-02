#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);
Servo myServo;

int button = 7;
int state = 20;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  myServo.attach(9);
  miBT.begin(38400);
}

void loop() {

 if(miBT.available() > 0){
    state = miBT.read();
    Serial.println(state);
 }

 myServo.write(state);
 delay(10);

 buttonState = digitalRead(button);
 if (buttonState == HIGH) {
   miBT.write('1');
 }
 else {
   miBT.write('0');
 }  
}
