/*  <--- Arduino Robot Distance Guidance --->
 * 
 * This sketch is showing the way the photoresistors
 * work using the Serial Monitor.
 * 
 * Components  used in this sketch
 * ----------
 *  - Arduino Uno
 *  - Breadboard
 *  - 2 x Light Dependent Resistors (Photoresistors) 
 *  - 2 x 10kΩ resistors  
 *    
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections 
 * -----------
 *  The schematic is shown in Chapter Two. 
 *  This is not a standalone circuit.
 * 
 * Other information
 * -----------------
 *  Always remember to plug in the Servo Motors batteries first and then the Arduino batteries.
 *  More about the photoresistors: https://en.wikipedia.org/wiki/Photoresistor
 *  
 *  
 *  Created on February 7 2017 by Evangelos Chantzis
 * 
 */

const int RightLightSensor = 2;  //declare the analog pins for the photoresistors
const int LeftLightSensor = 0;

int SensorLeft;
int SensorRight;
int SensorDifference;

void setup() {
  pinMode(LeftLightSensor, INPUT);
  pinMode(RightLightSensor, INPUT);
  Serial.begin(9600);
  Serial.println("This monitor will show us what the photoresistors read and where the robot will go");
  Serial.println("Left    Right   Difference    Robot Move");
  Serial.println();
}

void loop() {
  
  SensorLeft = 1023 - analogRead(LeftLightSensor);  //read the photoresistors
  Serial.print(SensorLeft);
  Serial.print("      ");
  delay(1);
  SensorRight = 1023 - analogRead(RightLightSensor);
  Serial.print(SensorRight);
  Serial.print("      ");
  delay(1);
  SensorDifference = abs(SensorLeft - SensorRight);
  Serial.print(SensorDifference);
  Serial.print("           ");

  if (SensorLeft > SensorRight && SensorDifference > 75) {  //left
    Serial.print("Left");
    delay(250);
  }
  
  if (SensorLeft < SensorRight && SensorDifference > 75) {  //right
    Serial.print("Right");
    delay(250);
  }
  
  else if (SensorDifference < 75) {  //forward
    Serial.print("Forward");
    delay(500);  
  }
  Serial.println();
}
