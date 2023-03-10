#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H

#include "point_controller.h"
#include "color_helper.h"

struct sphere_object {
    struct point_3d center;  // center point of the sphere
    int radius;  // radius of the sphere
    struct rgb_color color;  // color of the sphere in rgb
    int specular;  // specularity of the sphere, -1 = matte
    float reflective;  // reflectivity of the sphere 0-1
    struct sphere_object *next_object;  // next object in linked list
};

// make a sphere object using the supplied arguments
//
// @param sphere_center center point of the made sphere
// @param sphere_radius radius of the made sphere
// @param sphere_color color of the made sphere in rgb
// @param sphere_specular specularity of the sphere
// @param sphere_reflective reflectivity of the sphere
// @return made sphere object
struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color, int sphere_specular, float sphere_reflective);

// TODO: implement generic scene linked list
// insert sphere into scene linked list(at head)
//
// @param node sphere to insert into scene linked list
void insert_sphere(struct sphere_object **node);

// remove(and free) a sphere from scene linked list
//
// @param node sphere to remove from scene linked list
void remove_sphere(struct sphere_object **node);

// fetch the head of the scene linked list
//
// @return head of the scene linked list
struct sphere_object *fetch_scene_head();
    
#endif  // OBJECT_COLLECTION_H
