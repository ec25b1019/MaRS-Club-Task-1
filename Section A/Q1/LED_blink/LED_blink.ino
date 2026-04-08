unsigned long current = 0;
unsigned long prev1 = 0, prev2 = 0, prev3 = 0;
int state1 = LOW, state2 = LOW, state3 = LOW;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  current=millis();
  led1();
  led2();
  led3();
}

void led1() {
  if(current-prev1>=500){
    prev1=current;
    if(state1==LOW){
      state1=HIGH;
    }
    else{
      state1=LOW;
    }
    digitalWrite(12, state1);
  }
}

void led2() {
  if(current-prev2>=1000){
    prev2=current;
    if(state2==LOW){
      state2=HIGH;
    }
    else{
      state2=LOW;
    }
    digitalWrite(8, state2);
  }
}

void led3() {
  if(current-prev3>=1500){
    prev3=current;
    if(state3==LOW){
      state3=HIGH;
    }
    else{
      state3=LOW;
    }
    digitalWrite(4, state3);
  }
}