
#include <IRremote.h>
#include "LowPower.h"

IRsend irsend;

const int b1  = 4;  //bluetooth
const int b2  = 5;  //mute
const int b3  = 6;  //vol up
const int b4  = 7;  //vol down
const int b5  = 8;  //bass up
const int b6  = 9;  //bass down
const int b7  = 10; //treble up
const int b8  = 11; //treble down
const int b9  = 12;  //Changes the mode to TV


int timer;
int modeCounter = 0;



void wakeUp() {
  timer = 0;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);
  pinMode(b6, INPUT);
  pinMode(b7, INPUT);
  pinMode(b8, INPUT);
  pinMode(b9, INPUT);
}

void loop() {
  attachInterrupt(0, wakeUp, HIGH);
  while (timer < 10000) {
    if (digitalRead(b1) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD22DD, 32);
    }

    if (digitalRead(b2) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD50AF, 32);
    }

    if (digitalRead(b3) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFDCA35, 32);
    }

    if (digitalRead(b4) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD7887, 32);
    }

    if (digitalRead(b5) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD4AB5, 32);
    }

    if (digitalRead(b6) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD58A7 , 32);
    }

    if (digitalRead(b7) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFDA25D, 32);
    }

    if (digitalRead(b8) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xFD629D, 32);
    }

    if (digitalRead(b9) == HIGH) {
      //can add another button
    }
    delay(1);
    timer = timer + 1;

  }
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}


