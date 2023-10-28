#ifndef VEC_MATH_H
#define VEC_MATH_H 1

typedef struct {
    int x;
    int y;
} vec2i;

/// @brief  Adds two vectors together
/// @param a The first vector 
/// @param b The second vector
/// @return The sum of the two vectors
vec2i v2iadd(vec2i a, vec2i b);

/// @brief  Subtracts two vectors
/// @param a The first vector
/// @param b The second vector
/// @return  The difference of the two vectors
vec2i v2isub(vec2i a, vec2i b);


#endif