#include <Servo.h>

Servo myservo1; //Servo for gripper. 
Servo myservo2; //Servo for wrist.
Servo myservo3; //Servo for 1 elbow.
Servo myservo4; //Servo for 2 elbow.
Servo myservo5; //Servo for 3 elbow.
Servo myservo6; //servo for base.

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int pos6 = 0;

int power=0;
int m=0;          // for motor 

void setup()
{
 Serial.begin(115200);
 //code for attaching (defininig) servos --> PWM (Pulse Width Modulation) Pins.
  myservo1.attach(2);
  myservo1.write(0);
  Serial.println("Servo1 Initialized");
  myservo2.attach(3);
  myservo2.write(0);
  Serial.println("Servo2 Initialized");
  myservo3.attach(4);
  myservo3.write(0);
  Serial.println("Servo3 Initialized");
  myservo4.attach(5);  
  myservo4.write(0);
  Serial.println("Servo4 Initialized");
  myservo5.attach(6);
  myservo5.write(0);
  Serial.println("Servo5 Initialized");
  myservo6.attach(7);
  myservo6.write(0);
  Serial.println("Servo6 Initialized");
}

void loop() 
{
  if (myservo6 
delay(00);
}
}
}
void reset()
{
    myservo1.write(0);
  Serial.println("servo1 resetted");
    myservo2.write(0);
  Serial.println("servo1 resetted");
    myservo3.write(0);
  Serial.println("servo1 resetted");
    myservo4.write(0);
  Serial.println("servo1 resetted");
    myservo5.write(0);
  Serial.println("servo1 resetted");
    myservo6.write(0);
  Serial.println("servo1 resetted");
}

  


