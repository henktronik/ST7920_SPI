// (C)2019 Pawel A. Hernik

/*
 128x64 ST7920 connections in SPI mode (only 6 wires between LCD and MCU):

 #01 GND  -> GND
 #02 VCC  -> VCC (5V)
 #04 RS   -> D10/CS or any pin
 #05 R/W  -> D11/MOSI
 #06 E    -> D13/SCK
 #15 PSB  -> GND (for SPI mode)
 #19 BLA  -> D9, VCC or any pin via 300ohm resistor
 #20 BLK  -> GND
*/

#define LCD_BACKLIGHT  9
#define LCD_CS         10

#include "ST7920_SPI.h"
#include <SPI.h>
ST7920_SPI lcd(LCD_CS);

const uint8_t icon1 [] PROGMEM = { 16,16,
0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xDE, 0xCC, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80,
0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0x7B, 0x33, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01,
};

const uint8_t icon2 [] PROGMEM = { 16,16,
0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xCC, 0xDE, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80,
0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x33, 0x7B, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01,
};

const uint8_t icon3 [] PROGMEM = { 16,16,
0xFC, 0x0C, 0x14, 0x24, 0x44, 0x84, 0x04, 0x04, 0x04, 0x04, 0x84, 0x44, 0x24, 0x14, 0x0C, 0xFC,
0x3F, 0x30, 0x28, 0x24, 0x22, 0x21, 0x21, 0x22, 0x22, 0x21, 0x21, 0x22, 0x24, 0x28, 0x30, 0x3F,
};  
void setup() 
{
  Serial.begin(9600);
  pinMode(LCD_BACKLIGHT, OUTPUT);
  //analogWrite(LCD_BACKLIGHT,30);
  digitalWrite(LCD_BACKLIGHT, HIGH);
  SPI.begin();
  lcd.init();
  lcd.cls();
  lcd.drawBitmap(icon1,0,0);
  lcd.drawBitmap(icon2,24,0);
  lcd.drawBitmap(icon3,48,0);
  
  lcd.drawBitmap(icon1,0,16);
  lcd.drawBitmap(icon2,-1,16);
  lcd.drawBitmap(icon3,-2,16);
  lcd.drawBitmap(icon3,116,54);
  lcd.display(0);
  //lcd.copy(0,10,8,32,0);
}

void loop() 
{
}

