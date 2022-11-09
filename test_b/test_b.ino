void setup() {
  pinMode(4,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(4));
}
