#include <SoftwareSerial.h>
#define rxPin 16
#define txPin 16
SoftwareSerial pantalla(16, 16);
int gp2;
float distancia;

void setup() {
  pinMode(txPin, OUTPUT);
  pantalla.begin(9600);
  delay(1000);
}

void LCD_CMD(int comando) {
  pantalla.write(0xfe);           //activa el ingreso de comando de control
  pantalla.write(comando);
}


void loop() {
  gp2 = analogRead(5);
  distancia = ((2914 / (gp2 + 5)) - 1);
  LCD_CMD(0x80);
  pantalla.print("RAW Data= ");
  LCD_CMD(0x8A);
  pantalla.print(gp2, DEC);

  LCD_CMD(0xc0);
  pantalla.print("Distancia= ");
  LCD_CMD(0xCA);
  pantalla.print(distancia, DEC);
  LCD_CMD(0xCE);
  pantalla.print("cm");
  delay(200);
}


