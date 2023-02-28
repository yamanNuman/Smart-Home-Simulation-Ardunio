#include <Keypad.h>
#include <LiquidCrystal.h>

#define FlamePin A0
#define buzzer 18
#define lamp 19
#define sensor A1


float temp;
int val = 0;
int state = LOW;

LiquidCrystal lcd (1,0,5,4,3,2);

void setup()
{
  analogReference(INTERNAL1V1); //analog giriş için referans voltajı
  lcd.begin(20,4);//lcd ekran boyutu
  pinMode(lamp,OUTPUT); //lamba cıkıs olarak ayarlandı
  pinMode(sensor,INPUT); //sensor giris olarak
  pinMode(FlamePin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT); //cikis olarak ayarladik

  //Serial.begin(9600);

}

void loop()
{ 

  temp = analogRead(A2); //A2 analog pinindeki degeri okur.
  temp = temp*1100/(1024*10); //sicakligin celciusa cevirme
  lcd.print("TEMP:  "); //lcd ekrana yazdirma
  lcd.print(temp); //lcd ekrana yazdirma
  if(temp >= 30)
  {
    lcd.setCursor(0,1);
    lcd.println("Sicaklik Yukseldi.");
  }
  else if(temp <= 20)
  {
    lcd.setCursor(0,1);
    lcd.println("Sicaklik Dustu.");
  }
  delay(500);
  lcd.clear(); //ekran temizle
  
  
  
int Flame = digitalRead(FlamePin);

if(Flame==HIGH)
{
  digitalWrite(buzzer, HIGH);
  delay(200);
  
}
else
{
 digitalWrite(buzzer, LOW); 
}

  val = digitalRead(sensor); //0-5 volt arası yüksek mi düşük mü
  if(val == HIGH) //yuksek ise lamba yak
  {
    digitalWrite(lamp,HIGH);
    delay(200);
    if(state == LOW)
    {
      state=HIGH;
    }
  }
  else //dusukse lamba yakma
  {
    digitalWrite(lamp,LOW);
    delay(200);
    if(state=HIGH)
    {
      state = LOW;
    }
  }

}
