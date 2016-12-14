#include<SoftwareSerial.h>

int BTS_RX=3;
int BTS_TX=2;
SoftwareSerial BTSerial = SoftwareSerial(BTS_TX, BTS_RX);

#define FORWARD '1'  //forward
#define FORWARD_L '2'  //LEFT
#define FORWARD_R '4'  //RIGHT
#define BACKWARD '5'  //BACK
#define STOP '3'  //STOP

int Left_motor_back=8;     
int Left_motor_go=9;     

int Right_motor_go=10;   
int Right_motor_back=11;  

void run()   
{
  digitalWrite(Right_motor_go,HIGH);  
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,200);
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH); 
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200);
  analogWrite(Left_motor_back,0);   
}

void brake()
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);  
}

void left()       
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);  
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);   
}

void spin_left()         
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,200);
 
}

void right()       
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);
   
}

void spin_right()        
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,200);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);    
}

void back()        
{
  digitalWrite(Right_motor_go,LOW); 
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);   
}

void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
 
  pinMode(Left_motor_go,OUTPUT); 
  pinMode(Left_motor_back,OUTPUT); 
  pinMode(Right_motor_go,OUTPUT);
  pinMode(Right_motor_back,OUTPUT);
}
void loop()
{  
  char direct;
  if(BTSerial.available() >0)
  {
    direct = BTSerial.read();
    
    if(direct ==FORWARD)
    run();
    else if(direct ==FORWARD_L)
    left();
    else if(direct ==FORWARD_R)
    right();
    else if(direct ==BACKWARD)
    back();
    else if(direct ==STOP)
    brake();
    else{}
    
    delay(50);
    
    if(direct != STOP)
      brake();
  }
  
  delay(100);
}
