


void breath(uint16_t breathLength) // cycle in second
{
    float breathDivisor = 8*breathLength;
    alpha = 0.5 + 0.5*sin(cycle++/breathDivisor);

    strip.setBrightness(MIN_ALPHA + (MAX_ALPHA-MIN_ALPHA)*alpha);
    strip.show();
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c) {
    for(uint16_t i=0; i<strip.numPixels(); i++)
        strip.setPixelColor(i, c);

    strip.show();
}

void ArcEnCiel(int decalage_octet) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        int position = (255*i + decalage_octet)/NUMPIXELS;
        ColorWheel(position, rgb);
        strip.setPixelColor(i, strip.Color(rgb[0],rgb[1],rgb[2]));
    }
    strip.show();
}


int scaleValueToByte(int value, int max) {
    return (255*value)/max;
}

uint32_t PackColor(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
void ColorWheel(int WheelPos, uint8_t rgb[3]) {
    // Un calcul un peu bizarre pour toujours avoir une valeur positive
    // (-1 redonne 254, c'est pratique pour aller en arrière)
    WheelPos = (WheelPos % 255 + 255) % 255;
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        rgb[0] = 255 - WheelPos * 3;
        rgb[1] = 0;
        rgb[2] = WheelPos * 3;
    }
    else if(WheelPos < 170) {
        WheelPos -= 85;

        rgb[0] = 0;
        rgb[1] = WheelPos * 3;
        rgb[2] = 255 - WheelPos * 3;
    } else {
        WheelPos -= 170;

        rgb[0] = WheelPos * 3;
        rgb[1] = 255 - WheelPos * 3;
        rgb[2] = 0;
    }
}
