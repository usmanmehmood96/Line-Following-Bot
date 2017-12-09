// Motor A
const int motorPin1   = 8;
const int motorPin2   = 9;
const int speedA      = 255; // For setting motor speed

// Motor B
const int motorPin3   = 10;
const int motorPin4   = 11;
const int speedB      = 255; // For setting motor speed

// Sensors
//const int farLeft     = A0;
const int midLeft     = A1;
const int nearLeft    = A2;
const int centerLeft  = A3;
const int centerRight = A4;
const int nearRight   = A5;
const int midRight    = A6;
//const int farRight    = A7;

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
  analogWrite(motorPin2, speedA-45);
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
  analogWrite(motorPin1, speedA-65);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}

//Left
void slightLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-45);
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
  analogWrite(motorPin4, speedB-65);
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
  if (analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    >500  && 
      analogRead(centerRight) >500    &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   )
  {
    moveForward(); Serial.println("moveForward()");
  } else



  // Ajdust postion (move left)
  /*==================================================================================================================================*/ /*
  if (analogRead(farLeft)     <=500   &&    analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    >500    ||    analogRead(centerLeft)    >500    && 
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   &&    analogRead(farRight)      <=500   )
  {
    slightLeft();           Serial.println("slightLeft()");
  } else
  
  if (analogRead(farLeft)     <=500   &&    analogRead(midLeft)     >500    ||    analogRead(nearLeft)    >500    &&    analogRead(centerLeft)    <=500   &&
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   &&    analogRead(farRight)      <=500   )
  {
    slightMoreLeft();       Serial.println("slightMoreLeft()");
  } else
  
  if (analogRead(farLeft)      >500   ||    analogRead(midLeft)     >500    &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500   &&
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   &&    analogRead(farRight)      <=500   )
  {
    moreLeft();             Serial.println("moreLeft()"); 
  } else
  /*==================================================================================================================================*/
  


  // Adjust position (move right)
  /*==================================================================================================================================*/ /*
  if (analogRead(farLeft)     <=500   &&    analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500   && 
      analogRead(centerRight) >500    ||    analogRead(nearRight)   >500    &&    analogRead(midRight)    <=500   &&    analogRead(farRight)      <=500   )
  {
    slightRight();          Serial.println("slightRight()");
  } else
  
  if (analogRead(farLeft)     <=500   &&    analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500   && 
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   >500    ||    analogRead(midRight)    >500    &&    analogRead(farRight)      <=500   )
  {
    slightMoreRight();      Serial.println("slightMoreRight()");
  } else
  
  if (analogRead(farLeft)     <=500   &&    analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500   && 
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    >500    ||    analogRead(farRight)      >500    )
  {
    moreRight();            Serial.println("moreRight()");
  } else
  /*==================================================================================================================================*/



  // Sharp turns
  /*==================================================================================================================================*/
  // Sharp left, Left turn
  if (analogRead(midLeft)     >500    &&    analogRead(nearLeft)    >500    &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   )
  {
    Serial.println("turningLeft()");
    delay(2000);
    turnLeft();             
    Serial.println("turnedLeft()");
  } else

  // Sharp right, Right turn
  if (analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(nearRight)   >500    &&    analogRead(midRight)    >500    )
  {
    Serial.println("turningRight()");
    delay(2000);
    turnRight();            
    Serial.println("turnRight()");
  } else
  /*==================================================================================================================================*/



  // T intersection
  if (analogRead(midLeft)     >500    &&    analogRead(nearLeft)    >500    &&    analogRead(centerLeft)    >500    && 
      analogRead(centerRight) >500    &&    analogRead(nearRight)   >500    &&    analogRead(midRight)    >500    )
  {
    turnLeft();             Serial.println("T intersect, turnLeft()");
  } else
  
  // Dead end
  if (analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500   && 
      analogRead(centerRight) <=500   &&    analogRead(nearRight)   <=500   &&    analogRead(midRight)    <=500   )
  {
    turnAround();           Serial.println("turnAround()");
  }  else



  if (  analogRead(centerLeft)  >   50 + analogRead(centerRight) )
  {
    slightLeft();           Serial.println("slightLeft()");
  } else
  
  if (  analogRead(midRight)     <=500   &&    analogRead(nearRight)    <=500   &&    analogRead(centerRight)    <=500   &&    analogRead(centerLeft)    <=500 )
  {
        if (  analogRead(nearLeft)    >   20 + analogRead(centerLeft) )
        {
          slightMoreLeft();           Serial.println("slightMoreLeft()");
        } else
        if (  analogRead(midLeft)     >   20 + analogRead(nearLeft) )
        {
          moreLeft();           Serial.println("MoreLeft()");
        } 
  } else


  if (  50 + analogRead(centerLeft)  <   analogRead(centerRight) )
  {
    slightRight();          Serial.println("slightRight()");
  } else
  
  if (  analogRead(midLeft)     <=500   &&    analogRead(nearLeft)    <=500   &&    analogRead(centerLeft)    <=500     &&    analogRead(centerRight)    <=500 )
  {
        if (  20 + analogRead(centerRight) <   analogRead(nearRight)   )
        {
          slightMoreRight();          Serial.println("slightMoreRight()");
        } else
        if (  20 + analogRead(nearRight)   <   analogRead(midRight)   )
        {
          moreRight();          Serial.println("MoreRight()");
        } 
  }
  
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Testiiii");
  Serial.println();Serial.print(speedA);Serial.print("   ");Serial.print(speedB);
  

  // Declaring output pins
  pinMode(motorPin1,    OUTPUT);
  pinMode(motorPin2,    OUTPUT);
  pinMode(motorPin3,    OUTPUT);
  pinMode(motorPin4,    OUTPUT);

  // Declaring input pins
  //pinMode(farLeft,      INPUT);
  pinMode(midLeft,      INPUT);
  pinMode(nearLeft,     INPUT);
  pinMode(centerLeft,   INPUT);
  pinMode(centerRight,  INPUT);
  pinMode(nearRight,    INPUT);
  pinMode(midRight,     INPUT);
  //pinMode(farRight,     INPUT);

}

void loop()
{
  readSensors();
}
