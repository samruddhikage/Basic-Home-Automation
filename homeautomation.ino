#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>  //http communication enable function
#include<ESP8266WebServer.h>
#include<ESP8266WiFiMulti.h>  //multiple library connection
ESP8266WiFiMulti wifiMulti;  //Instant creation
HTTPClient http;   //Instant creation
WiFiClient wificlient; //Instant creation
String link1,payload;
int httpcode; //Instant creation
#define light 5
void setup()
{
  pinMode(light,OUTPUT);
  Serial.begin(9600);
 // wifiMulti.STA();
  wifiMulti.addAP("IOT Lab 2","iot12345");
  wifiMulti.addAP("Galaxy A03 Core0788","12345678");
  wifiMulti.addAP("Sapna","SAPNA2829");
  while(wifiMulti.run()!=WL_CONNECTED)
  {
    Serial.println("connecting.......");
    delay(500);
  }
  Serial.println("Device Name:");
  Serial.print(WiFi.SSID());
  Serial.println("IP Address:");
  Serial.print(WiFi.localIP());
  delay(1000); 
}
void loop()
{
  link1="http://192.168.1.219:500/check_status";
  http.begin(wificlient,link1);
  httpcode=http.GET();
  payload=http.getString();
  Serial.println(httpcode);
  Serial.println(payload);
  if(payload=="on")
  {
    digitalWrite(light,LOW);  //On
  }   
  if(payload=="off")
  {
    digitalWrite(light,HIGH); //off
  }
  
  
}
