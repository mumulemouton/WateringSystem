
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int wet = 653;
const int dry = 953;
int K3 = 7;
int K4 = 6;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(K3, OUTPUT);
  pinMode(K4, OUTPUT);
  digitalWrite(K3, HIGH);
  digitalWrite(K4, HIGH);
  delay(500);
}
void loop() {
lcd.setCursor(0,0);
lcd.print("bazylia: ");
int bazylia = map(analogRead(0), wet, dry, 100, 0);
lcd.print(bazylia);
lcd.print("%");
Serial.print("bazylia: ");
Serial.print(bazylia);
Serial.print("%   ");
lcd.setCursor(0,1);
lcd.print("mieta: ");
int mieta = map(analogRead(1), wet, dry, 100, 0);
lcd.print(mieta);
lcd.print("%");
Serial.print("mieta: ");
Serial.print(mieta);
Serial.print("%\n");
if (bazylia < 50) {
    digitalWrite(K3, LOW);
  } else {
    digitalWrite(K3, HIGH);
  }
if (mieta < 50) {
    digitalWrite(K4, LOW);
  } else {
    digitalWrite(K4, HIGH);
  }
delay(2000);
lcd.clear();
}
 
