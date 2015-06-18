#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "sdl.hpp"
#include "../color.hpp"


int main(int argc, char *argv[]) {
    sdl_init_simulation();

    // Init sleep time
    struct timespec sleep_time;
    sleep_time.tv_sec  = 0;
    sleep_time.tv_nsec = 5000000;

    int led = 0;

    // The colors
    uint8_t rgb[3];


    while(1) {
        // SDL close event
        SDL_Event event; 
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
                return 0;
        }

        nanosleep(&sleep_time, NULL);
 
        ColorWheel(scaleValueToByte(led, LED_COUNT), rgb);

        set_led(PackColor(rgb[0],rgb[1],rgb[2]), led);
        led++;
    }
 
    return 0;
}




