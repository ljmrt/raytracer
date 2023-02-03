#include <stdlib.h>
#include <math.h>
#include "point_controller.h"
#include "common.h"

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
    float viewport_x = canvas_x * (common.VIEWPORT_WIDTH/common.SCREEN_WIDTH);
    float viewport_y = canvas_y * (common.VIEWPORT_HEIGHT/common.SCREEN_HEIGHT);
    float viewport_z = common.VIEWPORT_DISTANCE;
    return make_point_3d(viewport_x, viewport_y, viewport_z);
}

struct point_3d add_3d(struct point_3d point_1, struct point_3d point_2)
{
    return *make_point_3d((point_1.x + point_2.x), (point_1.y + point_2.y), (point_1.z + point_2.z));
}

struct point_3d subtract_3d(struct point_3d point_1, struct point_3d point_2)
{
    return *make_point_3d((point_1.x - point_2.x), (point_1.y - point_2.y), (point_1.z - point_2.z));
}

struct point_3d multiply_point(struct point_3d point, float constant)
{
    return *make_point_3d((point.x * constant), (point.y * constant), (point.z * constant));
}

struct point_3d divide_point(struct point_3d point, float constant)
{
    return *make_point_3d((point.x / constant), (point.y / constant), (point.z / constant));
}

float dot_product_vector(struct point_3d vector_1, struct point_3d vector_2)
{
    return (vector_1.x * vector_2.x) + (vector_1.y * vector_2.y) + (vector_1.z * vector_2.z);
}

float vector_length(struct point_3d target_vector)
{
    return sqrt(dot_product_vector(target_vector, target_vector));
}
