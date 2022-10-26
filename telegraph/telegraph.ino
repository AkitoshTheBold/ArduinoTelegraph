char buff[30];
bool inst=0;
string msg;
void setup() {
  // 2 & 4 receiver indication & data
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  // 12 & 13 sender indication & data
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  if(digitalRead(2)) {
    
  }
  if(Serial.available()) {
    msg = Serial.readString();
    char enc[50];
    encode(msg,enc);
    digitalWrite(12,HIGH);
    for(int i=0; i<strlen(enc); i++) {
      digitalWrite(13,enc[i]);
    }
  }
}
