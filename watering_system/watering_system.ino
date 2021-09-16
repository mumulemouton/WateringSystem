#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int wet = 653;
const int dry = 953;
int K3 = 7;
int K4 = 6;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(K3, OUTPUT);
  pinMode(K4, OUTPUT);
  digitalWrite(K3, HIGH);
  digitalWrite(K4, HIGH);
  delay(1000);
}
void loop() {
  int bazylia = map(analogRead(0), wet, dry, 100, 0);
  int mieta = map(analogRead(1), wet, dry, 100, 0);
  if (bazylia < 70) {
    digitalWrite(K3, LOW);
  } else {
    digitalWrite(K3, HIGH); 
  }
if (mieta < 70) {
    digitalWrite(K4, LOW);
  } else {
    digitalWrite(K4, HIGH);
  }
lcd.init();
lcd.backlight();
lcd.clear();
lcd.setCursor(0,0);
delay(1000);
bazylia = map(analogRead(0), wet, dry, 100, 0);
mieta = map(analogRead(1), wet, dry, 100, 0);
if(bazylia >= 100)
bazylia = 100;
if(mieta >= 100)
mieta = 100;
delay(100);
lcd.print("bazylia: ");
lcd.print(bazylia);
lcd.print("%");
Serial.print("bazylia: ");
Serial.print(bazylia);
Serial.print("%   ");
lcd.setCursor(0,1);
lcd.print("mieta: ");
lcd.print(mieta);
lcd.print("%");
Serial.print("mieta: ");
Serial.print(mieta);
Serial.print("%\n");
delay(2000);
lcd.clear();
}
 
