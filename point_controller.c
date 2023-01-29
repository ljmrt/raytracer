#include <stdlib.h>
#include "point_controller.h"
#include "screen_helper.h"

struct point_3d *make_point_3d(int point_x, int point_y, int point_z)
{
    struct point_3d *made_point = (struct point_3d *)malloc(sizeof(struct point_3d));
    made_point->x = point_x;
    made_point->y = point_y;
    made_point->z = point_z;

    return made_point;
}

struct point_3d *get_viewport_position(int canvas_x, int canvas_y)
{
    int viewport_x = canvas_x * (VIEWPORT_WIDTH/SCREEN_WIDTH);
    int viewport_y = canvas_y * (VIEWPORT_HEIGHT/SCREEN_HEIGHT);
    int viewport_z = VIEWPORT_DISTANCE;
    return make_point_3d(viewport_x, viewport_y, viewport_z);
}
