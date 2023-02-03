#ifndef COMMON_H
#define COMMON_H

#include "color_helper.h"

struct client {
    float SCREEN_WIDTH;
    float SCREEN_HEIGHT;
    float VIEWPORT_WIDTH;
    float VIEWPORT_HEIGHT;
    float VIEWPORT_DISTANCE;
    struct rgb_color BACKGROUND_COLOR;
};
// initialize client struct
static struct client common = {
    .SCREEN_WIDTH = 480,
    .SCREEN_HEIGHT = 480,
    .VIEWPORT_WIDTH = 1,
    .VIEWPORT_HEIGHT = 1,
    .VIEWPORT_DISTANCE = 1,
    .BACKGROUND_COLOR = {.r = 255, .b = 255, .g = 255},
};  // TODO: implement common struct handler functions

#endif  // COMMON_H
