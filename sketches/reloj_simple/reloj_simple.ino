#include <virtuabotixRTC.h> //Libreria


// CLK -> 6, DAT -> 7, RST -> 8
// SCLK -> 6, I/O -> 7, CE -> 8 

virtuabotixRTC myRTC(6, 7, 8); // Si cambiamos los PIN de conexión, debemos cambiar aquí tambien

void setup() {
  Serial.begin(9600);

  // Para ajustar la fecha y hora, debemos utilizar el siguiente formato:
  // segundos, minutos, horas, dia de la semana, numero de día, mes y año
  //myRTC.setDS1302Time(00, 33, 13, 3, 12, 2, 2020); // SS, MM, HH, DW, DD, MM, YYYY
  /* después de ajustar la hora la linea de arriba se debe comentar o eliminar
   *  para que la fecha y hora quede grabada
  */
  // La configuración de fecha y hora ha sido ajustada
}

void loop() {
  // Esta función actualiza las bariables para obtener resultados actuales
  myRTC.updateTime();

  // Se imprime el resultado en el Monitor Serial
  Serial.print("Fecha y hora actual: ");
  Serial.print(myRTC.dayofmonth); // Se puede cambiar entre día y mes si se utiliza el sistema Americano
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);

  // Un pequeño delay para no repetir y leer más facil
  delay(1000);
}
