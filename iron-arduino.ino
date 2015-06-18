#include <Adafruit_NeoPixel.h>
#include <math.h>

#define ENCODER_DO_NOT_USE_INTERRUPTS // in case of Arduino NANO for example (without interrupt)
#include <Encoder.h>

#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS   24

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Limits of brightness
#define MIN_ALPHA 15
#define MAX_ALPHA 100

float alpha; // Current value of the pixels

int cycle = 0;

// Start color, red~0, green~85, blue~170
#define StartColor 150
int colorValue = StartColor; // New Color management value
uint8_t rgb[3];

// Encoder management
Encoder myEnc(2, 3);
long oldPosition  = -999;

void setup() {
    Serial.begin(9600);
    Serial.println("Basic Encoder Test:");

    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    long newPosition = myEnc.read();
    if (newPosition != oldPosition)
    {
        oldPosition = newPosition;
        Serial.println(newPosition);

        ColorWheel(newPosition, rgb);
    }

    breath(6);
}

void breath(uint16_t breathLength) // cycle in second
{
    float breathDivisor = 8*breathLength;
    alpha = 0.5 + 0.5*sin(cycle++/breathDivisor);

//Serial.println(alpha);

//    colorWipe(strip.Color(100, 150, 255));
    colorWipe(strip.Color(rgb[0],rgb[1],rgb[2]));
    strip.setBrightness(MIN_ALPHA + (MAX_ALPHA-MIN_ALPHA)*alpha);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c) {
    for(uint16_t i=0; i<strip.numPixels(); i++)
        strip.setPixelColor(i, c);

    strip.show();
}

