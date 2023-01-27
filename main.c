#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>

#define WINDOW_WIDTH 640  // window width
#define WINDOW_HEIGHT 480  //window height

int main(int argc, char* args[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *pixel_renderer = NULL;

    int init_result = SDL_Init(SDL_INIT_VIDEO);
    if (init_result < 0) {
        printf("sdl initialization error: %s\n", SDL_GetError());
        goto MAIN_END;
    }

    window = SDL_CreateWindow("raytracer",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, 
        SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("window creation error: %s\n", SDL_GetError());
        goto MAIN_END;
    }

    pixel_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (pixel_renderer == NULL) {
        printf("renderer creation error: %s\n", SDL_GetError());
        goto MAIN_END;
    }

    SDL_SetRenderDrawColor(pixel_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(pixel_renderer);
    SDL_RenderPresent(pixel_renderer);

    // keep the window up
    SDL_Event poll_event;
    while (1 < 2) {
        SDL_PollEvent(&poll_event);  // poll for key presses 
        // if quit key pressed
        if (poll_event.key.keysym.sym == SDLK_ESCAPE) {
            break;
        }
    }

    MAIN_END:
        if (window != NULL) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();

        return 0;
}
