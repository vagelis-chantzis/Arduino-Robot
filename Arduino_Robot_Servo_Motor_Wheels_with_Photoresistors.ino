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
