int R = 6;
int G = 5;
int B = 3;

int bt = 2;

int brillo;
int brilloR = 50;
int brilloG = 50;
int brilloB = 50;

int pulsador;
int pot = 0;
int color = 1;

bool pulsado = false;

void setup() {
// initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(B, OUTPUT);  
  pinMode(G, OUTPUT);  
  pinMode(R, OUTPUT);  
  pinMode(bt, INPUT);  
}

void loop() {
 brillo = analogRead(pot) / 4;

 pulsador = digitalRead(bt);
 
 if(pulsador == 1 && pulsado == false){
  switch (color) {
  case 1:
    color++;
    pulsado=true;
    break;
  case 2:
    color++;
    pulsado=true;
    break;
   case 3:
    color=1;
    pulsado=true;
    break;
  default:
    // statements
    break;
  }

 }

Serial.println(color);
if(pulsador==0){
    pulsado=false;
}

 if(color == 1){
   //red
   brilloR = brillo;
   analogWrite(R, brilloR);
 }
 if(color == 2){
   //green
   brilloG = brillo;
   analogWrite(G, brilloG);
 }
 if(color == 3){
   //blue
   brilloB = brillo;
   analogWrite(B, brilloB);
 }


   
}
