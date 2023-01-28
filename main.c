#include <SDL2/SDL.h>
#include "window_handler.h"

#define WINDOW_WIDTH 640  // window width
#define WINDOW_HEIGHT 480  //window height

int main(int argc, char* args[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *pixel_renderer = NULL;

    initialize_window(
        &window, &pixel_renderer,
        "raytracer",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // keep the window up
    SDL_Event poll_event;
    while (1 < 2) {
        SDL_PollEvent(&poll_event);
        // if quit key pressed
        if (poll_event.key.keysym.sym == SDLK_ESCAPE) {
            break;
        }
    }

    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();

    return 0;
}
