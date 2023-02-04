#include <stdio.h>
#include <stdlib.h>
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

float compute_lighting(struct point_3d target_point, struct point_3d target_normal)
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

        float normal_light_product = dot_product_vector(target_normal, light_vector);
        if (normal_light_product > 0) {
            light_intensity += index->intensity * (normal_light_product / (vector_length(target_normal) * vector_length(light_vector)));
        }

        index = index->next_light;
    }

    return light_intensity;
}
