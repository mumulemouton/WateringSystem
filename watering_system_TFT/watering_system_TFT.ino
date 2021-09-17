#include <TFT.h>
#define cs 10
#define dc 8
#define rst 9
#define WHITE    0xFFFF
const int wet = 610;
const int dry = 950;
int K3 = 7;
int K4 = 6;
char bazyliaPrint[4];
char mietaPrint[4];
TFT TFTscreen = TFT(cs,  dc, rst);
void setup() {
Serial.begin(9600);
pinMode(K3, OUTPUT);
pinMode(K4, OUTPUT);
digitalWrite(K3, HIGH);
digitalWrite(K4, HIGH);
TFTscreen.begin();
TFTscreen.setRotation(3);
TFTscreen.background(255,255,255);
TFTscreen.stroke(0,0,0);
TFTscreen.setTextSize(2);
TFTscreen.setTextColor(WHITE);
TFTscreen.text("Bazylia:",10,50);
TFTscreen.text("Mieta:",10,70);
TFTscreen.text("%",140,50);
TFTscreen.text("%",140,70);
}

void loop() {
int bazylia = map(analogRead(0), wet, dry, 100, 0);
int mieta = map(analogRead(1), wet, dry, 100, 0);
Serial.print("bazylia: ");
Serial.print(bazylia);
Serial.print("%   ");
Serial.print("mieta: ");
Serial.print(mieta);
Serial.print("%\n");
String bazylia_s = String(bazylia);
String mieta_s = String(mieta);
bazylia_s.toCharArray(bazyliaPrint, 4);
mieta_s.toCharArray(mietaPrint, 4);
TFTscreen.stroke(0,0,0);
TFTscreen.text(bazyliaPrint,105,50);
TFTscreen.text(mietaPrint,105,70);
delay(250);
TFTscreen.stroke(255,255,255);
TFTscreen.text(bazyliaPrint,105,50);
TFTscreen.text(mietaPrint,105,70);
delay(1);
}
