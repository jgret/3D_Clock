#include <Adafruit_NeoPixel.h>
#include <RTClib.h>

#define PIN 2 // input pin Neopixel is attached to
#define NUMPIXELS 58  // number of neopixels in strip
   
#define SEG_0 0       // leds before SEG_0   
#define SEG_1 13      // leds before SEG_1   ((1 * 7) * 2) - 1
#define SEG_2 29      // leds before SEG_2   ((2 * 7) * 2) - 1 + 2
#define SEG_3 43      // leds before SEG_3   ((3 * 7) * 2) - 1 + 2

//   SEG:  
//     0     1     2     3
//    ---   ---   ---   --- 
//   |   | |   | |   | |   |
//    ---   ---   ---   --- 
//   |   | |   | |   | |   |
//    ---   ---   ---   --- 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
RTC_DS3231 rtc;

void setup()
{
  Serial.begin(9600);

  // Initialize the NeoPixel library
  pixels.begin();
 
  if (!rtc.begin())
  {
    Serial.println("No RTC found");
    while (1);
  }

  if (!rtc.lostPower())
  {
    Serial.println("RTC has low Power");
    // Set Time
    while (1);
  }
}

void loop()
{
  //read clock time from rtc
  DateTime now = rtc.now();
  int hour;
  if (now.isPM()) 
  {
    hour = now.hour() + 12;
  } else {
    hour = now.hour();
  }
  int min = now.minute();

  //display time on segments
  clearSegments();
  displayTime(hour, min);

  //update Clock
  pixels.show();
  delay(1000);
}

void clearSegments()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, 0);
  }
}

//    7-Segment LEDs
//   
//             6/7
//          ---- ----
//         |         |
//     8/9 |         | 4/5
//         |         |
//          ---- ----
//         |   2/3   |
//   10/11 |         | 0/1
//         |         |
//          ---- ----
//            12/13 

void displayTime(int hour, int min) {
  displayNum(SEG_0, hour / 10, 255, 0, 0);
  displayNum(SEG_1, hour % 10, 255, 0, 0);
  displayNum(SEG_2, min / 10, 255, 0, 0);
  displayNum(SEG_3, min % 10, 255, 0, 0);
}

void displayNum(int segoff, int num, int r, int g, int b)
{
  uint32_t color = pixels.Color(r, g, b);

  switch (num)
  {

  case 0:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
     
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
     
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);
     
    pixels.setPixelColor(segoff + 10, color);
    pixels.setPixelColor(segoff + 11, color);
   
    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 1:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
    break;

  case 2: 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
 
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
 
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);

    pixels.setPixelColor(segoff + 10, color);
    pixels.setPixelColor(segoff + 11, color);

    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 3:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
 
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
 
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);

    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 4:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
 
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
 
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);
    break;

  case 5:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
 
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
 
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);
    
    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 6:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
 
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
     
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
     
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);
    
    pixels.setPixelColor(segoff + 10, color);
    pixels.setPixelColor(segoff + 11, color);
    
    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 7:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
     
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
     
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
    break;

  case 8:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
     
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
     
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
         
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
     
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);
    
    pixels.setPixelColor(segoff + 10, color);
    pixels.setPixelColor(segoff + 11, color);
    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;

  case 9:
    pixels.setPixelColor(segoff + 0,  color);
    pixels.setPixelColor(segoff + 1,  color);
     
    pixels.setPixelColor(segoff + 2,  color);
    pixels.setPixelColor(segoff + 3,  color);
     
    pixels.setPixelColor(segoff + 4,  color);
    pixels.setPixelColor(segoff + 5,  color);
         
    pixels.setPixelColor(segoff + 6,  color);
    pixels.setPixelColor(segoff + 7,  color);
     
    pixels.setPixelColor(segoff + 8,  color);
    pixels.setPixelColor(segoff + 9,  color);

    pixels.setPixelColor(segoff + 12, color);
    pixels.setPixelColor(segoff + 13, color);
    break;
  }
}