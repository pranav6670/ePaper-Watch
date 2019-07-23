#include <Arduino.h>
#include<ESP8266WiFi.h>
#include "thermo.h"
#include "press.h"
#include "hum.h"
#include "ht.h"
#include "watch_square.h"
#include <U8g2lib.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Geometry.h>

#include "DHT.h"
#include <Adafruit_NeoPixel.h>
#include "RTClib.h"
#include "watchface.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define DHTTYPE DHT11
#define DHTPIN D3

U8G2_SSD1607_200X200_F_4W_SW_SPI u8g2(U8G2_R3, /* clock=*/ D5, /* data=*/ D7, /* cs=*/ D8, /* dc=*/ D6);  // eInk/ePaper Display
Adafruit_BMP085 bmp;
DHT dht(DHTPIN, DHTTYPE);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(3, D4, NEO_GRB + NEO_KHZ800);
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  pinMode(D4, INPUT);
  u8g2.initDisplay();
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  dht.begin();
  //  pixels.begin();
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    //    rtc.adjust(DateTime(2018, 9, 03, 01, 0 , 4));

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}
uint8_t counter = 0;
void loop() {
  u8g2.setPowerSave(0);  // before drawing, enable charge pump (req. 300ms)
  DateTime now = rtc.now();
  u8g2.firstPage();
  int btnstate = digitalRead(D0);
  if (btnstate == HIGH) {
    //    delay(125);
    counter++;
    counter %= 9;
    Serial.print(counter);
  }
  do {
    switch (counter) {
      case 0:
        test_logo();
        colorDisp(60, 0, 0);
        break;
      case 1:
        u8g2.setFont(u8g2_font_7Segments_26x42_mn);
        u8g2.drawStr(20, 120, String(now.hour()).c_str());
        u8g2.drawStr(80, 120, ":");
        u8g2.drawStr(110, 120, String(now.minute()).c_str());
        u8g2.setFont(u8g2_font_inb21_mf);
        u8g2.drawStr(20, 160, String(daysOfTheWeek[now.dayOfTheWeek()]).c_str());
        u8g2.setFont(u8g2_font_inr24_mn);
        u8g2.drawStr(20, 50, String(now.day()).c_str());
        u8g2.drawStr(40, 50, "/");
        u8g2.drawStr(60, 50, String(now.month()).c_str());
        u8g2.drawStr(80, 50, "/");
        u8g2.drawStr(100, 50, String(now.year()).c_str());
        colorDisp(0, 60, 0);
        //        u8g2.clearBuffer();
        break;
      case 2:
        u8g2.setFont(u8g2_font_inr24_mf);
        u8g2.drawXBM(76, 24, 80, 80, test_bits);
        u8g2.drawStr(20, 160, String(bmp.readPressure()).c_str());
        u8g2.drawStr(100, 160, " Pa ");
        colorDisp(0, 0, 60);
        //        u8g2.clearBuffer();
        break;
      case 3:
        u8g2.setFont(u8g2_font_inr21_mf);
        u8g2.drawStr(20, 60, "ALTITUDE:- ");
        u8g2.drawStr(10, 140, String(bmp.readAltitude()).c_str());
        u8g2.drawStr(50, 180, " meters ");
        colorDisp(60, 60, 0);
        //        u8g2.clearBuffer();
        break;
      case 4:
        u8g2.setFont(u8g2_font_profont29_tf);
        u8g2.drawXBM(76, 24, 48, 48, thermo_bits);
        u8g2.drawStr(10, 100, "Temperature");
        u8g2.setFont(u8g2_font_inr21_mf);
        u8g2.drawStr(20, 150, String(bmp.readTemperature()).c_str());
        u8g2.drawStr(120, 150, " *C ");
        u8g2.drawStr(20, 180, String(dht.readTemperature(true)).c_str());
        u8g2.drawStr(120, 180, " *F ");
        colorDisp(0, 60, 60);
        //        u8g2.clearBuffer();
        break;
      case 5:
        u8g2.setFont(u8g2_font_inr21_mf);
        u8g2.drawXBM(20, 20, 113, 113, hum_bits);
        u8g2.drawStr(20, 180, String(dht.readHumidity()).c_str());
        u8g2.drawStr(140, 180, " % ");
        colorDisp(60, 0, 60);
        //        u8g2.clearBuffer();
        break;
      case 6:
        u8g2.setFont(u8g2_font_inr21_mf);
        u8g2.drawXBM(20, 20, 113, 113, ht2_bits);
        u8g2.drawStr(20, 160, String(dht.computeHeatIndex(dht.readTemperature(true), dht.readHumidity())).c_str());
        u8g2.drawStr(120, 160, " *F ");
        u8g2.drawStr(20, 190, String(dht.computeHeatIndex(dht.readTemperature(), dht.readHumidity(), false)).c_str());
        u8g2.drawStr(120, 190, " *C ");
        colorDisp(60, 60, 60);
        //        u8g2.clearBuffer();
        break;
      case 7:
        drawWatchFace(face_bits);
        colorDisp(60, 60, 60);
        //        u8g2.clearBuffer();
        break;
      case 8:
        drawWatchFace(facesquare_bits);
        break;
    }
  } while (u8g2.nextPage());
  //  delay(100);
}

