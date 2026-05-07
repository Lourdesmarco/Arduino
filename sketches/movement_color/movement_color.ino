int R = 6;
int G = 5;
int B = 3;

int sensor = 2;


long randNumber;

void setup() {
// initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(B, OUTPUT);  
  pinMode(G, OUTPUT);  
  pinMode(R, OUTPUT);  
  pinMode(sensor, INPUT);
  
}

void loop() {


  int value= digitalRead(sensor);
  Serial.println(value);
  if (value == HIGH){
    randNumber = random(256);
  analogWrite(R, randNumber);
  randNumber = random(256);
  analogWrite(G, randNumber);
  randNumber = random(256);
  analogWrite(B, randNumber);
    }
  

  delay(1000);
   
}
