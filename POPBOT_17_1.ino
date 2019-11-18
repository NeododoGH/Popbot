#include <SoftwareSerial.h>
#define rxPin 16
#define txPin 16
SoftwareSerial pantalla(16, 16);
int posVal[] = {460, 610, 760, 1050, 1340, 1500, 1660, 1940, 2220};
int gp2[9];
int j, maximo, max_punto;

void setup() {
  pinMode(7, OUTPUT);       //motor servo
  pinMode(14, OUTPUT);      //parlante interno
  pinMode(txPin, OUTPUT);
  pantalla.begin(9600);
  delay(1000);
  LCD_Clear();
}

//calcula la posicion del objetivo
int toma_punto() {
  int i, old = 0, max1;
  for (i = 0; i < 9; i++) {
    if (gp2[i] > old) {
      old = gp2[i];
      max1 = i;
    }
  }
  maximo = old;
  return (max1);
}


void mover_servo(int val) {
  int i;
  for (i = 0; i < 20; i++) {
    digitalWrite(7, HIGH);
    delayMicroseconds(val);
    digitalWrite(7, LOW);
    delay(20);
  }
}

void beep() {
  int i;
  for (i = 0; i < 600; i++) {
    digitalWrite(14, HIGH);
    delayMicroseconds(150);
    digitalWrite(14, LOW);
    delayMicroseconds(150);
  }
}

void LCD_dato(int posicion, int x) {
  pantalla.write(0xfe);
  pantalla.write(posicion);
  pantalla.print(x, DEC);
}

void LCD_texto(int posicion, char*x) {
  pantalla.write(0xfe);
  pantalla.write(posicion);
  pantalla.print(x);
}

void LCD_Clear() {
  pantalla.write(0xfe);
  pantalla.write(0x01);
}

void loop() {
  for (j = 0; j < 9; j++) {
    mover_servo(posVal[j]);
    gp2[j] = analogRead(5);     //lee datos del sensor IR
    LCD_Clear();
    LCD_texto(0x80, "Posicion");
    LCD_dato(0x89, j);
    LCD_texto(0x8a, ":= ");
    LCD_dato(0x8d, gp2[j]);
    delay(1000);
  }
  max_punto = toma_punto();
  mover_servo(posVal[max_punto]);
  LCD_Clear();
  LCD_texto(0x80, "Seleccion :");
  LCD_dato(0x8a, max_punto);
  LCD_texto(0xc8, maximo);
  beep();
  delay(5000);
  LCD_Clear();
}


