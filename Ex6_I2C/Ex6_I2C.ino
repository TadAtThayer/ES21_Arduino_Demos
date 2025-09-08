#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define BUTTON 6

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R2, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C

// U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C

void setup(void) {
  u8g2.begin();
  pinMode( BUTTON, INPUT );
}

void loop(void) {
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");    // write something to the internal memory  
  
  if ( digitalRead( BUTTON ) ) {
    u8g2.drawStr(0,20,"(Button Released)");
  } else {
    u8g2.drawStr(0,20,"(Button Pressed)");   
  }
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(100);  
}
