#include <stdlib.h>
#include "point_controller.h"
#include "screen_helper.h"

struct 3d_point *make_3d_point(int point_x, int point_y, int point_z)
{
    struct 3d_point *made_point = (struct 3d_point *)malloc(sizeof(struct 3d_point));
    made_point->x = point_x;
    made_point->y = point_y;
    made_point->z = point_z;

    return made_point;
}

struct 3d_point *get_viewport_position(int canvas_x, int canvas_y)
{
    int viewport_x = canvas_x * (VIEWPORT_WIDTH/SCREEN_WIDTH);
    int viewport_y = canvas_y * (VIEWPORT_HEIGHT/SCREEN_HEIGHT);
    int viewport_z = VIEWPORT_DISTANCE;
    return make_3d_point(viewport_x, viewport_y, viewport_z);
}
