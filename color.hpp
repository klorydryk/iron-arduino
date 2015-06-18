#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdint.h>

void ColorWheel(int WheelPos, uint8_t rgb[3]);

int scaleValueToByte(int value, int max);
uint32_t PackColor(uint8_t r, uint8_t g, uint8_t b);

#endif