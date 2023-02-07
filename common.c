#include "common.h"

float common_clamp(float target, float minimum, float maximum)
{
    float result = target > maximum ? maximum : target;
    return result < minimum ? minimum : result;
}
