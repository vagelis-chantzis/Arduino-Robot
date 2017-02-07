/*  <--- Arduino Robot Servo motors Wheels --->
 * 
 * This sketch Shows the basic movements of the servo motors.
 * 
 * Components  used in this sketch
 * ----------
 *  - Arduino Uno
 *  - Breadboard  
 *  - 2 x Continuous Rotation Servo (SpringRC SM-S4303R)
 *  - 2 x 330μF capacitors 
 *  - Magician Robot Chassis 
 *  - 2 x plastic wheels 6cm diameter, 0.7cm width 
 *  - 1 x 9V battery and 4 x 1.5V batteries 
 *    
 *  Libraries
 *  ---------
 *  - Servo.h
 *
 * Connections 
 * -----------
 *  The schematic is shown in Chapter Two. 
 *  This is not a standalone circuit.
 * 
 * Other information
 * -----------------
 *  Always remember to plug in the Servo Motors batteries first and then the Arduino batteries.
 *  
 *  
 *  Created on February 7 2017 by Evangelos Chantzis
 * 
 */

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
