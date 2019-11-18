int Ref = 300;
int Izq, Der;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void avanza(int speeds) {
  analogWrite(3, speeds);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void retrocede(int speeds) {
  digitalWrite(3, LOW);  // rueda izquierda avanza a la velocidad de 0-255
  analogWrite(5, speeds);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  analogWrite(9, speeds);
}


void giro_izq(int speeds) {
  digitalWrite(3, LOW);  // rueda izquierda avanza a la velocidad de 0-255
  analogWrite(5, speeds);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void giro_der(int speeds) {
  analogWrite(3, speeds);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  analogWrite(9, speeds);
}


void loop() {
  Izq = analogRead(7);
  Der = analogRead(6);
  if (Izq > Ref && Der > Ref) {
    avanza(150);
  }
  else if (Izq < Ref && Der < Ref) {
    retrocede(150);
    delay(200);
    giro_der(150);
    delay(500);
  }
  else if (Izq < Ref) {
    retrocede(150);
    delay(300);
    giro_der(150);
    delay(400);
  }
  else if (Der < Ref) {
    retrocede(150);
    delay(300);
    giro_izq(150);
    delay(300);
  }

}
