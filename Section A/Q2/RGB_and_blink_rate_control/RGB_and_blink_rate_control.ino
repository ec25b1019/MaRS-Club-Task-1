int pot=A0;
int led=5;
int red=11;
int green=10;
int blue=9;
unsigned long prev=0;
int state=LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  int potVal=analogRead(pot);
  
  unsigned long current=millis();
  int rate=map(potVal, 0, 1023, 50, 1000);
  if (current-prev>=rate){
    prev=current;
    if (state==LOW){
      state=HIGH;
    }
    else{
      state=LOW;
    }
  }
  digitalWrite(led, state);
  
  int rVal=0;
  int gVal=0;
  int bVal=0;
  if (potVal<=341){
    rVal=map(potVal, 0, 341, 255, 0);
    gVal=map(potVal, 0, 341, 0, 255);
    bVal=0;
  }
  else if (potVal<=682){
    gVal=map(potVal, 341, 682, 255, 0);
    bVal=map(potVal, 341, 682, 0, 255);
    rVal=0;
  }
  else {
    bVal=map(potVal, 682, 1023, 255, 0);
    rVal=map(potVal, 682, 1023, 0, 255);
    gVal=0;
  }
  analogWrite(red, rVal);
  analogWrite(green, gVal);
  analogWrite(blue, bVal);
}