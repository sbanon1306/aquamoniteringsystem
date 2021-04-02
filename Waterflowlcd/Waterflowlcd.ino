

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = A0;
void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Flow Meter");
lcd.setCursor(0,1);
lcd.print("****************");
delay(2000);
pinMode(input,INPUT);
}
void loop()
{

X = pulseIn(input, HIGH);
Y = pulseIn(input, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;
LS = WATER/60;
if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Speed:0.00");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
Serial.println(TOTAL);
lcd.print(TOTAL);
lcd.print("L");
}
else
{
TOTAL = TOTAL + LS;
Serial.println(FREQUENCY);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VOL.:");
lcd.print(WATER);
lcd.print(" L/M");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
lcd.print(TOTAL);
lcd.print("L");
}
}
  
delay(1000);
 
}
