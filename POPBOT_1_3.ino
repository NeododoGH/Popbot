//con esta rutina el robot hace un cuadrado

void setup() {
  pinMode(3, OUTPUT);   //motor A1
  pinMode(5, OUTPUT);   //motor A2
  pinMode(6, OUTPUT);   //motor B1
  pinMode(9, OUTPUT);   //motor B2
  pinMode(2, INPUT);    //switch izquierdo
  pinMode(4, INPUT);    //switch derecho
}


void avanza(int speeds) {
  analogWrite(3, speeds);   // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void giro_izquierda(int speeds) {
  digitalWrite(3, LOW);   // rueda izquierda avanza a la velocidad de 0-255
  analogWrite(5, speeds);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void giro_derecha(int speeds) {
  analogWrite(3, speeds);   // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  analogWrite(9, speeds);
}

void loop() {
  if (digitalRead(2) == 0) {    //presiono switch2, hace giros a la izquierda
    while (1) {
      avanza(125);              //avanza a la velocidad de 125
      delay(900);
      giro_izquierda(125);      //hace el giro a la velocidad de 125
      delay(400);
    }
  }
  if (digitalRead(4) == 0) {  //presiono switch4, hace giros a la derecha
    while (1) {
      avanza(125);            //avanza a la velocidad de 125
      delay(900);
      giro_derecha(125);      //hace giro a la velocidad de 125
      delay(400);
    }
  }
}
