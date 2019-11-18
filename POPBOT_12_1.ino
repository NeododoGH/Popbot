int Ref = 400;
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

void motor_para() {
  digitalWrite(3, LOW);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
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

void derecha90() {
  avanza(150);
  delay(50);
  giro_der(200);
  delay(100);
  while (analogRead(6) < Ref);
  delay(50);
}

void izquierda90() {
  avanza(150);
  delay(50);
  giro_izq(200);
  delay(100);
  while (analogRead(7) < Ref);
  delay(50);
}

void izquierda180() {
  giro_izq(200);
  delay(300);
  while (analogRead(7) < Ref);
  delay(50);
}



void cruz() {
  cont++;
  if (cont == 12) {
    motor_para();
  }
  else if (cont == 2 || cont == 10) {
    derecha90();
  }
  else if (cont == 3 || cont == 6 || cont == 9) {
    izquierda90();
  }
}

void loop() {
  while (cont < 12) {
    Izq = analogRead(7);
    Der = analogRead(6);
    if ((Izq < Ref) && (Der < Ref)) {
      cruz();
    }
    else if ((Izq > Ref) && (Der > Ref)) {
      avanza(150);
    }
    else if (Izq < Ref) {
      giro_der(150);
    }
    else if (Der < Ref) {
      giro_izq(150);
    }
  }
  while (1);
}
