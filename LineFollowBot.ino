// Sensor LOW/HIGH constant
const unsigned int hilo = 500; // For calibrating according to light levels. Use sketch 'analog IR'.

// Motor A
const unsigned int motorPin1   = 8;
const unsigned int motorPin2   = 9;
const unsigned int speedA      = 255; // For setting speed of motor A

// Motor B
const unsigned int motorPin3   = 10;
const unsigned int motorPin4   = 11;
const unsigned int speedB      = 255; // For setting speed of motor B

// Sensors
const unsigned int farLeft     = A0;
const unsigned int midLeft     = A1;
const unsigned int nearLeft    = A2;
//const unsigned int centerLeft  = A3;   not used
//const unsigned int centerRight = A4;   not used
const unsigned int nearRight   = A5;
const unsigned int midRight    = A6;
const unsigned int farRight    = A7;

// Movement
void moveForward()
{
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, speedA);
   analogWrite(motorPin3, speedB);
   analogWrite(motorPin4, 0);
}

//Right
void slightRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA-55);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void slightMoreRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA-75);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void moreRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA-100);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void turnRight()
{
  analogWrite(motorPin1, speedA);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}

//Left
void slightLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-55);
  analogWrite(motorPin4, 0);
}
void slightMoreLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-75);
  analogWrite(motorPin4, 0);
}
void moreLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-100);
  analogWrite(motorPin4, 0);
}
void turnLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, speedB);
}


void turnAround()
{
  analogWrite(motorPin1, speedA);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void moveBackward()
{
  analogWrite(motorPin1, speedA);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, speedB);
}
void dontMove()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}


// Sensor Readings
void readSensors()
{
  
  
  // Straight line
  /*======================================================================================================================================================*/
  if (analogRead(farLeft)     <=hilo   &&    analogRead(midLeft)    <=hilo   &&    analogRead(nearLeft)    > hilo    && 
      analogRead(nearRight)   > hilo   &&    analogRead(midRight)   <=hilo   &&    analogRead(farRight)    <=hilo    )
  {
    moveForward(); Serial.println("moveForward()");
  } else
  /*======================================================================================================================================================*/




  // Sharp turns
  /*======================================================================================================================================================*/
  // Sharp left, Left turn
  if (analogRead(farLeft)     >hilo    &&    analogRead(midLeft)    >hilo    &&    analogRead(midRight)   <=hilo   &&    analogRead(farRight)    <=hilo   )
  {
    Serial.println("turningLeft()");
        analogWrite(motorPin1, 0);
        analogWrite(motorPin2, speedA);
        analogWrite(motorPin3, 0);
        analogWrite(motorPin4, speedB-100);
    Serial.println("turnedLeft()");
  } else

  // Sharp right, Right turn
  if (analogRead(farLeft)     <=hilo   &&    analogRead(midLeft)    <=hilo   &&    analogRead(midRight)   >hilo    &&    analogRead(farRight)    >hilo    )
  {
    Serial.println("turningRight()");
        analogWrite(motorPin1, speedA-100);
        analogWrite(motorPin2, 0);
        analogWrite(motorPin3, speedB);
        analogWrite(motorPin4, 0);
    Serial.println("turnedRight()");
  } else
  /*======================================================================================================================================================*/




  //Intersection and Dead end
  /*======================================================================================================================================================*/
  // T intersection
  if (analogRead(farLeft)     >hilo    &&    analogRead(midLeft)    >hilo    &&    analogRead(nearLeft)    >hilo    && 
      analogRead(nearRight)   >hilo    &&    analogRead(midRight)   >hilo    &&    analogRead(farRight)    >hilo    )
  {
    turnLeft();             Serial.println("T intersect, turnLeft()");
  } else
  
  // Dead end
  if (analogRead(farLeft)     <=hilo   &&    analogRead(midLeft)    <=hilo   &&    analogRead(nearLeft)    <=hilo   && 
      analogRead(nearRight)   <=hilo   &&    analogRead(midRight)   <=hilo   &&    analogRead(farRight)    <=hilo   )
  {
    turnAround();           Serial.println("turnAround()");
  }  else
  /*======================================================================================================================================================*/




  // Adjusting position
  /*======================================================================================================================================================*/
  if (  analogRead(nearLeft)  >   50 + analogRead(nearRight) )
  {
    slightLeft();           Serial.println("slightLeft()");
  } else
  
  if (  analogRead(farRight)    <=hilo   &&   analogRead(midRight)    <=hilo   &&   analogRead(nearRight)   <=hilo   &&   analogRead(nearLeft)    <=hilo )
  {
        if (  analogRead(midLeft)   >   20 + analogRead(nearLeft) )
        {
          slightMoreLeft();           Serial.println("slightMoreLeft()");
        } else
        if (  analogRead(farLeft)   >   20 + analogRead(midLeft) )
        {
          moreLeft();           Serial.println("MoreLeft()");
        } 
  } else


  if (  50 + analogRead(nearLeft)  <   analogRead(nearRight) )
  {
    slightRight();          Serial.println("slightRight()");
  } else
  
  if (  analogRead(farLeft)   <=hilo   &&    analogRead(midLeft)    <=hilo   &&    analogRead(nearLeft)   <=hilo    &&    analogRead(nearRight)   <=hilo )
  {
        if (  20 + analogRead(nearRight) <   analogRead(midRight)   )
        {
          slightMoreRight();          Serial.println("slightMoreRight()");
        } else
        if (  20 + analogRead(midRight)   <   analogRead(farRight)   )
        {
          moreRight();          Serial.println("MoreRight()");
        } 
  }
  /*======================================================================================================================================================*/

}

void setup()
{
  Serial.begin(9600);
  Serial.println("Test");
  Serial.println();Serial.print(speedA);Serial.print("   ");Serial.print(speedB);
  //delay(4000);

  // Declaring output pins
  pinMode(motorPin1,    OUTPUT);
  pinMode(motorPin2,    OUTPUT);
  pinMode(motorPin3,    OUTPUT);
  pinMode(motorPin4,    OUTPUT);

  // Declaring input pins
  pinMode(farLeft,      INPUT);
  pinMode(midLeft,      INPUT);
  pinMode(nearLeft,     INPUT);
  //pinMode(centerLeft,   INPUT);
  //pinMode(centerRight,  INPUT);
  pinMode(nearRight,    INPUT);
  pinMode(midRight,     INPUT);
  pinMode(farRight,     INPUT);

}

void loop()
{
  readSensors();
}
