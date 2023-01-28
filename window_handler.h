#include <SDL2/SDL.h>

// create a blank(fully white) window
//
// @param window window context to create
// @param renderer renderer context to create
// @param window_name name of the window
// @param window_x x position of the window(screen coordinate system)
// @param window_y y position of the window(screen coordinate system)
// @param window_width width of the window
// @param window_height height of the window
// @return success
int initialize_window(SDL_Window **window, SDL_Renderer **renderer, char *window_name, int window_x, int window_y, int window_width, int window_height);
