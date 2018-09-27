#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <geometry_msgs/Quaternion.h>

ros::NodeHandle  nh;

Servo servo1;
Servo servo2;
//int prueba=1;
int anguloA=0;
int anguloB=0;
float ser2R=0;
float ser2B=0;
float ser1R=0;
float ser1B=0;
int angle_increment=5;

void servo_cbA(const geometry_msgs::Quaternion& servos_msg){
float ser2R=servos_msg.x; //servo de arriba da para arriba
float ser2B=servos_msg.y; //servo de arriba da para abajo
float ser1R=servos_msg.z; //servo de abajo da para arriba
float ser1B=servos_msg.w; //servo de abajo da para abajo
//while ser1A!=0

//void servo_cbA( const std_msgs::UInt16& servoA_msg){
  int anguloA=0;
  int anguloB=0;
//  int x = servoA_msg;
  
  if(ser2R==1)
  {
    anguloA+=angle_increment;
    servo1.write(anguloA);
    //delay(500);
  }
  if(ser2B==1)
  {
    anguloA-=angle_increment;
    servo1.write(anguloA);
    //delay(500);
  }
  if(ser1R==1)
  {
    anguloB+=angle_increment;
    servo2.write(anguloB);
    //delay(500);
  }
  if(ser1B==1)
  {
    anguloB-=angle_increment;
    servo2.write(anguloB);
    //delay(500);
  }
  
  
}

ros::Subscriber<geometry_msgs::Quaternion> sub("servos", servo_cbA);

//ros::Subscriber<std_msgs::UInt16> sub("servo_abajo", servo_cbA);

void setup(){
  //pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo1.attach(10); //attach it to pin 9
  servo2.attach(9);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
