#include "point_controller.h"

struct light {
    int id;  // id = 0: ambient, id = 1: point, id = 2: directional
    float intensity;  // all the intensities of lights must add up to 1
    struct point_3d position;  // position for point lights, or direction for directional lights
    struct light *next_light;  // next light in the lights linked list
};

// make a light using the supplied arguments
//
// @param light_id type of the made light
// @param light_intensity intensity of the made light
// @param light_position position of the made light
// @return made light
struct light *make_light(int light_id, float light_intensity, struct point_3d light_position);

// insert light into lights linked list
// inserts at head
//
// @param node light to insert into lights linked list
void insert_light(struct light **node);

// remove(and free) a light from the lights linked list
//
// @param node light to remove from the lights linked list
void remove_light(struct light **node);

// fetch the head of the lights linked list
//
// @return head of lights linked list
struct light *fetch_lights_head();

// compute the intensity of light at a point
// uses diffuse illumination 
//
// @param target_point targeted point to use in calculations
// @param target_normal normal of the targeted point to use in calculations
// @param view_vector vector pointing from object to camera
// @param target_specular specularity of the target object
// @return intensity of light at point
float compute_lighting(struct point_3d target_point, struct point_3d target_normal, struct point_3d view_vector, int target_specular);
