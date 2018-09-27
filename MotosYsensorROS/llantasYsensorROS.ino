#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::String hum_msg;
std_msgs::Int16 hum_value;
ros::Publisher pub_hum("hum_string", &hum_msg);
ros::Publisher pub_mi_variable("hum_value", &hum_value);

void servo_cb( const std_msgs::Int16& cmd_msg){
  if(cmd_msg.data==1)
  {
  //adelante izquierda
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  
  }
  if(cmd_msg.data==2)
  {
  //adelante derecha
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  
  }
  if(cmd_msg.data==3)
  {
  //atras izquierda
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  }
  if(cmd_msg.data==4)
  {
  //atras derecha
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  
  }
  if(cmd_msg.data==5)
  {
  //alto
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  } 
}

ros::Subscriber<std_msgs::Int16> sub("motor", servo_cb );

void setup() {
    pinMode(2, OUTPUT); //IN1
    pinMode(3, OUTPUT);//In2
    pinMode(4, OUTPUT);//IN3
    pinMode(5, OUTPUT); //IN4

    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub_hum);
    nh.advertise(pub_mi_variable);

}

void loop() {
   int lecturaDeHumedad = analogRead(A0);
   hum_value.data = lecturaDeHumedad;

   pub_hum.publish(&hum_msg);
   pub_mi_variable.publish(&hum_value);

   nh.spinOnce();
   delay(1);


}
