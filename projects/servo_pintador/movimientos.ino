int parar = 90;

int giro_reloj =45;
int giro_contrarreloj = 135;

int detencion = 100;

void adelante(){
   //adelante
  servoMotor1.write(giro_reloj);
  servoMotor2.write(giro_contrarreloj);
  delay(detencion);
}


void parando(){
  //PARAR
  servoMotor1.write(parar);
  servoMotor2.write(parar);
  delay(detencion);
}

void girar(){      
   //giro
  servoMotor1.write(giro_reloj);
  servoMotor2.write(giro_reloj);
  delay(detencion);
}

void atras(){
  //atrás
  servoMotor1.write(giro_contrarreloj);
  servoMotor2.write(giro_reloj);
  delay(detencion);
}
