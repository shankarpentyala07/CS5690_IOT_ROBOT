

int result [5];           
#include <Wire.h>         
#include <SFE_BMP180.h>   
#define ALTITUDE 3       
SFE_BMP180 pressure;      
#include <DHT.h>          
#define DHTPIN 2          
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
Serial.begin(9600);       
Serial.println("Program started");

pinMode(A0, INPUT);       
pinMode(A1, INPUT);       
//BMP180 Setup
if (pressure.begin())     
 {Serial.println("BMP180 init success");
 Serial.print("AWS :");
 Serial.print("\t");
 Serial.print("Rain Drop\t");
 Serial.print("Pressure \t");
 Serial.print("Air Hum\t");
 Serial.print("\t");
 Serial.println("Temp \t");}
else                       
  {
    Serial.println("BMP180 init fail");
    while (1);
  }
  

dht.begin(); 
}

void loop() {
//analog setup
int A_Rain = analogRead(A0);
int A_Soil = analogRead(A1); 
A_Rain = map(A_Rain, 800, 1023, 100, 0);

result[1]=A_Rain;

char status;
double T, P, p0; 
status = pressure.startTemperature();
if (status != 0) {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0) {
    status = pressure.startPressure(3);
      if (status != 0) {
        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0) {
          p0 = pressure.sealevel(P, ALTITUDE);
          result[2]=p0;
        }}}}
result[3] = dht.readHumidity();
result[4] = dht.readTemperature();
Serial.print(" \t");
Serial.print(result[0]);
Serial.print(" %\t");
Serial.print("\t");
Serial.print(result[1]);
Serial.print(" %\t");
Serial.print("\t");
Serial.print(result[2]);
Serial.print(" hPa \t");
Serial.print(result[3]);
Serial.print(" %\t");
Serial.print("\t");
Serial.print(result[4]);
Serial.println("C \t");
delay(5000);
}
