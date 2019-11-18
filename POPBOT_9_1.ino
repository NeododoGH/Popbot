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

void motor_para() {
  digitalWrite(3, LOW);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
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

void beep() {
  int i;
  for (i = 0; i < 600 ; i++) {
    digitalWrite(14, HIGH);
    delayMicroseconds(150);
    digitalWrite(14, LOW);
    delayMicroseconds(150);
  }
}

void sound(int freq, int duracion) {
  unsigned long us;
  int duracion1, i;
  us = (1000000 / (freq * 2));
  duracion1 = (duracion / (us * 2));
  for (i = 0; i < duracion1; i++) {
    digitalWrite(14, HIGH);
    delayMicroseconds(us);
    digitalWrite(14, LOW);
    delayMicroseconds(us);
  }
}

void loop() {
  Izq = analogRead(7);
  Der = analogRead(6);
  if (Izq > Ref && Der > Ref) {
    avanza(150);
  }
  else if (Izq < Ref && Der < Ref) {
    cont++;
    motor_para();
    for (j = 0; j < cont; j++) {
      beep();
      delay(100);
    }
    avanza(150);
    delay(100);
  }
  else if (Izq < Ref) {
    giro_izq(255);
  }
}
