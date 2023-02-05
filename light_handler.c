#include <stdlib.h>
#include <math.h>
#include "light_handler.h"
#include "point_controller.h"

struct light *head_light = NULL;

struct light *make_light(int light_id, float light_intensity, struct point_3d light_position)
{
    struct light *made_light = (struct light *)malloc(sizeof(struct light));
    made_light->id = light_id;
    made_light->intensity = light_intensity;
    made_light->position = light_position;
    made_light->next_light = NULL;

    return made_light;
}

void insert_light(struct light **node)
{
    (*node)->next_light = head_light;
    head_light = *node;
}

void remove_light(struct light **node)
{
    struct light *index = head_light;
    // iterate through linked list
    while (index->next_light != *node) {
        if (index->next_light == NULL) break;
        index = index->next_light;
    }
    index->next_light = (*node)->next_light;

    free(*node);
}

struct light *fetch_lights_head()
{
    return head_light;
}

float compute_lighting(struct point_3d target_point, struct point_3d target_normal, struct point_3d view_vector, int target_specular)
{
    float light_intensity = 0;

    struct light *index = head_light;
    // iterate through linked list
    while (index != NULL) {
        // if light is ambient
        if (index->id == 0) {
            light_intensity += index->intensity;
            
            index = index->next_light;
            continue;
        }

        struct point_3d light_vector;
        // if light is point
        if (index->id == 1) {
            light_vector = subtract_3d(index->position, target_point);
        } else {
            // light is direction
            // set light_vector to the light's direction
            light_vector = index->position;  // position member changes context depending on id
        }
        
        float normal_dot_light = dot_product_vector(target_normal, light_vector);

        // diffuse object
        if (normal_dot_light > 0) {
            light_intensity += index->intensity * (normal_dot_light / (vector_length(target_normal) * vector_length(light_vector)));
        }

        // specular object
        if (target_specular != -1) {
            struct point_3d reflected_ray = subtract_3d(multiply_point(target_normal, 2 * normal_dot_light), light_vector);
            int ray_dot_view = dot_product_vector(reflected_ray, view_vector);
            if (ray_dot_view > 0) {
                light_intensity += index->intensity * pow(ray_dot_view / (vector_length(reflected_ray) * vector_length(view_vector)), target_specular);
            }
        }

        index = index->next_light;
    }

    return light_intensity;
}
