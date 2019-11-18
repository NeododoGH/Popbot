//con esta rutina el robot hace un circulo donde una rueda gira mas rápido que la otra

void setup() {
  pinMode(3, OUTPUT);   //motor A1
  pinMode(5, OUTPUT);   //motor A2
  pinMode(6, OUTPUT);   //motor B1
  pinMode(9, OUTPUT);   //motor B2
  pinMode(2, INPUT);    //switch izquierdo
  pinMode(4, INPUT);    //switch derecho
}


void avanza(int Lspeed, int Rspeed) {
  analogWrite(3, Lspeed);  // rueda izquierda avanza a la velocidad de 0-255
  digitalWrite(5, LOW);
  analogWrite(6, Rspeed);  //rueda derecha avanza a la velocidad de 0-255
  digitalWrite(9, LOW);
}

void parar() {
  digitalWrite(3, LOW);  // el robot retrocede
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  avanza(80, 255);
  if (digitalRead(4) == 0) {
    parar();
    while (1);
  }
}
