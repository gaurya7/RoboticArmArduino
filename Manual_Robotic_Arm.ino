#include <Servo.h>
#include <IRremote.h>

Servo myservo1; //Servo of base with interface of pot1 
Servo myservo2; //Servo connected to L with interface of button 1 and button 2
Servo myservo3; //Servo connected to L2 with interface of button 3 and button 4
Servo myservo4; //Servo of elbow with interface of pot2
Servo myservo5; //Servo connected to L3 with interface of button 5 and button 6


int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;


int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int power=0;
int m=0;          // for motor 

void setup()
{
 Serial.begin(115200);
irrecv.enableIRIn();
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
}

void loop() 
{
if (irrecv.decode(&results)) 
{

irrecv.resume();

//You can also print your received values here
//Just declare the serial in the setup function
//Use Serial.println(results.value);

//Serial.println(results.value);

if (results.value == 16736925)      //replace these value with the values of your code
{ 
reset();
}
else if(results.value == 16761405)  //replace these value with the values of your code
{ 
 if(power==0)
 {
 power=1;
  Serial.println("power on");
 }
 else if(power==1)
 {
  power=0;
  Serial.println("power off");
 }
 else 
 {
  Serial.println("error in power");
 }  
 }
 else if(results.value == 16724175)  //motor 1 remote b1
{ 
 m=1; 
 Serial.println("motor1 selected");
}
 else if(results.value == 16718055)  //motor 2 remote b2
{ 
m=2;
 Serial.println("motor2 selected");  
}
 else if(results.value == 16743045)  //motor 3 remote b3
{ 
 m=3; 
  Serial.println("motor3 selected");
}
 else if(results.value == 16716015)  //motor 4 remote b4
{ 
m=4;  
 Serial.println("motor4 selected");
}
 else if(results.value == 16726215)  //motor 5 remote b5
{ 
 m=5; 
  Serial.println("motor5 selected");
}
else if(results.value == 16754775)  //for increasing angle
{Serial.println("+++++"); 
  if( m==1 )
  {
    if ((pos1>=0)&&(pos1<=180)) //motor no.1 base 180.
    {
    pos1=pos1+15; 
    myservo1.write(pos1);
    Serial.println("Position 1 is : ");
    Serial.println(pos1);
    }
    if(pos1>180)
    {
      pos1=180;
    }
  }
else if( m==2 )
  {
    if ((pos2>=0)&&(pos2<=180)) //motor no.2 elbow 1 90.
    {
    pos2=pos2+15; 
    myservo2.write(pos2);
    Serial.println("Position 2 is : ");
    Serial.println(pos2);
    }
    if(pos2>180)
    {
      pos2=180;
    }
  }
else if( m==3 )
  {
    if ((pos3>=0)&&(pos3<=180)) //motor no.3 elbow2 90.
    {
    pos3=pos3+15; 
    myservo3.write(pos3);
    Serial.println("Position 3 is : ");
    Serial.println(pos3);
    }
    if(pos3>180)
    {
      pos3=180;
    }
  }
else if( m==4 )
  {
    if ((pos4>=0)&&(pos4<=180)) //motor no.4 wrist 180.
    {
      pos4=pos4+15; 
      myservo4.write(pos4);
      Serial.println("Position 4 is : ");
    Serial.println(pos4);
    }
    if(pos4>180)
    {
      pos4=180;
    }
  }
else if( m==5 )
  {
   if ((pos5>=0)&&(pos5<=90)) //motor no.5 arm 90.
    {
      pos5=pos5+15; 
      myservo5.write(pos5);
      Serial.println("Position 5 is : ");
    Serial.println(pos5);
    }
    if(pos5>90)
    {
      pos5=90;
    }
  }
}
else if(results.value == 16769055)  //for increasing angle
{Serial.println("----- ");
  if( m==1 )
  {
    if ((pos1>=0)&&(pos1<=195)) //motor no.1 base 180.
    {
    pos1=pos1-15; 
    myservo1.write(pos1);
    Serial.println("Position 1 is : ");
    Serial.println(pos1);
    }
    if(pos1<0)
    {
      pos1=0;
    }
  }
else if( m==2 )
  {
    if ((pos2>=0)&&(pos2<=195)) //motor no.2 elbow 1 90.
    {
    pos2=pos2-15; 
    myservo2.write(pos2);
    Serial.println("Position 2 is : ");
    Serial.println(pos2);
    }
    if(pos2<0)
    {
      pos2=0;
    }
  }
else if( m==3 )
  {
    if ((pos3>=0)&&(pos3<=195)) //motor no.3 elbow2 90.
    {
    pos3=pos3-15; 
    myservo3.write(pos3);
    Serial.println("Position 3 is : ");
    Serial.println(pos3);
    }
    if(pos3<0)
    {
      pos3=0;
    }
  }
else if( m==4 )
  {
    if ((pos4>=0)&&(pos4<=195)) //motor no.4 wrist 180.
    {
      pos4=pos4-15; 
      myservo4.write(pos4);
      Serial.println("Position 4 is : ");
    Serial.println(pos4);
    }
    if(pos4<0)
    {
      pos4=0;
    }
  }
else if( m==5 )
  {
   if ((pos5>=0)&&(pos5<=105)) //motor no.5 arm 90.
    {
      pos5=pos5-15; 
      myservo5.write(pos5);
      Serial.println("Position 5 is : ");
    Serial.println(pos5);
    }
    if(pos5<0)
    {
      pos5=0;
    }
  }






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
}
  


