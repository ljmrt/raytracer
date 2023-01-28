#include <stdlib.h>
#include "color_helper.h"

struct rgb_color *make_rgb_color(int red, int green, int blue)
{
    struct rgb_color *made_struct = (struct rgb_color *)malloc(sizeof(struct rgb_color));
    made_struct->r = red;
    made_struct->g = green;
    made_struct->b = blue;

    return made_struct;
}
