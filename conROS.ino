#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup() { 
    nh.initNode();
    nh.advertise(chatter);
    Serial.begin(9600);
    pinMode(7, INPUT);//Digital
}
 
void loop() 
{
   int lecturaDeHumedad = analogRead(A0);//Analogo
   Serial.print(lecturaDeHumedad);
  //humedad entre 1000 y 1023 esta super seco
   if(lecturaDeHumedad>=1000)
   {
      chatter.publish("Fuera del suelo");
      //Serial.println("Fuera del suelo");     
   }
   else if(lecturaDeHumedad<1000 && lecturaDeHumedad>=600)
   {
      chatter.publish("Esta seco el suelo");
      //Serial.println("Esta seco el suelo");   
   }
   else if(lecturaDeHumedad<600 && lecturaDeHumedad>=370)
   {
      chatter.publish("Esta humedo");
      //Serial.println("Esta humedo");
   }
   else if(lecturaDeHumedad<370)
   {
      chatter.publish("Esta empapado");
      //Serial.println("Esta empapado");
   }
   delay(1000);
    nh.spinOnce();
}
