

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
