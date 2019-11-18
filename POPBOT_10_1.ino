int Ref = 700;
int Izq, Der;
int cont = 0, j;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(14, OUTPUT);    //se conecta el buzzer
}

void avanza(int speeds) {
  analogWrite(3, speeds);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  analogWrite(6, speeds);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void derecha90() {
  avanza(150);
  delay(50);
  giro_der(200);
  delay(100);
  while (analogRead(6) > Ref);
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
  if (Izq < Ref && Der < Ref) {
    derecha90();
  }
  else if ((Izq > Ref) && (Der > Ref)) {
    avanza(150);
  }
  else if (Der < Ref) {
    giro_der(150);
  }
}
