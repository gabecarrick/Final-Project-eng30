#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();//established motorshield
Adafruit_DCMotor *M1 = AFMS.getMotor(1);//Classify motor connected to motorshield port 1
Adafruit_DCMotor *M2 = AFMS.getMotor(2);//Classify motor connected to motorshield port 
void setup() {
  Serial.begin(9600); // establishing serial library
  
  if (!AFMS.begin()) { 
   while (1);
  }

//Turning on motor M1
 M1->setSpeed(255);
 M1->run(RELEASE);

//Turning on motor M2
 M2->setSpeed(255);
 M2->run(RELEASE);
}

int i;//Establishing reference integer

void loop() {
  M1->run(FORWARD);
  M2->run(FORWARD);
  for (i=0; i<255; i++) { //i is increased by 1 every 25ms, m1 runs at 200/255 for 255*25 ms 
   M1->setSpeed(200);
   M2->setSpeed(200);
   delay(25);
  }
 
 for (i=255; i!=0; i--) { //i is decreased by 1 every 25ms, motor runs at 200*255 for 255*25 ms 
   M1->setSpeed(200);
   M2->setSpeed(200);
   delay(25);
 }

 delay(1200); //added a delay for motor wear and tear

 M1->run(BACKWARD);
 M2->run(BACKWARD);
 for (i=0; i<255; i++) {  //i is increased by 1 every 25ms, motor runs at 200/255 for 255*25 ms 
   M1->setSpeed(200);
   M2->setSpeed(200);
   delay(25);
 }

 delay(1200);//added a delay for motor wear and tear

 for (i=255; i!=0; i--) {  //i is decreased by 1 every 25ms, motor runs at 200/255 for 255*25 ms 
   M1->setSpeed(200);
   M2->setSpeed(200);
   delay(25);
 }
 delay(1200);
}
