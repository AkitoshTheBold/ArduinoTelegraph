/*
 * A morse code message is a ternary string, with 'x' being the sentinel value for padding.
 * Each morse code value is encoded and decoded using a lookup table.
 */

// constants for translation.
char chars = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
char code[][] = {"01xxx","1000x","1010x","100xx","0xxxx","0010x","110xx","0000x","00xxx","0111x","101xx","0100x","11xxx","10xxx","111xx","0110x","1101x","010xx","000xx","1xxxx","001xx","0001x","011xx","1001x","1011x",
        "1100x","11111","01111","00111","00011","00001","00000","10000","11000","11100","11110"};
void encode(char in[], char out[], size_t insize) { // Output is in out[].
  for(size_t i = 0; i < insize; i++) {
    char c = in[i];
    char ind = -1;
    for(size_t j = 0; j < 36; j++) { // get the index of the character.
      if(chars[j] == c) {
        ind = j;
        break;
      }
    }
    if(ind < 0) return; /* not supposed to happen. */
    for(size_t j = 0; j < 5; j++) { // write the relevant morse code to out[].
      out[i*5+j] = code[ind][j];
    }
  }
}

bool match(char *i, char* j) {
  for(size_t k=0;k<5;k++){ if (i[k] != j[k]) return 0; }
  return 1;
}

void decode(char in[], char out[], size_t insize) {
  for(size_t i = 0; i < insize; i +=5) {
    for(size_t j = 0; j < 36; j++) {
      if(match(in+i,code[j])){
        out[i/5]=char[j];
        break;
      }
    }
  }
}

void setup() {
  // 2 & 4 receiver indication & data
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  // 12 & 13 sender indication & data
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void decode()

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
