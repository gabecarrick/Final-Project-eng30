/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.10 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.11 or later version;
     - for iOS 1.10.3 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);

Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL

#include <SoftwareSerial.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 37 bytes
  { 255,2,0,0,0,30,0,17,0,0,0,31,1,106,200,1,1,2,0,1,
  40,39,24,24,0,2,31,0,1,40,139,24,24,0,5,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Forward_direction; // =1 if button pressed, else =0
  uint8_t Backward_direction; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_FORWARD_DIRECTION 8
#define PIN_BACKWARD_DIRECTION 9


void setup() 
{
  RemoteXY_Init (); 
  AFMS.begin();
  pinMode (PIN_FORWARD_DIRECTION, OUTPUT);
  pinMode (PIN_BACKWARD_DIRECTION, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_FORWARD_DIRECTION, (RemoteXY.Forward_direction==0)?LOW:HIGH);
  digitalWrite(PIN_BACKWARD_DIRECTION, (RemoteXY.Backward_direction==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
    if (digitalRead(8) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(FORWARD);
      myMotor2->setSpeed(255);
      myMotor2->run(BACKWARD);

    } else if (digitalRead(9) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(FORWARD);
      myMotor2->setSpeed(255);
      myMotor2->run(BACKWARD);
    } else {
      myMotor1->setSpeed(255);
      myMotor1->run(RELEASE);
      myMotor2->setSpeed(255);
      myMotor2->run(RELEASE);

    }


}