// Chapter 5 - Motor Control
// Controlling Speed
// By Cornel Amariei for Packt Publishing
// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h> 
#include <Servo.h>
#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL_RX 2 
#define REMOTEXY_SERIAL_TX 3 
#define REMOTEXY_SERIAL_SPEED 9600 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,5,0,0,0,60,0,8,13,0,
  1,1,1,1,35,30,2,31,48,0,
  1,1,63,1,35,29,2,31,57,48,
  0,1,1,1,33,35,30,2,31,49,
  56,48,0,1,1,63,31,36,31,2,
  31,50,55,48,0,1,1,37,1,25,
  61,2,31,51,54,48,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t Zero; // =1 if button pressed, else =0 
  uint8_t Ninety; // =1 if button pressed, else =0 
  uint8_t One_Eighty; // =1 if button pressed, else =0 
  uint8_t Two_Seventy; // =1 if button pressed, else =0 
  uint8_t Three_Sixty; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop)


// Include the Servo library
#include <Servo.h> 

// Declare the Servo pin
int servoPin = 3;
// Create a servo object
Servo Servo1;

void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  RemoteXY_Init ();  
}

void loop(){
  // Make servo go to 0 degrees
  RemoteXY_Handler (); 
  if (RemoteXY.Zero == 1)
 {
  Servo1.write(0);
 }
  // Make servo go to 90 degrees
  if (RemoteXY.One_Eighty == 1)
  {
  Servo1.write(180);
  }
  // Make servo go to 180 degrees
  if (RemoteXY.Two_Seventy == 1)
  {
  Servo1.write(270);
  }
  if (RemoteXY.Ninety == 1)
  {
  Servo1.write(90);
  }
  if (RemoteXY.Three_Sixty == 1)
  {
    Servo1.write(360);
  }

}



