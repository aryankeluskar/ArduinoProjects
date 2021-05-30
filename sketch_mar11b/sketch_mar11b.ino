#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xAF5E817:
          Serial.println("Power");
          digitalWrite(5, HIGH);
          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          break;
          case 0xAF5C53A:
          Serial.println("Power");
          digitalWrite(5, LOW);
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          break;
          case 0xAF532CD:
          Serial.println("Red");
          digitalWrite(4, HIGH);
          break;
          case 0xAF5A25D:
          Serial.println("Green");
          digitalWrite(3, HIGH);
          break;
          case 0xAF5629D:
          Serial.println("Yellow");
          digitalWrite(2, HIGH);
          break;
          case 0xAF5E21D:
          Serial.println("Blue");
          digitalWrite(5, HIGH);
          break;  
            
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
