#include "point_controller.h"
#include "color_helper.h"
#include "object_collection.h"

// compute the intersection of a ray with objects in the scene
//
// @param camera_position position of the camera in 3d space
// @param viewport_distance distance of the viewport away from the camera
// @param advance_minimum minimum amount that the trace can advance by
// @param advance_maximum maximum amount that the trace can advance by
// @return rgb color of the intersection
struct rgb_color trace_ray(struct point_3d camera_position, int viewport_distance, int advance_minimum, int advance_maximum);

// solve quadratic equation for if a ray intersects with a sphere
//
// @param O position of the camera in 3d space
// @param D distance of the viewport away from the camera
// @param sphere sphere to test intersections with
// @param t1 first solution to quadratic equation
// @param t2 second solution to quadratic equation
void ray_intersects(struct point_3d O, int D, struct sphere_object sphere, int *t1, int *t2);
