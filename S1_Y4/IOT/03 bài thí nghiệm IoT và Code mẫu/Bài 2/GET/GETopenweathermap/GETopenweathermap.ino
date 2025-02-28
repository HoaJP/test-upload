#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <Arduino_JSON.h>
#include <string.h>
const char* ssid = "S21 của Khánh";
const char* password = "11112003" ;
 
String weatherApiKey = "6d35f1ab8a502527d69c1ff0d5e0659c";
 
String city = "Hanoi";
String countrycode = "";
String weatherJsonBuffer;
 
//http config
String weatherUrl = "https://api.openweathermap.org/data/2.5/weather?lat=21.0278&lon=105.8342&appid=6d35f1ab8a502527d69c1ff0d5e0659c";
 
int temp = 30;
int humi = 80;
 
String httpGETRequest(const char* Url);
void setup() {
   
  Serial.begin(115200);
 
  //setup wifi
  WiFi.begin(ssid,password);
  Serial.println("conecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  //read temp to openweather
  Serial.println(weatherUrl);
  weatherJsonBuffer = httpGETRequest(weatherUrl.c_str());
  Serial.println(weatherJsonBuffer);
  JSONVar weatherJson = JSON.parse(weatherJsonBuffer);
  if(JSON.typeof_(weatherJson) == "undefined")
  {
    Serial.println("Parsing fail");
    return;
  }
  Serial.println();
  temp = weatherJson["main"]["temp"];
  temp = temp - 273;
  Serial.print("Temperature: ");
  Serial.println(temp);
 
  humi = weatherJson["main"]["humidity"];
  Serial.print("Humidity: ");
  Serial.println(humi);

  delay(10000);
}
 
String httpGETRequest(const char* Url)
{
  HTTPClient http;
  http.begin(Url);
  int responseCode = http.GET();
  String responseBody = "{}";
  if(responseCode > 0)
  {
    Serial.print("responseCode:");
    Serial.println(responseCode);
    responseBody = http.getString();
  }
  else
  {
    Serial.print("Error Code: ");
    Serial.println(responseCode);
  }
  http.end();
  return responseBody;
}