#include <Servo.h> //include Servo library

const int RForward = 120;  //the speed of the servo, maximum speed is 180
const int RBackward = 60;   
const int LForward = 60; 
const int LBackward = 120; 
const int RNeutral = 90;  //centered position
const int LNeutral = 90;

Servo leftMotor;  //declare motors
Servo rightMotor;

void setup() {
  rightMotor.attach(11);  //attach motors to proper pins
  leftMotor.attach(10);
}

void loop() {

 leftMotor.write(LForward); //forward
 rightMotor.write(RForward);
 delay(1500);
  
 leftMotor.write(LBackward); //left turn
 rightMotor.write(RForward); 
 delay(1250);
  
 leftMotor.write(LForward); //right turn
 rightMotor.write(RBackward);
 delay(1250);
  
 leftMotor.write(LNeutral); //stop
 rightMotor.write(RNeutral);
 delay(1500);
}
