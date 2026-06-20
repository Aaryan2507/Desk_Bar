#include <LiquidCrystal_I2C.h>
 #define outputA 6 //CLK
 #define outputB 7 //DT
 int counter = 0; 
 int aState;
 int aLastState;  
#include <Wire.h>
uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t note[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrow[8] = {  0x1,0x1,0x5,0x9,0x1f,0x8,0x4};
LiquidCrystal_I2C lcd(0x27,16,2);
 void setup() { 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   lcd.createChar(0, bell);
  lcd.createChar(1, note);
   lcd.home();
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 const char* messages[] = {
  "Message 0",
  "Message 5",
  "Message 10",
  "Message 15",
  "Message 20",
  "Message 25",
  "Message 30"
};
void update_LCD(int counter){
  int group=counter/5;
  group=constrain(group,0,6);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(messages[group]);
}
 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
     update_LCD(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
