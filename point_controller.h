struct 3d_point {
    int x;
    int y;
    int z;
}

// make(mallloc) 3d_point struct out of given arguments
//
// @param point_x x position to set
// @param point_y y position to set
// @param point_z z position to set
// @return made 3d_point struct pointer
struct 3d_point *make_3d_point(int point_x, int point_y, int point_z);

// get viewport position of pixel on canvas
//
// @param canvas_x x position of the point to convert
// @param canvas_y y position of the point to convert
// @return 3D point of viewport position pointer
struct 3d_point *get_viewport_position(int canvas_x, int canvas_y);
