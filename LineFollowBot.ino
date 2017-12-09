// Motor A
const int motorPin1   = 8;
const int motorPin2   = 9;
const int speedA      = 255; // For setting motor speed

// Motor B
const int motorPin3   = 10;
const int motorPin4   = 11;
const int speedB      = 255; // For setting motor speed

// Sensors
const int farLeft     = A0;
const int midLeft     = A1;
const int nearLeft    = A2;
const int centerLeft  = A3;
const int centerRight = A4;
const int nearRight   = A5;
const int midRight    = A6;
const int farRight    = A7;

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
  analogWrite(motorPin2, speedA-15);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void slightMoreRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA-25);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void moreRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA-35);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}
void turnRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speedB);
  analogWrite(motorPin4, 0);
}

//Left
void slightLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-15);
  analogWrite(motorPin4, 0);
}
void slightMoreLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-25);
  analogWrite(motorPin4, 0);
}
void moreLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, speedB-35);
  analogWrite(motorPin4, 0);
}
void turnLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speedA);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
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
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    >200    || 
      analogRead(centerRight) >200    &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    moveForward(); Serial.println("moveForward();");
  } else



  // Ajdust postion (move left)
  /*==================================================================================================================================*/
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    >200    ||    analogRead(centerLeft)    >200    && 
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    slightLeft(); Serial.println("slightLeft();");
  } else
  
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     >200    ||    analogRead(nearLeft)    >200    &&    analogRead(centerLeft)    <=200   &&
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    slightMoreLeft(); Serial.println("slightMoreLeft();");
  } else
  
  if (analogRead(farLeft)      >200   ||    analogRead(midLeft)     >200    &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   &&
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    moreLeft(); Serial.println("moreLeft();");
  } else
  /*==================================================================================================================================*/
  


  // Adjust position (move right)
  /*==================================================================================================================================*/
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   && 
      analogRead(centerRight) >200    ||    analogRead(nearRight)   >200    &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    slightRight(); Serial.println("slightRight();");
  } else
  
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   && 
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   >200    ||    analogRead(midRight)    >200    &&    analogRead(farRight)      <=200   )
  {
    slightMoreRight(); Serial.println("slightMoreRight();");
  } else
  
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   && 
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    >200    ||    analogRead(farRight)      >200    )
  {
    moreRight(); Serial.println("moreRight();");
  } else
  /*==================================================================================================================================*/



  // Sharp turns
  /*==================================================================================================================================*/
  // Sharp left, Left turn
  if (analogRead(farLeft)     >200    &&    analogRead(midLeft)     >200    &&    analogRead(nearLeft)    >200    &&    analogRead(centerLeft)    >200    && 
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    turnLeft(); Serial.println("turnLeft();");
  }

  // Sharp right, Right turn
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   && 
      analogRead(centerRight) >200    &&    analogRead(nearRight)   >200    &&    analogRead(midRight)    >200    &&    analogRead(farRight)      >200    )
  {
    turnRight(); Serial.println("turnRight();");
  }
  /*==================================================================================================================================*/



  // T intersection
  if (analogRead(farLeft)     >200    &&    analogRead(midLeft)     >200    &&    analogRead(nearLeft)    >200    &&    analogRead(centerLeft)    >200    && 
      analogRead(centerRight) >200    &&    analogRead(nearRight)   >200    &&    analogRead(midRight)    >200    &&    analogRead(farRight)      >200    )
  {
    turnLeft(); Serial.println("turnLeft();");
  }
  
  // Dead end
  if (analogRead(farLeft)     <=200   &&    analogRead(midLeft)     <=200   &&    analogRead(nearLeft)    <=200   &&    analogRead(centerLeft)    <=200   && 
      analogRead(centerRight) <=200   &&    analogRead(nearRight)   <=200   &&    analogRead(midRight)    <=200   &&    analogRead(farRight)      <=200   )
  {
    turnAround(); Serial.println("turnAround();");
  }
  
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Test");
  Serial.println();Serial.print(speedA);Serial.print("   ");Serial.print(speedB);
  

  // Declaring output pins
  pinMode(motorPin1,    OUTPUT);
  pinMode(motorPin2,    OUTPUT);
  pinMode(motorPin3,    OUTPUT);
  pinMode(motorPin4,    OUTPUT);

  // Declaring input pins
  pinMode(farLeft,      INPUT);
  pinMode(midLeft,      INPUT);
  pinMode(nearLeft,     INPUT);
  pinMode(centerLeft,   INPUT);
  pinMode(centerRight,  INPUT);
  pinMode(nearRight,    INPUT);
  pinMode(midRight,     INPUT);
  pinMode(farRight,     INPUT);
}

void loop()
{
  readSensors();
}
