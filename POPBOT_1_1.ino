void setup() {
  pinMode(3, OUTPUT);   //motor A1
  pinMode(5, OUTPUT);   //motor A2
  pinMode(6, OUTPUT);   //motor B1
  pinMode(9, OUTPUT);   //motor B2
}


void avanza() {
  digitalWrite(3, HIGH);  // el robot avanza
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
}

void retrocede() {
  digitalWrite(3, LOW);  // el robot retrocede
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
}

void loop() {
  avanza();
  delay(3000);    //avanza durante 1 segundo
  retrocede();
  delay(2000);    //retrocede durante 1 segundo

}
