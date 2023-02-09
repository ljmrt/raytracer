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
    .BACKGROUND_COLOR = {.r = 0, .b = 0, .g = 0},
};  // TODO: implement common struct handler functions

// commom math function, clamp
//
// @param target variable to clamp
// @param minimum minimum value that the variable can be
// @param maximum maximum value that the variable can be
float common_clamp(float target, float minimum, float maximum);

#endif  // COMMON_H
