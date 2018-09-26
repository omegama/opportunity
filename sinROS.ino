
void setup() {
   Serial.begin(9600);
    pinMode(7, INPUT);//Digital
}
 
void loop() 
{
   int lecturaDeHumedad = analogRead(A0);//Analogo
   Serial.print(lecturaDeHumedad);//Imprime el valor que recibe el sensor
  //humedad entre 1000 y 1023 esta super seco
   if(lecturaDeHumedad>=1000)
   {
      Serial.println("Fuera del suelo");     
   }
   else if(lecturaDeHumedad<1000 && lecturaDeHumedad>=600)
   {
      Serial.println("Esta seco el suelo");   
   }
   else if(lecturaDeHumedad<600 && lecturaDeHumedad>=370)
   {
      Serial.println("Esta humedo");
   }
   else if(lecturaDeHumedad<370)
   {
      Serial.println("Esta empapado");
   }
   delay(1000);
}
