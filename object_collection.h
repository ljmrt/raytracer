#include "point_controller.h"
#include "color_helper.h"

struct sphere_object {
    struct point_3d center;  // center point of the sphere
    int radius;  // radius of the sphere
    struct rgb_color color;  // color of the sphere in rgb
    struct sphere_object *next_sphere;  // linked list next entry
}

// make a sphere object using the supplied arguments
//
// @param sphere_center center point of the made sphere
// @param sphere_radius radius of the made sphere
// @param sphere_color color of the made sphere in rgb
// @return made sphere object
struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color);

// TODO: insert and remove sphere entry functions
