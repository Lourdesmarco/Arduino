#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11); //10 va al TX del modulo BlueTooth, 11 va al RX del modulo BT
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  miBT.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(miBT.available())
  Serial.write(miBT.read());

  if(Serial.available())
  miBT.write(Serial.read());
}
