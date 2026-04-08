#include <HX711.h>
#include <LiquidCrystal.h>
#include <VirtualWire.h>
#include <Wire.h> 

#define TX_Pin 3

char *controller;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 10, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

HX711 scale(9, 6); //HX711 scale(6, 5);

float calibration_factor = 550;
float units;
float ounces;

void setup()
{
  Serial.begin(9600);
  Serial.println("TRIP LEVEL INDICATOR");
  vw_set_tx_pin(TX_Pin);
  vw_setup(2000);// speed of data transfer Kbps
  pinMode(13,OUTPUT);
  pinMode(8, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("TRIP LEVEL");
  lcd.setCursor(0,1);
  lcd.print("INDICATOR");
  delay(1100);
  lcd.clear();
  scale.set_scale(calibration_factor);
  scale.tare();
}

void loop()
{
  units = scale.get_units(),10;
  if (units < 0)
  {
    units = 0.00;
  }
  ounces = units * 0.035274;
if (units <=135) {
  controller="1" ;
  vw_send((uint8_t *)controller,strlen(controller));
  vw_wait_tx(); 
  digitalWrite(13,1);
  delay(100);
  Serial.print("CHECK ME...");
  Serial.println(units);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CHECK ME...");
  lcd.setCursor(0,1);
  lcd.print(units);
  lcd.print("g");
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8,LOW);
  delay(500);
  }
else  {
  controller="0" ;
  vw_send((uint8_t *)controller,strlen(controller));
  vw_wait_tx();
  digitalWrite(13,0);
  delay(100);
  Serial.print("Measured Weight");
  Serial.println(units);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measured Weight");
  lcd.setCursor(0,1);
  lcd.print(units);
  lcd.print("g");
  delay(500);
  digitalWrite(8,LOW);
  }
}
