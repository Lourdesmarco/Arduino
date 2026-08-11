
//#include <IRremote.h>

#include <Servo.h>
Servo servoMotor1;
Servo servoMotor2;


int val;


//const int RECV_PIN = 6;
//
// 
//IRrecv irrecv(RECV_PIN);
//decode_results results;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoMotor1.attach(10);
  servoMotor2.attach(9);

  //irrecv.enableIRIn();
}

void loop() {

  patron1();
//   if (irrecv.decode(&results))
//   {
//      Serial.println(results.value, HEX);
//      irrecv.resume();
//   }
  
}
