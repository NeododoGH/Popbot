
int posVal[] = {460, 610, 760, 1050, 1340, 1500, 1660, 1940, 2220};
int gp2[9];
int j, maximo, posicion;



void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(14, OUTPUT);
  beep();
  delay(2000);
}


int max_punto() {
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

void servo_home() {
  mover_servo(460);
  mover_servo(460);
  mover_servo(460);
  mover_servo(460);
}

void mover_servo(int val) {
  int i;
  for (i = 0; i < 5; i++) {
    digitalWrite(7, HIGH);
    delayMicroseconds(val);
    digitalWrite(7, LOW);
    delay(20);
  }
}

void avanza(int speeds) {
  analogWrite(3, speeds);
  digitalWrite(5, LOW);
  analogWrite(6, speeds);
  digitalWrite(9, LOW);
}

void motor_para() {
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
}

void giro_izq(int speeds) {
  digitalWrite(3, LOW);
  analogWrite(5, speeds);
  analogWrite(6, speeds);
  digitalWrite(9, LOW);
}

void giro_der(int speeds) {
  analogWrite(3, speeds);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  analogWrite(9, speeds);
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

void loop() {
  motor_para();
  servo_home();
  for (j = 0; j < 9; j++) {
    mover_servo(posVal[j]);
    gp2[j] = analogRead(5);
  }
  posicion = max_punto();
  if (maximo < 20) {
    giro_der(150);
    delay(600);
  }
  else if (maximo > 280) {
    mover_servo(posVal[max_punto()]);
    beep();
    while (1);
  }
  else {
    switch (posicion) {
      case 0: giro_der(200);
        delay(320);
        avanza(200);
        delay(400 - maximo);
        break;
      case 1: giro_der(200);
        delay(240);
        avanza(200);
        delay(400 - maximo);
        break;
      case 2: giro_der(200);
        delay(160);
        avanza(200);
        delay(400 - maximo);
        break;
      case 3: giro_der(200);
        delay(80);
        avanza(200);
        delay(400 - maximo);
        break;
      case 4: avanza(200);
        delay(400 - maximo);
        break;
      case 5: giro_izq(200);
        delay(80);
        avanza(200);
        delay(400 - maximo);
        break;
      case 6: giro_izq(200);
        delay(160);
        avanza(200);
        delay(400 - maximo);
        break;
      case 7: giro_izq(200);
        delay(240);
        avanza(200);
        delay(400 - maximo);
        break;
      case 8: giro_izq(200);
        delay(320);
        avanza(200);
        delay(400 - maximo);
    }
  }
}






