int inputPin = 8; //boton1 
int inputPin2 = 11;//boton2 

int outputPin = 9; //led1
int outputPin2 = 12; //led2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(inputPin, INPUT); //boton1 
  pinMode(inputPin2, INPUT); //boton2
   
  pinMode(outputPin, OUTPUT); //led1
  pinMode(outputPin2, OUTPUT); //led2
}

void loop() {
  // put your main code here, to run repeatedly:
   
  digitalWrite(outputPin, digitalRead(inputPin));
  digitalWrite(outputPin2, digitalRead(inputPin2));    
  
}
