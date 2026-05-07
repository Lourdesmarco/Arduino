int led = 13;
int sensor = 2;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  //delay(5000);
}

void loop() {
  value = digitalRead(sensor);
  if (value == HIGH){
    digitalWrite(led, HIGH);
    
    }else{
    digitalWrite(led, LOW);
      }
  
  delay(50);
   Serial.println(value);
}
