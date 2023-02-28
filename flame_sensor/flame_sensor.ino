#include <LiquidCrystal.h>

LiquidCrystal lcd(1,0,5,4,3,2);

#define FlamePin A8
#define buzzer 18

void setup() {
   lcd.begin(16, 2);
   pinMode(FlamePin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
    lcd.setCursor(5, 0);
    lcd.print("FLAME");
    lcd.setCursor(3, 1);
    lcd.print("DETECTOR");
    delay(1000);
    lcd.clear();
}

void loop() {

int Flame = digitalRead(FlamePin);

if(Flame==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(5, 0);
  lcd.print("FLAME");
   lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  delay(200);
  lcd.clear();
  delay(200);
  
}
else
{
 digitalWrite(buzzer, LOW); 
}
  

}
