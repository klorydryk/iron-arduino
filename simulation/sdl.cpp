#include <math.h>

#include "sdl.hpp"
SDL_Surface *surface;

int sdl_init_simulation() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return 1;

    atexit(SDL_Quit);

    surface = SDL_SetVideoMode(SCREEN_SIZE, SCREEN_SIZE, 0, SDL_DOUBLEBUF);

    if (surface == NULL)
        return 2;
}


void set_pixel(int x, int y, Uint32 pixel) {
    Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
    *(Uint32 *)target_pixel = pixel;
}


void set_led(Uint32 pixel, int led) {
    SDL_LockSurface(surface);

    float angle     = (TWOPI/LED_COUNT) * (led  ),
          angleStop = (TWOPI/LED_COUNT) * (led+1);

    float xpos, ypos;
    float angle_inc=1.0f/(SCREEN_SIZE/2);

    for(; angle<=angleStop;angle+=angle_inc){
        xpos=SCREEN_SIZE/2+SCREEN_SIZE/2*cos(angle);
        ypos=SCREEN_SIZE/2+SCREEN_SIZE/2*sin(angle);
        set_pixel(xpos,ypos,pixel);
    }


    SDL_FreeSurface(surface);
    SDL_Flip(surface);
}
