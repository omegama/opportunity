#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <geometry_msgs/Quaternion.h>

ros::NodeHandle  nh;

Servo servo1;
Servo servo2;
int prueba=1;
void servo_cbA(const geometry_msgs::Quaternion& servos_msg){
float ser2R=servos_msg.x;
float ser2B=servos_msg.y;
float ser1R=servos_msg.z;
float ser1B=servos_msg.w;
//while ser1A!=0

//void servo_cbA( const std_msgs::UInt16& servoA_msg){
  int anguloA=0;
  int anguloB=0;
//  int x = servoA_msg;
  while(true)
  {
  if(ser2R==1)
  {
    anguloA+=10;
    servo1.write(anguloA);
    //delay(500);
  }
  if(ser2B==1)
  {
    anguloA-=10;
    servo1.write(anguloA);
    //delay(500);
  }
  if(ser1R==1)
  {
    anguloB+=10;
    servo2.write(anguloB);
    //delay(500);
  }
  if(ser1B==1)
  {
    anguloB-=10;
    servo2.write(anguloB);
    //delay(500);
  }
  }
  
  
  
   //set servo angle, should be from 0-180  
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

ros::Subscriber<geometry_msgs::Quaternion> sub("servos", servo_cbA);

//ros::Subscriber<std_msgs::UInt16> sub("servo_abajo", servo_cbA);

void setup(){
  //pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo1.attach(8); //attach it to pin 9
  servo2.attach(9);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
