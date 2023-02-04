#include <stdlib.h>
#include "color_helper.h"

struct rgb_color *make_rgb_color(float red, float green, float blue)
{
    struct rgb_color *made_struct = (struct rgb_color *)malloc(sizeof(struct rgb_color));
    made_struct->r = red;
    made_struct->g = green;
    made_struct->b = blue;

    return made_struct;
}

struct rgb_color multiply_color(struct rgb_color color, float constant)
{
    return *make_rgb_color((color.r * constant), (color.g * constant), (color.b * constant));
}
