void setup() {

  pinMode(10, OUTPUT);   //set pin as output , blue led
  pinMode(11, OUTPUT);   //set pin as output , red led
  pinMode(12, OUTPUT);   //set pin as output , yellow led

  Serial.begin(9600);    //start serial communication @9600 bps
  }

void loop(){
  
  if(Serial.available()){  //id data is available to read

    char val = Serial.read();

    if(val == 'r'){       //if r received
      digitalWrite(12, HIGH); //turn on red led
      }
    if(val == 'g'){       //if b received
      digitalWrite(10, HIGH); //turn on blue led
      }
    if(val == 'y'){       //if y received
      digitalWrite(11, HIGH); //turn on yellow led
      }
    if(val == 'f'){       //if f received
      digitalWrite(11, LOW); //turn off all led
      digitalWrite(12, LOW);
      digitalWrite(10, LOW);
      }      
    }
  }

