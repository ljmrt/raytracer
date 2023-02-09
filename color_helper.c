#include <stdlib.h>
#include "color_helper.h"
#include "common.h"

struct rgb_color *make_rgb_color(float red, float green, float blue)
{
    struct rgb_color *made_struct = (struct rgb_color *)malloc(sizeof(struct rgb_color));
    made_struct->r = red;
    made_struct->g = green;
    made_struct->b = blue;

    return made_struct;
}

struct rgb_color add_color(struct rgb_color color_1, struct rgb_color color_2)
{
    return *make_rgb_color((color_1.r + color_2.r), (color_1.g + color_2.g), (color_1.b + color_2.b));
}

struct rgb_color multiply_color(struct rgb_color color, float constant)
{
    return *make_rgb_color((color.r * constant), (color.g * constant), (color.b * constant));
}

void clamp_color(struct rgb_color *target_color)
{
    int rgb_minimum = 0; 
    int rgb_maximum = 255;
    target_color->r = common_clamp(target_color->r, rgb_minimum, rgb_maximum);
    target_color->g = common_clamp(target_color->g, rgb_minimum, rgb_maximum);
    target_color->b = common_clamp(target_color->b, rgb_minimum, rgb_maximum);
}
