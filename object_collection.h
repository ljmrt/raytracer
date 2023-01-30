#include "point_controller.h"
#include "color_helper.h"

struct sphere_object {
    struct point_3d center;  // center point of the sphere
    int radius;  // radius of the sphere
    struct rgb_color color;  // color of the sphere in rgb
    struct sphere_object *next_object;  // next object in linked list
}

// make a sphere object using the supplied arguments
//
// @param sphere_center center point of the made sphere
// @param sphere_radius radius of the made sphere
// @param sphere_color color of the made sphere in rgb
// @return made sphere object
struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color);

// TODO: implement generic scene linked list
// insert sphere into linked list
//
// @param node sphere to insert into scene linked list
// @return pointer to node in scene linked list
struct sphere_object *insert_sphere(struct sphere_object **node);

// remove(and free) a sphere from scene linked list
//
// @param node sphere to remove from scene linked list
void remove_sphere(struct sphere_object *node);