void test_logo() {
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawGlyph(5, 20, 0x2603);
  u8g2.drawGlyph(180, 20, 0x2603);
  u8g2.drawGlyph(5, 180, 0x2603);
  u8g2.drawGlyph(180, 180, 0x2603);

  u8g2.setFont(u8g2_font_osr41_tf);
  u8g2.drawStr(20, 60, "Hey,");
  u8g2.drawStr(40, 120, "look");
  u8g2.drawStr(60, 160, "at");
  u8g2.drawStr(80, 200, "me");
  //  u8g2.drawStr(20, 20,);



}
void colorDisp(int x, int y, int z) {
  for (int i = 0; i < 3; i++) {
    pixels.setPixelColor(i, pixels.Color(x, y, z));
    pixels.show();
  }
}
void drawHandle(float width, float length, float div, Rotation r, Point c) {
  Point p0, p1, p2, p3;
  p0.X() = 0;
  p0.Y() = 0;

  p1.X() = -width / 2;
  p1.Y() = -length * div;

  p2.X() = width / 2;
  p2.Y() = -length * div;

  p3.X() = 0;
  p3.Y() = -length;

  p0 = r * p0 + c;
  p1 = r * p1 + c;
  p2 = r * p2 + c;
  p3 = r * p3 + c;

  u8g2.drawLine(p0.X(), p0.Y(), p1.X(), p1.Y());
  u8g2.drawLine(p0.X(), p0.Y(), p2.X(), p2.Y());
  u8g2.drawLine(p3.X(), p3.Y(), p1.X(), p1.Y());
  u8g2.drawLine(p3.X(), p3.Y(), p2.X(), p2.Y());
}

void drawWatchFace(const uint8_t *bits) {
  DateTime now = rtc.now();

  Point c;
  c.X() = 100;
  c.Y() = 100;

  Rotation rh, rm;
  rh.RotateZ(2 * PI *
             (((now.hour() > 12 ? now.hour() - 12 : now.hour()) / 12.0) +
              (now.minute() / 60.0) / 12.0));
  rm.RotateZ(2 * PI * (now.minute() / 60.0));

  u8g2.drawXBM(0, 0, 200, 200, bits);
  u8g2.setFont(u8g2_font_fub14_tn);
  u8g2.drawStr(
    134, 107,
    String(String(now.day() < 9 ? " " : "") + String(now.day())).c_str());

  for (int i = 0; i < 9; i++) {
    drawHandle(i, 50, 0.6, rh, c);
  }

  for (int i = 0; i < 5; i++) {
    drawHandle(i, 75, 0.4, rm, c);
  }
}

