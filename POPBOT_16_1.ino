int i;

void setup() {
  pinMode(8, OUTPUT);       //servo motor
  pinMode(7, OUTPUT);       //servo motor
}

void loop() {
  for (i = 0; i < 100; i++) {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delayMicroseconds(500);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(20);
  }
  for (i = 0; i < 100; i++) {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delayMicroseconds(2300);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(20);

  }

}


