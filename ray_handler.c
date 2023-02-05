#include <stdlib.h>
#include <math.h>
#include "ray_handler.h"
#include "common.h"
#include "object_collection.h"
#include "light_handler.h"

struct rgb_color trace_ray(struct point_3d camera_position, struct point_3d ray_direction, float advance_minimum, float advance_maximum)
{
    float closest_t = advance_maximum;
    struct sphere_object closest_sphere;
    int closest_sphere_changed = 0;

    struct sphere_object *scene_head = fetch_scene_head();
    while (scene_head != NULL) {
        float t1, t2;
        ray_intersects(camera_position, ray_direction, *scene_head, &t1, &t2);
        
        if (t1 >= advance_minimum && t1 <= advance_maximum && t1 < closest_t) {
            closest_t = t1;
            closest_sphere = *scene_head;
            closest_sphere_changed = 1;
        }
        if (t2 >= advance_minimum && t2 <= advance_maximum && t2 < closest_t) {
            closest_t = t2;
            closest_sphere = *scene_head;
            closest_sphere_changed = 1;
        }

        scene_head = scene_head->next_object;
    }

    // sphere hasn't changed
    if (closest_sphere_changed == 0) {
        return common.BACKGROUND_COLOR;
    }

    struct point_3d point = add_3d(camera_position, multiply_point(ray_direction, closest_t));  // compute intersection
    struct point_3d point_normal = subtract_3d(point, closest_sphere.center);  // compute sphere normal at intersection
    point_normal = divide_point(point_normal, vector_length(point_normal));

    float light_intensity = compute_lighting(point, point_normal, multiply_point(ray_direction, -1), closest_sphere.specular);

    return multiply_color(closest_sphere.color, light_intensity);
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
        *t1 = 10000000;
        *t2 = 10000000;
        return;
    }

   *t1 = (-b + sqrt(discriminant)) / (2 * a);
   *t2 = (-b - sqrt(discriminant)) / (2 * a);
}
