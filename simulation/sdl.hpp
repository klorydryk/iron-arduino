#ifndef SDL_HPP
#define SDL_HPP

#include <SDL/SDL.h>


#define TWOPI 6.283f
#define SCREEN_SIZE 50
#define LED_COUNT  255

int sdl_init_simulation();

void set_led(Uint32 pixel, int led);

#endif