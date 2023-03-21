int x;

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(38400);
}


void loop() {
  if (Serial.available()){
    x = Serial.read();
  }

  if (x=='1'){
    digitalWrite(13,HIGH);
  }
  
  if (x=='0'){
    digitalWrite(13,LOW);
  }
}



