#include "point_controller.h"
#include "color_helper.h"
#include "object_collection.h"

// compute the intersection of a ray with objects in the scene
//
// @param camera_position position of the camera in 3d space
// @param ray_direction direction of the ray
// @param t_minimum minimum amount that the trace can advance by
// @param t_maximum maximum amount that the trace can advance by
// @param recursion_depth the depth to recur in reflections
// @return rgb color of the intersection
struct rgb_color trace_ray(struct point_3d camera_position, struct point_3d ray_direction, float t_minimum, float t_maximum, int recursion_depth);

// solve quadratic equation for if a ray intersects with a sphere
//
// @param O position of the camera in 3d space
// @param D direction of the ray
// @param sphere sphere to test intersections with
// @param t1 first solution to quadratic equation
// @param t2 second solution to quadratic equation
void ray_intersects(struct point_3d O, struct point_3d D, struct sphere_object sphere, float *t1, float *t2);

// find the closest intersection of a ray with a sphere
//
// @param camera_position position of the camera in 3d space
// @param ray_direction direction of the ray
// @param t_minimum the minimum t can be
// @param t_maximum the maximum t can be
// @param closest_t used to return the closest t
// @param closest_sphere used to return the closest sphere
// @return if a sphere was found
int closest_intersection(struct point_3d camera_position, struct point_3d ray_direction, float t_minimum, float t_maximum, float *closest_t, struct sphere_object *closest_sphere);

// compute the reflection of target_direction in respect to target_normal
//
// @param target_vector the vector to use in calculations
// @param target_normal the normal to use in calculations
// @return reflection
struct point_3d reflect_ray(struct point_3d target_vector, struct point_3d target_normal);
