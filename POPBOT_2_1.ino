//con esta rutina el robot rebota al chocar con pared

void setup() {
  pinMode(3, OUTPUT);   //motor A1
  pinMode(5, OUTPUT);   //motor A2
  pinMode(6, OUTPUT);   //motor B1
  pinMode(9, OUTPUT);   //motor B2
  pinMode(15, INPUT);   //sensor de choque
  pinMode(17, INPUT);   //sensor de choque
}


void avanza(int speeds) {
  analogWrite(3, speeds);   // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void retrocede(int speeds) {
  digitalWrite(3, LOW);   // rueda izquierda avanza a la velocidad de 0-255
  analogWrite(5, speeds);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, speeds);
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
  avanza(150);
  if (digitalRead(15) == 0) {    //presiono switch2, hace giros a la izquierda
    retrocede(150);
    delay(500);
    giro_derecha(200);
    delay(400);
  }
  if (digitalRead(17) == 0) {  //presiono switch4, hace giros a la derecha
    retrocede(150);
    delay(400);
    giro_izquierda(200);
    delay(400);
  }
}
