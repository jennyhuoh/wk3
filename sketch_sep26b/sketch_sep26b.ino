#include <Wire.h>  
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, 21, 22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(32,INPUT);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  // put your main code here, to run repeatedly:
    int rd;
    rd=analogRead(32);
    Serial.println(rd);
    rd=map(rd,0,4095,0,255);
    delay(7);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Read Value is");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 20, String(rd));
    display.display();
}
