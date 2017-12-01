// Motor A
const int motorPin1   = 8;
const int motorPin2   = 9;

// Motor B
const int motorPin3   = 10;
const int motorPin4   = 11;

// Sensors
const int near        = 7;
const int farLeft     = 6;
const int nearLeft    = 5;
const int center      = 4;
const int nearRight   = 3;
const int farRight    = 2;

// Movement
void moveForward()
{
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 120);
   analogWrite(motorPin3, 180);
   analogWrite(motorPin4, 0);
}
void moveBackward()
{
  analogWrite(motorPin1, 150);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 180);
}
void slightRight()
{
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 80);
}
void slightLeft()
{
  analogWrite(motorPin1, 80);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);
}
void dontMove()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}
void turnLeft()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 180);
}
void turnRight()
{
  analogWrite(motorPin1, 150);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}

// Sensor Readings
void readSensors()
{
  // Straight line
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == HIGH && digitalRead(center) == LOW && digitalRead(nearRight) == HIGH && digitalRead(farRight) == HIGH)
  {
    moveForward();
  } else
  
  // Ajdust postion (move left)
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == LOW && digitalRead(center) == HIGH && digitalRead(nearRight) == HIGH && digitalRead(farRight) == HIGH)
  {
    slightLeft();
  } else
  
  // Adjust position (move right)
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == HIGH && digitalRead(center) == HIGH && digitalRead(nearRight) == LOW && digitalRead(farRight) == HIGH)
  {
    slightRight();
  } else
  
  // Sharp left, Left + Straight intersection
  if (digitalRead(farLeft) == LOW && digitalRead(nearLeft) == LOW && digitalRead(center) == LOW && digitalRead(nearRight) == HIGH && digitalRead(farRight) == HIGH)
  {
    turnLeft();
  } else
  
  // Sharp right, Right + Straight intersection
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == HIGH && digitalRead(center) == LOW && digitalRead(nearRight) == LOW && digitalRead(farRight) == LOW)
  {
    turnRight();
  } else

  // Sharp left, Left turn
  if (digitalRead(farLeft) == LOW && digitalRead(nearLeft) == LOW && digitalRead(center) == HIGH && digitalRead(nearRight) == HIGH && digitalRead(farRight) == HIGH)
  {
    turnLeft();
  }

  // Sharp right, Right turn
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == HIGH && digitalRead(center) == HIGH && digitalRead(nearRight) == LOW && digitalRead(farRight) == LOW)
  {
    moveForward();
  }

  // T intersection
  if (digitalRead(farLeft) == LOW && digitalRead(nearLeft) == LOW && digitalRead(center) == HIGH && digitalRead(nearRight) == LOW && digitalRead(farRight) == LOW)
  {
    turnLeft();
  }

  // 4 way intersection
  if (digitalRead(farLeft) == LOW && digitalRead(nearLeft) == LOW && digitalRead(center) == LOW && digitalRead(nearRight) == LOW && digitalRead(farRight) == LOW)
  {
    turnLeft();
  }
  
  // Stop moving
  if (digitalRead(farLeft) == HIGH && digitalRead(nearLeft) == HIGH && digitalRead(center) == HIGH && digitalRead(nearRight) == HIGH && digitalRead(farRight) == HIGH)
  {
    dontMove();
  }
}

void setup()
{
    //Serial.begin (9600);

    // Declaring output pins
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    // Declaring input pins
    pinMode(farLeft,   INPUT);
    pinMode(nearLeft,  INPUT);
    pinMode(center,    INPUT);
    pinMode(nearRight, INPUT);
    pinMode(farRight,  INPUT);
}

void loop()
{
  readSensors();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
