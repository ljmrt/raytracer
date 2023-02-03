#ifndef COLOR_HELPER_H
#define COLOR_HELPER_H

struct rgb_color {
    int r;  // intensity of red
    int b;  // intensity of blue
    int g;  // intensity of green
};

// make a rgb color struct
//
// @param red intensity of red
// @param blue intensity of blue
// @param green intensity of green
// @return made rgb color struct pointer
struct rgb_color *make_rgb_color(int red, int blue, int green);

// get the product of a color and a constant
//
// @param color color to be multiplied
// @param constant constant to multiply the color by
// @return product
struct rgb_color multiply_color(struct rgb_color color, float constant);

#endif  // COLOR_HELPER_H
