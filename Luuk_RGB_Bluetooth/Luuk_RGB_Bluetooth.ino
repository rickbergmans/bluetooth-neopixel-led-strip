//  Control WS2812b light strip with iPhone or Android app
//
//  iPhone app URL: https://itunes.apple.com/gb/app/hm10-bluetooth-serial/id1030454675?mt=8
//
//  Android app URL: https://play.google.com/store/apps/details?id=project.bluetoothterminal&hl=en

#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

SoftwareSerial BT(10, 11);  // TX, RX of the Bluetooth Module

#define PIXEL_PIN      6    // Data Pin of Led strip 
#define PIXEL_COUNT    118   // Number of LEDs in the strip
#define BRIGHTNESS     255    // use 96 for medium brightness
#define SPEED          50    // Speed of each Color Transition (in ms)
#define IMMEDIATELY    0    // Transition happen instantly
#define RAINBOW_SPEED  1    // Rainbow Transition speed

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool offOld = LOW;
bool WhiteOld = LOW;
bool RedOld = LOW;
bool GreenOld = LOW;
bool BlueOld = LOW;
bool TopazOld = LOW;
bool LilacOld = LOW;
bool RainbowOld = LOW;
bool rgbOld = LOW;
bool rainbowLongOld = LOW;
bool strobeEffectOld = LOW;
int  showType = 0;
int  loops = 1;

//  VOID SETUP

void setup() {

  BT.begin(9600);

  BT.println("Connected to Arduino");


  strip.setBrightness(BRIGHTNESS);


  strip.begin();
  strip.show();
}

char a;

//  VOID LOOP

void loop() {

  bool off = LOW;
  bool White = LOW;
  bool Blue = LOW;
  bool Red = LOW;
  bool Green = LOW;
  bool Topaz = LOW;
  bool Lilac = LOW;
  bool Rainbow = LOW;
  bool rainbowLong = LOW;
  bool rgb = LOW;
  bool strobeEffect = LOW;
  bool end;

  //BLUETOOTH INPUT LOGIC

  if (BT.available())
  {
    a = (char)BT.read();


    if (a == 'o')
    {
      off = HIGH;
      BT.println("TURNING OFF LEDs..");

    } else {
      off = LOW;
    }

    // ===========================================================================================

    if (a == 'w')
    {
      White = HIGH;
      BT.println("TURNING LEDs WHITE");

    } else {
      White = LOW;
    }

    // ===========================================================================================

    if (a == 'b')
    {
      Blue = HIGH;
      BT.println("CHANGING TO BLUE");

    } else {
      Blue = LOW;
    }

    // ===========================================================================================

    if (a == 'r')
    {
      Red = HIGH;
      BT.println("CHANGING TO RED");
    } else {
      Red = LOW;
    }

    // ===========================================================================================

    if (a == 'g')
    {
      Green = HIGH;
      BT.println("CHANGING TO GREEN");

    } else {
      Green = LOW;
    }

    // ===========================================================================================

    if (a == 't')
    {
      Topaz = HIGH;
      BT.println("CHANGING TO TOPAZ");

    } else {
      Topaz = LOW;
    }

    // ===========================================================================================

    if (a == 'l')
    {
      Lilac = HIGH;
      BT.println("CHANGING TO LILAC");

    } else {
      Lilac = LOW;
    }

    // ===========================================================================================

    if (a == 'a')
    {
      Rainbow = HIGH;
      BT.println("RAINBOW ANIMATION");

    } else {
      Rainbow = LOW;
    }

    // ===========================================================================================

    if (a == 'm')
    {
      rgb = HIGH;
      BT.println("MIX COLORS");

    } else {
      rgb = LOW;
    }

    // ===========================================================================================

    if (a == 's')
    {
      rainbowLong = HIGH;
      BT.println("RAINBOW LONG");

    } else {
      rainbowLong = LOW;
    }
    // ===========================================================================================

    if (a == 'c')
    {
      strobeEffect = HIGH;
      BT.println("STROBE");

    } else {
      strobeEffect = LOW;
    }

    // ===========================================================================================

    if (a == '1')
    {
      BT.println("LOW");
      showType = 11;                            // Low brightness
      startShow(showType);
    }

    if (a == '2')
    {
      BT.println("MIDDLE");
      showType = 12;                            // Middle brightness
      startShow(showType);
    }


    if (a == '3')
    {
      BT.println("HIGH");
      showType = 13;                            //  High brightness
      startShow(showType);
    }

    if (a == 'x')
    {
      BT.println("HIGH");
      loops = 0.3;
      startShow(showType);
    }

    if (a == 'y')
    {
      BT.println("HIGH");
      loops = 3;
    }

    if (a == 'z')
    {
      BT.println("HIGH");
      loops = 5;
    }

  }

  // ===========================================================================================
  //  SHOWTYPE START LOGIC


  if (off == LOW && offOld == HIGH) {
    delay(20);


    if (off == LOW) {
      showType = 0  ;                            // Off animation Type 0

      startShow(showType);
    }
  }

  // ===========================================================================================

  if (White == LOW && WhiteOld == HIGH) {
    delay(20);


    if (White == LOW) {
      showType = 1  ;                            // White animation Type 1

      startShow(showType);
    }
  }


  // ===========================================================================================

  if (Red == LOW && RedOld == HIGH) {
    delay(20);


    if (Red == LOW) {
      showType = 2  ;                            // Red animation Type 2

      startShow(showType);
    }
  }

  // ===========================================================================================

  if (Green == LOW && GreenOld == HIGH) {
    delay(20);


    if (Green == LOW) {
      showType = 3  ;                            // Green animation Type 3

      startShow(showType);
    }
  }

  // ===========================================================================================

  if (Blue == LOW && BlueOld == HIGH) {
    delay(20);


    if (Blue == LOW) {
      showType = 4  ;                            // Blue animation Type 4

      startShow(showType);
    }
  }

  // ===========================================================================================

  if (Topaz == LOW && TopazOld == HIGH) {
    delay(20);


    if (Topaz == LOW) {
      showType = 5  ;                            // Topaz animation Type 5

      startShow(showType);
    }
  }

  // ===========================================================================================

  if (Lilac == LOW && LilacOld == HIGH) {
    delay(20);


    if (Lilac == LOW) {
      showType = 6  ;                            // Topaz animation Type 6

      startShow(showType);
    }
  }

  // ===========================================================================================


  if (Rainbow == LOW && RainbowOld == HIGH) {
    delay(20);

    if (Rainbow == LOW) {
      showType = 8;                            // Rainbow animation Type 8
      startShow(showType);
    }
  }

  // ===========================================================================================

  if (rainbowLong == LOW && rainbowLongOld == HIGH) {
    delay(20);

    if (rainbowLong == LOW) {
      showType = 9;                            // Rainbow animation Type 9
      startShow(showType);
    }
  }

  // ===========================================================================================

  if (strobeEffect == LOW && strobeEffectOld == HIGH) {
    delay(20);

    if (strobeEffect == LOW) {
      showType = 10;                            // Rainbow animation Type 10
      startShow(showType);
    }
  }

  // ===========================================================================================

  if (rgb == LOW && rgbOld == HIGH) {
    delay(20);

    if (rgb == LOW) {
      showType = 7;                            // Mix animation Type 7
      rgb = HIGH;

      startShow(showType);
    }
  }

  // ===========================================================================================

  //  TURNING SHOW OFF

  WhiteOld = White;
  RedOld = Red;
  BlueOld = Blue;
  GreenOld = Green;
  TopazOld = Topaz;
  LilacOld = Lilac;
  offOld = off;
  RainbowOld = Rainbow;
  rainbowLongOld = rainbowLong;
  strobeEffectOld = strobeEffect;
  rgbOld = rgb;

}

