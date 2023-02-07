#ifndef COLOR_HELPER_H
#define COLOR_HELPER_H

struct rgb_color {
    float r;  // intensity of red
    float b;  // intensity of blue
    float g;  // intensity of green
};

// make a rgb color struct
//
// @param red intensity of red
// @param blue intensity of blue
// @param green intensity of green
// @return made rgb color struct pointer
struct rgb_color *make_rgb_color(float red, float blue, float green);

// get the product of a color and a constant
//
// @param color color to be multiplied
// @param constant constant to multiply the color by
// @return product
struct rgb_color multiply_color(struct rgb_color color, float constant);

// clamp the color between 0-255 to prevent color errors
//
// @param color color to clamp(gets modified)
void clamp_color(struct rgb_color *color);

#endif  // COLOR_HELPER_H
