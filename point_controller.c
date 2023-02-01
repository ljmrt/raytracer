#include <stdio.h>
#include <stdlib.h>
#include "point_controller.h"
#include "screen_helper.h"

struct point_3d *make_point_3d(float point_x, float point_y, float point_z)
{
    struct point_3d *made_point = (struct point_3d *)malloc(sizeof(struct point_3d));
    made_point->x = point_x;
    made_point->y = point_y;
    made_point->z = point_z;

    return made_point;
}

struct point_3d *get_viewport_position(float canvas_x, float canvas_y)
{
    float viewport_x = canvas_x * (VIEWPORT_WIDTH/SCREEN_WIDTH);
    float viewport_y = canvas_y * (VIEWPORT_HEIGHT/SCREEN_HEIGHT);
    float viewport_z = VIEWPORT_DISTANCE;
    return make_point_3d(viewport_x, viewport_y, viewport_z);
}

struct point_3d subtract_3d(struct point_3d point_1, struct point_3d point_2)
{
    return *make_point_3d((point_1.x - point_2.x), (point_1.y - point_2.y), (point_1.z - point_2.z));
}

float dot_product_3d(struct point_3d vector_1, struct point_3d vector_2)
{
    return (vector_1.x * vector_2.x) + (vector_1.y * vector_2.y) + (vector_1.z * vector_2.z);
}
