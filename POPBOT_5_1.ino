//detecta blaco y negro

#include <SoftwareSerial.h>
#define RXpin 16
#define TXpin 16
SoftwareSerial pantalla(16,16);
int Lsensor;
int Rsensor;

void setup() {
  pinMode(16,OUTPUT);
  digitalWrite(16,HIGH);            //usa puerto 16 para comunicarse con pantalla
  pantalla.begin(9600);             //velocidad de comunicacion de 9600 baudios
  delay(1000);
}

void LCD_CMD(int comando){
    pantalla.write(0xfe);           //activa el ingreso de comando de control
    pantalla.write(comando);
}

void loop() {
    Lsensor=analogRead(7);
    Rsensor=analogRead(6);
    LCD_CMD(0x01);                  //limpia pantalla
    LCD_CMD(0x80);                  //escribe desde primera columna-primera fila
    pantalla.print("L Sensor=  ");
    pantalla.print(Lsensor);
    LCD_CMD(0xC0);                  //escribe desde primera columna-segunda fila
    pantalla.print("R Sensor=  ");
    pantalla.print(Rsensor);
    delay(1000);


  }






  
