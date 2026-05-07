int trigger = 2;
int echo = 3;

int led = 5;
int brillo = 0;

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

brillo = map(d, 2, 400, 0, 255);
analogWrite(led, brillo);

Serial.println(brillo);

Serial.print("Distancia: ");
Serial.print(d);
Serial.print(" cm");

Serial.println();




}
