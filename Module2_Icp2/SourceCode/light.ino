/*
Project: Grove Light Sensor Lesson
Programmer: Shahrulnizam Mat Rejab
Board: Arduino Uno
Last Modified: 9 November 2016
Website: http://shahrulnizam.com
*/

int light;

void setup()
{
Serial.begin(9600);
pinMode(A1,INPUT);
}

void loop()
{
light=analogRead(A1);
Serial.println(light);
delay(1000);

}
