#include <stdlib.h>
#include "object_collection.h"
#include "color_helper.h"
#include "point_controller.h"

struct sphere_object *head_object = NULL;

struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color)
{
    struct sphere_object *made_sphere = (struct sphere_object *)malloc(sizeof(struct sphere_object));
    made_sphere->center = sphere_center;
    made_sphere->radius = sphere_radius;
    made_sphere->color = sphere_color;
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
        if (index->next_object == NULL) {
            break;
        }
        index = index->next_object;
    }
    index->next_object = (*node)->next_object;

    free(*node);
}

struct sphere_object *fetch_scene_head()
{
    return head_object;
}

struct sphere_object *create_sphere(float sphere_center_x, float sphere_center_y, float sphere_center_z, int sphere_radius, int sphere_r, int sphere_g, int sphere_b)
{
    struct rgb_color *sphere_color = make_rgb_color(sphere_r, sphere_g, sphere_b);
    struct point_3d *sphere_center = make_point_3d(sphere_center_x, sphere_center_y, sphere_center_z);

    struct sphere_object *created_sphere = make_sphere(*sphere_center, sphere_radius, *sphere_color);
    
    free(sphere_color);
    free(sphere_center);

    insert_sphere(&created_sphere);
    return created_sphere;
}
