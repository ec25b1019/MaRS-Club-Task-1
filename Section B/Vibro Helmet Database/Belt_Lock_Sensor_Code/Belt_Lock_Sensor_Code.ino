int vibR = 11;
int vibL = 6;
int sensor = 5;
void setup()
{
  pinMode(vibR, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(sensor) == HIGH)
  {
    digitalWrite(vibR, LOW);
    digitalWrite(vibL, LOW);
    Serial.println("Belt Is LOCKED");
  }
  else 
  {
    digitalWrite(vibR, HIGH);
    digitalWrite(vibL, HIGH);
    delay(500);
    digitalWrite(vibR, LOW);
    digitalWrite(vibL, LOW);
    delay(500);
    Serial.println("Belt Is OPEN");
  }
  delay(100);
}
