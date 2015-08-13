#include <math.h>
#include <Adafruit_NeoPixel.h>

#define ENCODER_DO_NOT_USE_INTERRUPTS // in case of Arduino NANO for example (without interrupt)
#include <Encoder.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
#define PIN 6
#define NUMPIXELS   24
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Limits of brightness
#define MIN_ALPHA 20
#define MAX_ALPHA 100

uint8_t rgb[3];

// Encoder management
Encoder myEnc(2, 3);
long oldPosition  = -999;

int decallage = 0;
void setup() {
    Serial.begin(9600);
    Serial.println("Basic Encoder Test:");

    strip.begin();
    strip.show(); // Initialize all pixels to 'off'

    strip.setBrightness(MIN_ALPHA);
    lcd_setup();
  
}

void loop() {
    lcd_decale(0);
    decallage+=(20+10*getSpeedCycleValue());
    decallage%=255*24; //sinon il y a un léger dépassement…
    /*long newPosition = myEnc.read();
    if (newPosition != oldPosition)
    {
        oldPosition = newPosition;
        Serial.println(newPosition);

        ColorWheel(newPosition, rgb);
    }

    breath(6);*/
    ArcEnCiel(decallage);
    //breath(10);

}

int cycleSpeed = 0;
const int cycleSpeedLength = 8;
float getSpeedCycleValue() {
    float breathDivisor = 8*cycleSpeedLength;
    return sin(cycleSpeed++/breathDivisor);
}
