#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
ros::NodeHandle nh;

std_msgs::String str_msg;
std_msgs::Int16 hum_value;

ros::Publisher pub_hum("hum_string", &hum_msg);
ros::Publisher pub_mi_variable("hum_value", &hum_value);
void setup() { 
    nh.initNode();
    nh.advertise(pub_hum);
    nh.advertise(pub_mi_variable);
    Serial.begin(9600);
}
 
void loop() 
{
   int lecturaDeHumedad = analogRead(A0);//Analogo
   hum_value.data = lecturaDeHumedad;
  
   if(lecturaDeHumedad>=1000)
   {
      hum_msg.data="Fuera del suelo";
      pub_hum.publish(&hum_msg);     
   }
   else if(lecturaDeHumedad<1000 && lecturaDeHumedad>=600)
   {
      hum_msg.data="Esta seco el suelo";
      pub_hum.publish(&hum_msg);   
   }
   else if(lecturaDeHumedad<600 && lecturaDeHumedad>=370)
   {
      hum_msg.data="Esta humedo";
      pub_hum.publish(&hum_msg);
   }
   else if(lecturaDeHumedad<370)
   {
       hum_msg.data="Esta empapado");
       pub_hum.publish(&hum_msg);
   }
   
    pub_mi_variable.publish(&hum_value);
    delay(1000);
    nh.spinOnce();
}
