#include "vmath.h"

vec2i v2iadd(vec2i a, vec2i b)
{
    return (vec2i){a.x + b.x, a.y + b.y};
}

vec2i v2isub(vec2i a, vec2i b)
{
    return (vec2i){a.x - b.x, a.y - b.y};
}