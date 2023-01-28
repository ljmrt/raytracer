struct rgb_color {
    int r;
    int b;
    int g;
}

// TODO: background color struct

// make a rgb color struct
//
// @param red intensity of red
// @param blue intensity of blue
// @param green intensity of green
// @return made rgb color struct pointer

struct rgb_color *make_rgb_color(int red, int blue, int green);
