void setup() {
  pinMode(2,OUTPUT);
}

int i = 0;

void loop() {
  if (i%3==0)
    digitalWrite(2,HIGH);
  else if (i%5==0)
    digitalWrite(2,HIGH);
  else digitalWrite(2,LOW);
}
