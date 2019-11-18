int gp2;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
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

void loop() {
  int i;
  for (i=0;i<5;i++){
    gp2=(gp2+analogRead(5));
  }
  gp2=gp2/5;
  if (gp2>290){
    retrocede(200);
    delay(300);
    giro_izq(200);
    delay(350);
  }
  else{
    avanza(200);
  }
}
