# 1 "d:\\prog\\arduino\\TheCoolerClock\\TheCoolerClock.ino"
# 2 "d:\\prog\\arduino\\TheCoolerClock\\TheCoolerClock.ino" 2
# 3 "d:\\prog\\arduino\\TheCoolerClock\\TheCoolerClock.ino" 2
# 13 "d:\\prog\\arduino\\TheCoolerClock\\TheCoolerClock.ino"
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(58 /* number of neopixels in strip*/, 2 /* input pin Neopixel is attached to*/, ((1<<6) | (1<<4) | (0<<2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);
RTC_DS3231 rtc;

int delayval = 1000; // timing delay in milliseconds

int redColor = 255;
int greenColor = 0;
int blueColor = 0;

//pinMode(2, OUTPUT);

void setup()
{

  Serial.begin(9600);

  // Initialize the NeoPixel library.
  pixels.begin();
  clearSegments();
  pixels.show();

  // Serial.println("Hello World");

  // if (!rtc.begin()) {
  //   Serial.println("No RTC found");
  //   while (1);
  // }

  // if (!rtc.lostPower()) {
  //   Serial.println("DRECK");
  //   while (1);
  // }

}

void loop()
{

  for (int i = 0; i < 58 /* number of neopixels in strip*/; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
  delay(10);

    for (int i = 0; i < 58 /* number of neopixels in strip*/; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
  delay(10);

    for (int i = 0; i < 58 /* number of neopixels in strip*/; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }
  pixels.show();
  delay(10);

}

void clearSegments()
{
  for (int i = 0; i < 58 /* number of neopixels in strip*/; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}

void setSegments(int hour, int min)
{
}

void displayNum(int segoff, int num, int r, int g, int b)
{

  switch (num)
  {

  case 0:
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 5, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 1:
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    break;

  case 2:
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 5, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 3:
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 4:
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    break;

  case 5:
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 6:
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 5, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 7:
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    break;

  case 8:
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 5, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;

  case 9:
    pixels.setPixelColor(segoff + 0, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 1, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 2, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 3, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 4, pixels.Color(r, g, b));
    pixels.setPixelColor(segoff + 6, pixels.Color(r, g, b));
    break;
  }
}

// setColor()
// picks random values to set for RGB
void setColor()
{
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
}
