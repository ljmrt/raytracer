#include <stdio.h>
#include "window_handler.h"

int initialize_window(SDL_Window **window, SDL_Renderer **renderer, char *window_name, int window_x, int window_y, int window_width, int window_height)
{
    int init_result = SDL_Init(SDL_INIT_VIDEO);
    if (init_result < 0) {
        printf("sdl initialization error: %s\n", SDL_GetError());
        return 1;
    }

    *window = SDL_CreateWindow(
        window_name,
        window_x, window_y,
        window_width, window_height, 
        SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("window creation error: %s\n", SDL_GetError());
        return 2;
    }

    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE);
    if (*renderer == NULL) {
        printf("renderer creation error: %s\n", SDL_GetError());
        return 3;
    }

    // fill window with white
    SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(*renderer);
    SDL_RenderPresent(*renderer);

    return 0;
}
