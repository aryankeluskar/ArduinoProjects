#include <IRremote.h>
#include "LowPower.h"
IRsend irsend;
const int button1 = 4; //Vol+
const int button2 = 5; //Switch
const int button3 = 6; //Vol-
int timer;

void wakeUp(){
 timer = 0;
}

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  timer = 0;
}

void loop() {
  attachInterrupt(0,wakeUp, HIGH);
  while (timer < 3000){
  if (digitalRead(button1) == HIGH){
  timer = 0;  
  delay(50);
  irsend.sendNEC(0x34895725, 32);} //Vol+

  if (digitalRead(button2) == HIGH){
  timer = 0;
  delay(50);
  irsend.sendNEC(0x56874159, 32);} //Switch

  if (digitalRead(button3) == HIGH){
  timer = 0;
  delay(50);
  irsend.sendNEC(0x15467823, 32);} //Vol-
  
   delay(1);
   timer = timer + 1;
}
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);}
