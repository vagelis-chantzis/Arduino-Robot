/*  <--- Arduino Ultrasonic Distance sensor --->
 * 
 * This sketch shows how the Ultrasonic Distance sensor 
 * works using the Serial Monitor.
 * 
 * Components  used in this sketch
 * ----------
 *  - Arduino Uno
 *  - Breadboard  
 *  - HC-SR04 Ultrasonic Distance Sensor 
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
 *  
 *  
 *  Created on February 7 2017 by Evangelos Chantzis
 * 
 */

#define trigPin 7  //the trig pin from distance sensor
#define echoPin 4  //the echo pin from distance sensor

const int collisionThresh = 15; //threshold for obstacles (in cm
long duration; //time it takes to recieve PING))) signal

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("This monitor will show us what the ultrasonic distance sensor reads");
  Serial.println();
}

void loop(){
  int distance = ping();  //call the ping function to get the distance in front of the robot

  Serial.print(distance);
  Serial.print("  cm  ");
  if (distance < collisionThresh) {  //collision
    Serial.print("Obstacle ahead!");  
  }
  delay(1000);
  Serial.println();
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
