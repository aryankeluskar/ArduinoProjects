#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);
void setup()  { 
  pinMode(8, OUTPUT);
  BT.begin(9600);
}
void loop() {
  if(BT.available()){
    char a=(BT.read());
    if (a==1) {
    digitalWrite(8, HIGH);
    }
    if (a==0)  {
    digitalWrite(8, LOW);
    }
  }
}
