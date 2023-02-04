#include "point_controller.h"
#include "color_helper.h"
#include "object_collection.h"

// compute the intersection of a ray with objects in the scene
//
// @param camera_position position of the camera in 3d space
// @param ray_direction direction of the ray
// @param advance_minimum minimum amount that the trace can advance by
// @param advance_maximum maximum amount that the trace can advance by
// @return rgb color of the intersection
struct rgb_color trace_ray(struct point_3d camera_position, struct point_3d ray_direction, float advance_minimum, float advance_maximum);

// solve quadratic equation for if a ray intersects with a sphere
//
// @param O position of the camera in 3d space
// @param D direction of the ray
// @param sphere sphere to test intersections with
// @param t1 first solution to quadratic equation
// @param t2 second solution to quadratic equation
void ray_intersects(struct point_3d O, struct point_3d D, struct sphere_object sphere, float *t1, float *t2);
