#include <stdlib.h>
#include <math.h>
#include "ray_handler.h"
#include "object_collection.h"

struct rgb_color trace_ray(struct point_3d camera_position, struct point_3d ray_direction, int advance_minimum, int advance_maximum)
{
    int closest_intersect = advance_maximum;
    struct sphere_object closest_sphere;

    struct sphere_object *scene_head = fetch_scene_head();
    while (scene_head != NULL) {
        int intersect1, intersect2;
        ray_intersects(camera_position, ray_direction, *scene_head, &intersect1, &intersect2);
        
        if (intersect1 >= advance_minimum && intersect1 <= advance_maximum && intersect1 < closest_intersect) {
            closest_intersect = intersect1;
            closest_sphere = *scene_head;
        }
        if (intersect2 >= advance_minimum && intersect2 <= advance_maximum && intersect2 < closest_intersect) {
            closest_intersect = intersect1;
            closest_sphere = *scene_head;
        }

        scene_head = scene_head->next_object;
    }

    // sphere hasn't changed
    if (closest_sphere.radius == 0) {
        // return background color
    }
    return closest_sphere.color;
}

void ray_intersects(struct point_3d O, struct point_3d D, struct sphere_object sphere, int *t1, int *t2)
{
    int sphere_radius = sphere.radius;
    struct point_3d CO = subtract_3d(O, sphere.center);

    int a = dot_product_3d(D, D);
    int b = 2 * dot_product_3d(CO, D);
    int c = dot_product_3d(CO, CO) - (sphere_radius * sphere_radius);

    int discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        *t1 = 10000000;  // TODO: implement global large number instead of inf.
        *t2 = 10000000;
        return;
    }

   *t1 = (-b + sqrt(discriminant)) / (2 * a);
   *t2 = (-b - sqrt(discriminant)) / (2 * a);
}