//  ANIMATION SWITCH WITH STARTSHOW FUNCTION

void startShow(int i) {
  switch (i) {

    case 0: colorWipe(strip.Color(0, 0, 0), SPEED);    // Black/off
      break;

    case 1: colorWipe(strip.Color(255, 255, 255), SPEED);  // White
      break;

    case 2: colorWipe(strip.Color(255, 0, 0), SPEED);  // Red
      break;

    case 3: colorWipe(strip.Color(0, 255, 0), SPEED);  // Green
      break;

    case 4: colorWipe(strip.Color(0, 0, 255), SPEED);  // Blue
      break;

    case 5: colorWipe(strip.Color(0, 250, 255), SPEED);  // Topaz
      break;

    case 6: colorWipe(strip.Color(144, 0, 255), SPEED);  // Lilac
      break;

    case 7: theaterChase(strip.Color(0, 250, 255), SPEED); // Topaz
      theaterChase(strip.Color(144, 0, 255), SPEED); // Lilac
      theaterChase(strip.Color(255, 215, 0), SPEED); // Orange
      break;

    case 8: rainbowCycle(loops);
      break;

    case 9: rainbowCycleLong(loops);
      break;

    case 10: Strobe(0xdf, 0xff, 0xfe, 10, 50, 1000);
      break;

    case 11: strip.setBrightness(20);
      break;

    case 12: strip.setBrightness(90);
      break;

    case 13: strip.setBrightness(255);
      break;
  }
}

// ANIMATIONS

//  ANIMATION #1 - COLOR WIPE

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

//  ANIMATION #2 - RAINBOW COLORS

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 10; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//  ANIMATION #3 - RAINBOW COLORS LONG VERSION

void rainbowCycleLong(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 150; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//  ANIMATION #3 - THEATER CHASE

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// ANIMATION #4 - STROBE EFFECT

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    strip.show();
    delay(FlashDelay);
    setAll(0, 0, 0);
    strip.show();
    delay(FlashDelay);
  }

  delay(EndPause);
}

// Set a LED color (not yet visible)
void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < PIXEL_COUNT; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}

//  COLOR WHEEL

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
