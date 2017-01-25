#include <Servo.h> //include Servo library

#define trigPin 7  //the trig pin from distance sensor
#define echoPin 4  //the echo pin from distance sensor

const int collisionThresh = 15; //threshold for obstacles (in cm)
long duration; //time it takes to recieve PING))) signal
int leftDistance, rightDistance; //distances on either side
Servo panMotor;  //micro servo with the distance sensor on it

void setup()
{
  panMotor.attach(6); 
  panMotor.write(90); //center the pan servo

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("This monitor will show us where the robot will go");
}

void loop(){
  int distance = ping();  //call the ping function to get the distance in front of the robot

  if (distance > collisionThresh) //if path is clear be guided from the light
  {
    Serial.println("Forward, path clear!");
    delay(250);
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
    Serial.println("Left turn!");
    delay(500); 
  }
  else if (rightDistance > leftDistance) //if right is less obstructed
  {
    Serial.println("Right turn!");
    delay(500);
  }
   else //if they are equally obstructed
  {
    Serial.println("Turn back!");
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
