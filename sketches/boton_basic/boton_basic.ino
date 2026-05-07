int button = 7; 
int led = 13; 

int value;

void setup() {
  Serial.begin(9600);
  
  pinMode(button, INPUT);  
  pinMode(led, OUTPUT); 
}

void loop() {   
  //digitalWrite(outputPin, digitalRead(inputPin));
  value = digitalRead(button);
  if (value  == HIGH) {
    digitalWrite(led,HIGH);                       
  }else{
    digitalWrite(led,LOW);
  }
   
}
