#include <Keypad.h>
#define kled 16
#define yled 17
#define sifre_uzunlugu 5

char sifre[sifre_uzunlugu] = "1234";
char girilenSifre[sifre_uzunlugu];
int i = 0;

const byte satir = 4;
const byte sutun = 3;

char tus_takimi[satir][sutun] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

char tus;

byte satir_pinleri[satir] = {10,9,8,7};
byte sutun_pinleri[sutun] = {13,12,11};

Keypad tuslarim = Keypad(makeKeymap(tus_takimi),satir_pinleri,sutun_pinleri,satir,sutun);

void setup()
{
  pinMode(kled,OUTPUT);
  pinMode(yled,OUTPUT);
  Serial3.begin(9600);
  digitalWrite(kled,0);
  digitalWrite(yled,0);
}

void loop()
{
  tus = tuslarim.getKey();
  if(tus)
  {
    girilenSifre[i++] = tus;
    Serial3.println(tus);
    delay(100);
  }
  if(i == 4)
  {
    char sifremiz[sifre_uzunlugu] = "1234";
    if((strncmp(girilenSifre,sifremiz,5) == 0))
    {
      digitalWrite(kled,0);
      digitalWrite(yled,1);
      delay(200);
        i = 0;
    }
    else
    {
      digitalWrite(kled,1);
      digitalWrite(yled,0);
      delay(200);
      i = 0;
    }
  }
}
