#include <stdlib.h>
#include <SDL2/SDL.h>
#include "window_handler.h"
#include "common.h"
#include "point_controller.h"
#include "ray_handler.h"
#include "light_handler.h"

int main(int argc, char* args[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *pixel_renderer = NULL;

    initialize_window(
        &window, &pixel_renderer,
        "raytracer",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        common.SCREEN_WIDTH, common.SCREEN_HEIGHT);

    // replace unneeded arguments with NULL?
    struct light *light_1 = make_light(0, 0.2, *make_point_3d(0, 0, 0));  // ambient light
    struct light *light_2 = make_light(1, 0.6, *make_point_3d(2, 1, 0));  // point light
    struct light *light_3 = make_light(2, 0.2, *make_point_3d(1, 4, 4));  // directional light
    insert_light(&light_1);
    insert_light(&light_2);
    insert_light(&light_3);

    // struct sphere_object *sphere_1 = make_sphere(*make_point_3d(0, -1, 3), 1, *make_rgb_color(255, 0, 0));
    struct sphere_object *sphere_1 = create_sphere(0, -1, 3, 1, 255, 0, 0);
    // struct sphere_object *sphere_2 = make_sphere(*make_point_3d(2, 0, 4), 1, *make_rgb_color(0, 0, 255));
    struct sphere_object *sphere_2 = create_sphere(2, 0, 4, 1, 0, 0, 255);
    // struct sphere_object *sphere_3 = make_sphere(*make_point_3d(-2, 0, 4), 1, *make_rgb_color(0, 255, 0));
    struct sphere_object *sphere_3 = create_sphere(-2, 0, 4, 1, 0, 255, 0);
    // struct sphere_object *sphere_4 = make_sphere(*make_point_3d(0, -5001, 0), 5000, *make_rgb_color(255, 255, 0));
    struct sphere_object *sphere_4 = create_sphere(0, -5001, 0, 5000, 255, 255, 0);
    // insert_sphere(&sphere_1);
    // insert_sphere(&sphere_2);
    // insert_sphere(&sphere_3);
    // insert_sphere(&sphere_4);

    struct point_3d *camera_position = make_point_3d(0, 0, 0);
    // iterate through each pixel
    for (int x = -(common.SCREEN_WIDTH/2); x < (common.SCREEN_WIDTH/2); x++) {
        for (int y = -(common.SCREEN_HEIGHT/2); y < (common.SCREEN_HEIGHT/2); y++) {
            struct point_3d *direction = get_viewport_position(x, y);  // translate canvas coordinates to viewport coordinates
            struct rgb_color color = trace_ray(*camera_position, *direction, 1, 10000000);  // get the color at the intersection of the ray
            SDL_SetRenderDrawColor(pixel_renderer, color.r, color.g, color.b, 255);

            // TODO: remove this translation
            int translated_x = (common.SCREEN_WIDTH/2) + x;
            int translated_y = (common.SCREEN_HEIGHT/2) - y;
            SDL_RenderDrawPoint(pixel_renderer, translated_x, translated_y);

            free(direction);
        }
    }

    SDL_RenderPresent(pixel_renderer);

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

    // TODO: move to function
    free(camera_position);
    free(sphere_1);
    free(sphere_2);
    free(sphere_3);
    free(sphere_4);
    free(light_1);
    free(light_2);
    free(light_3);

    return 0;
}
