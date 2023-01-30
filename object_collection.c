#include "object_collection.h"

struct sphere_object *head_object = NULL;

struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color)
{
    struct sphere_object *made_sphere = (struct sphere_object *)malloc(sizeof(sphere_object));
    made_sphere->center = sphere_center;  // possibly incorrect?
    made_sphere->radius = sphere_radius;
    made_sphere->color = sphere_color;  // possibly incorrect?
    made_sphere->next_sphere = NULL;

    return made_sphere;
}

struct sphere_object *insert_sphere(struct sphere_object **node)
{

}

void remove_sphere(struct sphere_object *node) 
{

}
