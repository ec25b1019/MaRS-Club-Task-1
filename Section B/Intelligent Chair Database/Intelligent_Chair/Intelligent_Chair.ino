int trigPin = 13; 
int echoPin = 10;
int trigPi = 12;
int echoPi = 5;
int ot1 = 6;
int ot2 = 9;
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;
void setup() 
{         
  Serial.begin(9600);
  pinMode(3,INPUT_PULLUP);
  pinMode(ot1,OUTPUT);
  pinMode(ot2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPi,OUTPUT);
  pinMode(echoPi,INPUT);
  analogWrite(ot1,225);
  analogWrite(ot2,225);  
}
void loop(){
if(digitalRead(3) == 0)
  {  
while(digitalRead(3) == 0);
digitalWrite(in3, LOW);
digitalWrite(in1, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in2, HIGH);
delay(1000);
digitalWrite(in2, LOW);
digitalWrite(in4, HIGH);
delay(1);
    }
long duration, distance;
digitalWrite(trigPi,HIGH);
delayMicroseconds(1000);
digitalWrite(trigPi, LOW);
duration=pulseIn(echoPi, HIGH);
distance =(duration/2)/29.1;
Serial.print("Sensor1 = ");
Serial.print(distance);
Serial.println("CM");
delay(100);
if((distance<=20 and distance>=10))
{
digitalWrite(in4, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in1, HIGH);
delay(1000);
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
delay(7500);
}
else if(distance<10 and distance>0)
{
digitalWrite(in1, HIGH);
digitalWrite(in3, HIGH);
delay(1000);
digitalWrite(in3, LOW);
digitalWrite(in1, LOW);
delay(10000);
digitalWrite(in4, HIGH);
digitalWrite(in2, HIGH);
delay(1000);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
}
else
{
digitalWrite(in4,LOW); 
digitalWrite(in2,LOW); 
digitalWrite(in3,LOW); 
digitalWrite(in1,LOW); 
  }
digitalWrite(trigPin,HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
duration=pulseIn(echoPin, HIGH);
distance =(duration/2)/29.1;
Serial.print("Sensor2 = ");
Serial.print(distance);
Serial.println("CM");
delay(100);
if((distance<=20 and distance>=10))
{
digitalWrite(in4, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in1, HIGH);
delay(1000);
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
delay(7500);
}
else if(distance<10 and distance>0)
{
digitalWrite(in1, HIGH);
digitalWrite(in3, HIGH);
delay(1000);
digitalWrite(in3, LOW);
digitalWrite(in1, LOW);
delay(10000);
digitalWrite(in4, HIGH);
digitalWrite(in2, HIGH);
delay(1000);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
}
else
{
digitalWrite(in4,LOW); 
digitalWrite(in2,LOW); 
digitalWrite(in3,LOW); 
digitalWrite(in1,LOW); 
  }
}
