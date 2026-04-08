int led=13;
int button=3;
unsigned long randDelay;
unsigned long OnTime;
unsigned long ResetTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP); 
  randDelay=random(2500, 6500);
  ResetTime=millis();
  
  Serial.println("Ready");
  delay(500);
  Serial.println("Set");
  delay(500);
  Serial.println("Go...");
}

void loop() {
  unsigned long current=millis();

  if (digitalRead(led)==LOW) {
    if (current-ResetTime>=randDelay) {
      digitalWrite(led, HIGH); 
      OnTime=millis(); 
    }
  } 
  
  else {
    if (digitalRead(button)==LOW) {
      unsigned long reactTime=millis()-OnTime; 
      Serial.print("Reaction Time: ");
      Serial.print(reactTime);
      Serial.println(" ms");
      
      digitalWrite(led, LOW);        
      randDelay=random(2000, 6000); 
      ResetTime=millis();         
      Serial.println("");
      Serial.println("Get ready for the next one...");
      delay(200);
    }
  }
}