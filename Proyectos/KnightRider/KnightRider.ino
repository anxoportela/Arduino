
int count = 0;
int wait = 50;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  for (count = 2; count <= 10; count++) {
    digitalWrite(count, HIGH);
    delay(wait);
    digitalWrite(count, LOW);
    delay(wait);
  }
  for (count = 9; count >= 3; count--) {
    digitalWrite(count, HIGH);
    delay(50);
    digitalWrite(count, LOW);
    delay(50);
  }
}
