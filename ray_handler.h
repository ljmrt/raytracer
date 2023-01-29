#include "point_controller.h"
#include "color_helper.h"

// compute the intersection of a ray with objects in the scene
//
// @param camera_position position of the camera in 3d space
// @param viewport_distance distance of the viewport away from the camera
// @param advance_minimum minimum amount that the trace can advance by
// @param advance_maximum maximum amount that the trace can advance by
// @return rgb color of the intersection
struct rgb_color trace_ray(struct point_3d camera_position, int viewport_distance, int advance_minimum, int advance_maximum);

// TODO: function to compute the intersection of a ray and a object(sphere) returning the values of advance
