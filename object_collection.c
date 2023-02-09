#include <stdlib.h>
#include "object_collection.h"
#include "color_helper.h"
#include "point_controller.h"

struct sphere_object *head_object = NULL;

struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color, int sphere_specular, float sphere_reflective)
{
    struct sphere_object *made_sphere = (struct sphere_object *)malloc(sizeof(struct sphere_object));
    made_sphere->center = sphere_center;
    made_sphere->radius = sphere_radius;
    made_sphere->color = sphere_color;
    made_sphere->specular = sphere_specular;
    made_sphere->reflective = sphere_reflective;
    made_sphere->next_object = NULL;

    return made_sphere;
}

void insert_sphere(struct sphere_object **node)
{
    (*node)->next_object = head_object;
    head_object = *node;
}

void remove_sphere(struct sphere_object **node) 
{
    struct sphere_object *index = head_object;
    // iterate through linked list
    while (index->next_object != *node) {
        if (index->next_object == NULL) break;
        index = index->next_object;
    }
    index->next_object = (*node)->next_object;

    free(*node);
}

struct sphere_object *fetch_scene_head()
{
    return head_object;
}
