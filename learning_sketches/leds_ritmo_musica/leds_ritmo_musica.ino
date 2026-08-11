int led = 13;
int led2 = 12;
int rango = 30; //Es el rango de los sonidos que coge, necesario ajustar el sensor
int volumen;

void setup() {              
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2,OUTPUT);  
}

void loop() {

    volumen = analogRead(A0);
 
    Serial.println(volumen);
    delay(50); //Para que los sonidos los escriba en los LED's con un delay de 50 milisegundos (un pequeño rango para que sea visible el encendido y el apagado por el ser humano)

    digitalWrite(led,LOW); //Se inicializa el LED rojo a apagado
    digitalWrite(led2,LOW); //Se inicializa el LED verde a apagado
    if(volumen>=rango){
      digitalWrite(led, HIGH); //Se enciende el LED rojo
      digitalWrite(led2,LOW); //Se apaga el LED verde
    }
    else{
      digitalWrite(led, LOW); //Se apaga el LED rojo
      digitalWrite(led2,HIGH); //Se enciende el LED verde
    }

}
