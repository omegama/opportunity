//#include <Wire.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::String hum_msg;
std_msgs::Int16 hum_value;
ros::Publisher pub_hum("hum_string", &hum_msg);
ros::Publisher pub_mi_variable("hum_value", &hum_value);


void setup() { 
    //Wire.begin();
    nh.initNode();
    nh.advertise(pub_hum);
    nh.advertise(pub_mi_variable);
    //pinMode(7, INPUT);//Digital
}
   
void loop() 
{
   
   int lecturaDeHumedad = analogRead(A0);
   hum_value.data = lecturaDeHumedad;
/*
  //humedad entre 1000 y 1023 esta super seco
  // if(lecturaDeHumedad>=1000)
   //{
    //hum_msg.data="Fuera del suelo";
      //pub_hum.publish("Fuera del suelo");
      //Serial.println("Fuera del suelo");     
   //}
   //if(lecturaDeHumedad<1000 && lecturaDeHumedad>=600)
   /{
    hum_msg.data="Esta seco el suelo";
      //pub_hum.publish("Esta seco el suelo");
      //Serial.println("Esta seco el suelo");   
   }
   if(lecturaDeHumedad<600 && lecturaDeHumedad>=370)
   {
    hum_msg.data="Esta humedo";
      //pub_hum.publish("Esta humedo");
      //Serial.println("Esta humedo");
   }
   else if(lecturaDeHumedad<370)
   {
    hum_msg.data="Esta empapado";
      //pub_hum.publish("Esta empapado");
      //Serial.println("Esta empapado");
   }
   */
   pub_hum.publish(&hum_msg);
   pub_mi_variable.publish(&hum_value);
   //}
   delay(1000);
    nh.spinOnce();
}
