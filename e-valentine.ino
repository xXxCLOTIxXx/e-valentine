/**************************************************************************
YouTube channel about programming.
https://www.youtube.com/@Xsarzy
 **************************************************************************/
 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>
#include <string.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//images
static const unsigned char PROGMEM logo_bmp[] =
{
	0x00, 0x00, 0x0c, 0x60, 0x0e, 0xe0, 0x0e, 0xe0, 0x7f, 0xfc, 0x7f, 0xfc, 0x3f, 0xf8, 0x0f, 0xe0, 
	0x3f, 0xf8, 0x7f, 0xfc, 0x7f, 0xfc, 0x0e, 0xe0, 0x0e, 0xe0, 0x0c, 0x60, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char PROGMEM main_bmp[] =
{
	0xff, 0xff, 0xff, 0xff, 0xc1, 0x83, 0x8c, 0x31, 0x1c, 0x78, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
	0x80, 0x01, 0xc0, 0x01, 0xc0, 0x03, 0xe0, 0x07, 0xf8, 0x0f, 0xfc, 0x3f, 0xff, 0x7f, 0xff, 0xff
};




#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

void first(void) {
  display.drawBitmap((display.width()  - LOGO_WIDTH ) / 2, (display.height() - LOGO_HEIGHT) / 2, logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.setTextSize(0.8);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, LOGO_HEIGHT/2 + 35);
  display.println(F("Happy Valentine's Day"));
  display.display();
  return;
}




void second(){
  display.drawBitmap((display.width()  - LOGO_WIDTH ) / 2, (display.height() - LOGO_HEIGHT) / 2, main_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.setCursor(LOGO_WIDTH/2 + 20, LOGO_HEIGHT/2 + 35);
  display.println(F("I love you <3"));
  display.display();
}


//main

void setup()   {   
  //Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
}



void loop(){
    display.invertDisplay(true);
    first();
    delay(3000);
    display.invertDisplay(false);
    display.clearDisplay();
    second();
    delay(3000);
    display.clearDisplay();
}


