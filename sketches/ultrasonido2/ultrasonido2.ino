int trigger = 2;
int echo = 3;

int led = 5;
int brillo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led, OUTPUT);
  digitalWrite(trigger, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
long t;
long d;

digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);

t = pulseIn(echo, HIGH);
d = t * 0.034 / 2;

Serial.print("Distancia: ");
Serial.print(d);
Serial.print(" cm / ");

Serial.println();

brillo = 200;
 digitalWrite(led, brillo);


}
