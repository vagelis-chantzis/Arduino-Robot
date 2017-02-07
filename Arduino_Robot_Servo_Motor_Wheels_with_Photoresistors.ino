/*  <--- Arduino Light Guidance --->
 * 
 * Using this sketch the robot will navigate
 * itself to the brightest light source.
 * 
 * Components  used in this sketch
 * ----------
 *  - Arduino Uno
 *  - Breadboard
 *  - 2 x Light Dependent Resistors (Photoresistors) 
 *  - 2 x 10kΩ resistors  
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

const int RightLightSensor = 2;  //declare the analog pins for the photoresistors
const int LeftLightSensor = 0;

int SensorLeft;
int SensorRight;
int SensorDifference;

Servo leftMotor;  //declare motors
Servo rightMotor;

void setup() {
  rightMotor.attach(11);  //attach motors to proper pins
  leftMotor.attach(10);

  pinMode(LeftLightSensor, INPUT);
  pinMode(RightLightSensor, INPUT);
}

void loop() {

    SensorLeft = 1023 - analogRead(LeftLightSensor);  //read the photoresistors
    delay(1);
    SensorRight = 1023 - analogRead(RightLightSensor);
    delay(1);
    SensorDifference = abs(SensorLeft - SensorRight);
  
  if (SensorLeft > SensorRight && SensorDifference > 75) {
    leftMotor.write(LBackward); //turn left
    rightMotor.write(RForward);
    delay(500);
  }

  if (SensorLeft < SensorRight && SensorDifference > 75) {
    leftMotor.write(LForward); //turn right
    rightMotor.write(RBackward);
    delay(500);
  }

  else if (SensorDifference < 75) { 
    leftMotor.write(LForward); //move forward
    rightMotor.write(RForward);
    delay(500);  
   }
}
