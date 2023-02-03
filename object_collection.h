#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H

#include "point_controller.h"
#include "color_helper.h"

struct sphere_object {
    struct point_3d center;  // center point of the sphere
    int radius;  // radius of the sphere
    struct rgb_color color;  // color of the sphere in rgb
    struct sphere_object *next_object;  // next object in linked list
};

// make a sphere object using the supplied arguments
//
// @param sphere_center center point of the made sphere
// @param sphere_radius radius of the made sphere
// @param sphere_color color of the made sphere in rgb
// @return made sphere object
struct sphere_object *make_sphere(struct point_3d sphere_center, int sphere_radius, struct rgb_color sphere_color);

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

// make a sphere object and insert it into the scene linked list with the provided arguments
//
// @param sphere_center_x sphere center point x 
// @param sphere_center_y sphere center point y 
// @param sphere_center_z sphere center point z 
// @param sphere_radius radius of the sphere
// @param sphere_r red intensity of sphere
// @param sphere_g green intensity of sphere
// @param sphere_b blue intensity of sphere
// @return pointer to sphere object
struct sphere_object *create_sphere(float sphere_center_x, float sphere_center_y, float sphere_center_z, int sphere_radius, int sphere_r, int sphere_g, int sphere_b);
    
#endif  // OBJECT_COLLECTION_H
