struct rgb_color {
    int r;  // intensity of red
    int b;  // intensity of blue
    int g;  // intensity of green
};

// TODO: background color struct

// make a rgb color struct
//
// @param red intensity of red
// @param blue intensity of blue
// @param green intensity of green
// @return made rgb color struct pointer

struct rgb_color *make_rgb_color(int red, int blue, int green);
