#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ray_handler.h"
#include "common.h"
#include "object_collection.h"
#include "light_handler.h"

struct rgb_color trace_ray(struct point_3d camera_position, struct point_3d ray_direction, float t_minimum, float t_maximum, int recursion_depth)
{
    float closest_t = t_maximum;
    struct sphere_object closest_sphere;
    closest_sphere.radius = 0;
    int found = closest_intersection(camera_position, ray_direction, t_minimum, t_maximum, &closest_t, &closest_sphere);

    if (!found) {
        return common.BACKGROUND_COLOR;
    }

    struct point_3d point = add_3d(camera_position, multiply_point(ray_direction, closest_t));  // compute intersection
    struct point_3d point_normal = subtract_3d(point, closest_sphere.center);  // compute sphere normal at intersection
    point_normal = divide_point(point_normal, vector_length(point_normal));

    struct point_3d opposite_direction = multiply_point(ray_direction, -1);

    float light_intensity = compute_lighting(point, point_normal, opposite_direction, closest_sphere.specular);
    struct rgb_color local_color = multiply_color(closest_sphere.color, light_intensity);
    
    float sphere_reflective = closest_sphere.reflective;
    if (recursion_depth <= 0 || sphere_reflective <= 0) {
        return local_color;
    }

    struct point_3d reflected_ray = reflect_ray(opposite_direction, point_normal);
    struct rgb_color reflected_color = trace_ray(point, reflected_ray, 0.001, INFINITY, --recursion_depth);

    return add_color(multiply_color(local_color, (1 - sphere_reflective)), multiply_color(reflected_color, sphere_reflective));
}

void ray_intersects(struct point_3d O, struct point_3d D, struct sphere_object sphere, float *t1, float *t2)
{
    int sphere_radius = sphere.radius;
    struct point_3d CO = subtract_3d(O, sphere.center);

    float a = dot_product_vector(D, D);
    float b = 2 * dot_product_vector(CO, D);
    float c = dot_product_vector(CO, CO) - (sphere_radius * sphere_radius);

    float discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        *t1 = INFINITY;
        *t2 = INFINITY;
        return;
    }

   *t1 = (-b + sqrt(discriminant)) / (2 * a);
   *t2 = (-b - sqrt(discriminant)) / (2 * a);
}

int closest_intersection(struct point_3d camera_position, struct point_3d ray_direction, float t_minimum, float t_maximum, float *closest_t, struct sphere_object *closest_sphere)
{
    struct sphere_object *scene_head = fetch_scene_head();
    int found = 0;
    while (scene_head != NULL) {
        float t1, t2;
        t1 = t2 = 0;
        ray_intersects(camera_position, ray_direction, *scene_head, &t1, &t2);
        
        if (t1 >= t_minimum && t1 <= t_maximum && t1 < *closest_t) {
            *closest_t = t1;
            *closest_sphere = *scene_head;
            found = 1;
        }
        if (t2 >= t_minimum && t2 <= t_maximum && t2 < *closest_t) {
            *closest_t = t2;
            *closest_sphere = *scene_head;
            found = 1;
        }

        scene_head = scene_head->next_object;
    }
    return found;
}

struct point_3d reflect_ray(struct point_3d target_vector, struct point_3d target_normal)
{
    return subtract_3d(multiply_point(target_normal, 2 * dot_product_vector(target_vector, target_normal)), target_vector);
}
