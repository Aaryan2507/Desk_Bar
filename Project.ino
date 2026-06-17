#include "Rencoder.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int outputA= 6;
int outputB= 7;
int aState;
int aLastState;
int counter=0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);
  Serial.begin(9600);
  aLastState=digitalRead(outputA);
}

void loop() {
  lcd.setCursor(0,0);
  int a=rencoder_out();
  lcd.print(a);
}
