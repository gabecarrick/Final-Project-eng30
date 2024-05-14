#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);
Adafruit_DCMotor *M2 = AFMS.getMotor(2);
void setup() {
  Serial.begin(9600);
  
  if (!AFMS.begin()) { 
   while (1);
  }

 M1->setSpeed(10);
 M1->run(RELEASE);
 M2->setSpeed(10);
 M2->run(RELEASE);
}
int i;

void loop() {
  M1->run(FORWARD);
   for (i=0; i<255; i++) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
  }

 for (i=255; i!=0; i--) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }

 M1->run(BACKWARD);
 for (i=0; i<255; i++) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }

 for (i=255; i!=0; i--) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }
 M2->run(FORWARD);
   for (i=0; i<255; i++) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
  }

 for (i=255; i!=0; i--) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }

 M2->run(BACKWARD);
 for (i=0; i<255; i++) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }

 for (i=255; i!=0; i--) {
   M1->setSpeed(i);
   M2->setSpeed(i);
   delay(5);
 }
}