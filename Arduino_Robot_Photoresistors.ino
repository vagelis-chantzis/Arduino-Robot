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
