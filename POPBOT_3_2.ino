//usa pantalla LCD

#include <SoftwareSerial.h>
#define RXpin 16
#define TXpin 16
SoftwareSerial pantalla(16,16);

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
    int i;
    LCD_CMD(0x01);                  //limpia pantalla
    LCD_CMD(0x80);                  //escribe desde primera columna-primera fila
    pantalla.print("POP BOT");
    LCD_CMD(0xC0);                  //escribe desde primera columna-segunda fila
    pantalla.print("Hola Mundo");
    delay(2000);

    LCD_CMD(0x01);                  //limpia pantalla
    LCD_CMD(0x85);                  
    pantalla.print("desde");

    LCD_CMD(0x07);                  //texto se desplaza a la izquierda
    for(i=0;i<9;i++){
      pantalla.print(" ");
      delay(200);
    }

    LCD_CMD(0x05);                  //texto se desplaza a la derecha
    for(i=0;i<9;i++){
      pantalla.print(" ");
      delay(200);
    }

    LCD_CMD(0x01);
    LCD_CMD(0x00);                    //muestra texto
    pantalla.print("experimento");
    LCD_CMD(0xC0);
    pantalla.print("Innovativo");
    delay(5000);

     LCD_CMD(0x01);                   //limpia pantalla
     pantalla.print("Contador");      //texto en primera fila
     while(1){
        i++;
        LCD_CMD(0xC0);
        pantalla.print(i,DEC);
        delay(100);
       }
    
}
