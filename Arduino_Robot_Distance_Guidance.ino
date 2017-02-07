/*  <--- Arduino Robot Distance Guidance --->
 * 
 * This sketch is about making the robot navigate itself 
 * without hitting any obstacles.
 * 
 * Components  used in this sketch
 * ----------
 *  - Arduino Uno
 *  - Breadboard
 *  - Magician Robot Chassis
 *  - 2 x Continuous Rotation Servo (SpringRC SM-S4303R)
 *  - 1 x Micro generic Servo 
 *  - HC-SR04 Ultrasonic Distance Sensor
 *  - 2 x 330μF capacitors 
 *  - 1 x 100μF capacitor 
 *  - 2 x plastic wheels 6cm diameter, 0.7cm width 
 *  - 1 x 9V battery and 4 x 1.5V batteries 
 *    
 *  Libraries
 *  ---------
 *  - Servo
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

#define trigPin 7  //the trig pin from distance sensor
#define echoPin 4  //the echo pin from distance sensor

const int RForward = 120;  //the speed of the servo, maximum speed is 180
const int RBackward = 60;   
const int LForward = 60; 
const int LBackward = 120; 
const int RNeutral = 90;  //centered position
const int LNeutral = 90;
const int collisionThresh = 15; //threshold for obstacles (in cm)

int leftDistance, rightDistance; //distances on either side
Servo panMotor;  //micro servo with the distance sensor on it
Servo leftMotor;  //declare motors
Servo rightMotor; 
long duration; //time it takes to recieve PING))) signal

void setup()
{
  rightMotor.attach(11);  //attach motors to proper pins
  leftMotor.attach(10);
  panMotor.attach(6); 
  panMotor.write(90); //center the pan servo
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  
  int distance = ping();  //call the ping function to get the distance in front of the robot

   if (distance > collisionThresh) //if path is clear go forward
  {
    leftMotor.write(LForward); 
    rightMotor.write(RForward);
    delay(500);
  }
  else //if path is blocked
  { 
    panMotor.write(0); 
    delay(500);
    rightDistance = ping(); //scan to the right
    delay(500);
    panMotor.write(180);
    delay(700);
    leftDistance = ping(); //scan to the left
    delay(500);
    panMotor.write(90); //return to center
    delay(100);
    compareDistance();
  }
}

void compareDistance()
{
  if (leftDistance > rightDistance) //if left is less obstructed 
  {
    leftMotor.write(LBackward); 
    rightMotor.write(RForward); //turn left
    delay(500); 
  }
  else if (rightDistance > leftDistance) //if right is less obstructed
  {
    leftMotor.write(LForward);
    rightMotor.write(RBackward); //turn right
    delay(500);
  }
   else //if they are equally obstructed
  {
    leftMotor.write(LBackward); 
    rightMotor.write(RForward); //turn 180 degrees
    delay(1000);
  }
}

long ping()
{
  // Send out PING))) signal pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  //Get duration it takes to receive echo
  duration = pulseIn(echoPin, HIGH);
  
  //Convert duration into distance
  return duration / 29 / 2;
}
