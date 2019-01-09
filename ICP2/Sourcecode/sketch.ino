#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial esp8266(9,10); 
#include <LiquidCrystal_PCF8574.h>
#include <stdlib.h>
#include <Time.h>


int sensorPin = A0;    
float sensorValue = 0;  
int count=9;
int starttime = 0;
int heartrate = 0; 
boolean counted = false;


void setup() {
  
  pinMode(sensorPin, INPUT); 
  Serial.begin(9600);
}


void loop() {
 

starttime = millis();
while (millis()<starttime+10000)                          
{ 
  sensorValue = analogRead(sensorPin);
  if (sensorValue >550 && counted == false)         
  {                                                                
    count++;
    counted = true;  
  }
  else if (sensorValue < 500)
  {
    counted = false; 
  } 
}

    heartrate = count*6;                                    
 Serial.println(heartrate);                                   

  heartrate=0;
  count =0;
}
