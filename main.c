#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640  // window width
#define SCREEN_HEIGHT 480  //window height

int main(int argc, char* args[]) {
    SDL_Window *window = NULL;
    SDL_Surface *screen_surface = NULL;

    int init_result = SDL_Init(SDL_INIT_VIDEO);
    if (init_result < 0) goto SDL_ERROR;

    window = SDL_CreateWindow("raytracer",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN);
    if (window == NULL) goto SDL_ERROR;

    screen_surface = SDL_GetWindowSurface(window);

    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));  //fill the window surface white
    SDL_UpdateWindowSurface(window);

    // keep the window up
    SDL_Event poll_event;
    int quit = 0;
    while (!quit) {
        int poll_result = SDL_PollEvent(&poll_event);  // poll for key presses 
        // if quit key pressed
        if (poll_result && poll_event.type == SDL_QUIT) {
            quit = 1;
        }
    }

    SDL_DestroyWindow(window);

    SDL_ERROR:
        printf("sdl error: %s\n", SDL_GetError());

    SDL_Quit();

    return 0;
}
