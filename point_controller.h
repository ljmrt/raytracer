#ifndef POINT_CONTROLLER_H
#define POINT_CONTROLLER_H

struct point_3d {
    float x;  // x position of point
    float y;  // y position of point
    float z;  // z position of point
};

// make(mallloc) point_3d struct out of given arguments
//
// @param point_x x position to set
// @param point_y y position to set
// @param point_z z position to set
// @return made point_3d struct pointer
struct point_3d *make_point_3d(float point_x, float point_y, float point_z);

// get viewport position of pixel on canvas
//
// @param canvas_x x position of the point to convert
// @param canvas_y y position of the point to convert
// @return 3D point of viewport position pointer
struct point_3d *get_viewport_position(float canvas_x, float canvas_y);

// get the difference of two 3d points
//
// @param point_1 the first point to use
// @param point_2 the second point to use
// @return difference
struct point_3d subtract_3d(struct point_3d point_1, struct point_3d point_2);

// get the dot product of two 3d points
//
// @param vector_1 the first vector to use
// @param vector_2 the second vector to use
// @return dot product
float dot_product_3d(struct point_3d vector_1, struct point_3d vector_2);

#endif  // POINT_CONTROLLER_H
