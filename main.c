#include <SDL2/SDL.h>
#include "window_handler.h"
#include "screen_helper.h"
#include "point_controller.h"

int main(int argc, char* args[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *pixel_renderer = NULL;

    initialize_window(
        &window, &pixel_renderer,
        "raytracer",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT);

    struct point_3d *camera_position = make_point_3d(0, 0, 0);
    for (int x = -(SCREEN_WIDTH/2), x < (SCREEN_WIDTH/2), x++) {
        for (int y = -(SCREEN_HEIGHT/2), y < (SCREEN_HEIGHT/2), y++) {
            struct point_3d *viewport_point = get_viewport_position(x, y);  // translate canvas coordinates to viewport coordinates
            struct rgb_color color = trace_ray(*camera_position, *viewport_position, 1, 100000);  // get the color at the intersection of the ray
            SDL_SetRenderDrawColor(pixel_renderer, color.r, color.g, color.b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

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
