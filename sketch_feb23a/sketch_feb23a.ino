////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

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
  { 255,5,0,0,0,83,0,8,13,0,
  4,32,67,3,10,57,2,26,1,0,
  35,3,28,28,2,31,85,80,32,98,
  121,32,52,53,0,1,0,35,32,29,
  29,2,31,68,79,87,78,32,98,121,
  32,52,53,0,1,0,6,3,28,28,
  2,31,85,80,32,98,121,32,49,53,
  0,1,0,5,32,29,29,2,31,68,
  79,87,78,32,98,121,32,49,53,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t servo_slider; // =-100..100 slider position 
  uint8_t up45; // =1 if button pressed, else =0 
  uint8_t down45; // =1 if button pressed, else =0 
  uint8_t up15; // =1 if button pressed, else =0 
  uint8_t down15; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

Servo myservo

void setup()  
{ 
  RemoteXY_Init ();  
  RemoteXY.servo_slider=0;
  myservo.attach(11)   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
  int angle = servo_slider*0.45   
  myservo.write(angle) 
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 

  
}
