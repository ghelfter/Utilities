/*  ============== Galen Helfter ==============  */
/*  ==============   Vector3.c   ==============  */

#include <math.h>

#include "Vector3.h"

void vector3_init(struct vector3 *vec)
{
    vec->x = 0.0;
    vec->y = 0.0;
    vec->z = 0.0;
}

struct vector3 vector3_add(struct vector3 *v1, struct vector3 *v2)
{
    struct vector3 result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;

    return result;
}

struct vector3 vector3_sub(struct vector3 *v1, struct vector3 *v2)
{
    struct vector3 result;
    result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    result.z = v1->z - v2->z;

    return result;
}

struct vector3 vector3_scale(struct vector3 *vec, double scale)
{
    struct vector3 result;
    result.x = vec->x * scale;
    result.y = vec->y * scale;
    result.z = vec->z * scale;

    return result;
}

struct vector3 vector3_scale_div(struct vector3 *vec, double scale)
{
    struct vector3 result;
    result.x = vec->x / scale;
    result.y = vec->y / scale;
    result.z = vec->z / scale;

    return result;
}

double vector3_dot(const struct vector3 *v1, const struct vector3 *v2)
{
    return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

struct vector3 vector3_cross(struct vector3 *v1, struct vector3 *v2)
{
    struct vector3 result;
    result.x = v1->y * v2->z - v1->z * v2->y;
    result.y = v1->z * v2->x - v1->x * v2->z;
    result.z = v1->x * v2->y - v1->y * v2->x;

    return result;
}

struct vector3 vector2_cross(struct vector2 *v1, struct vector2 *v2)
{
    struct vector3 result;
    result.x = 0.0;
    result.y = 0.0;
    result.z = v1->x * v2->y - v1->y * v2->x;

    return result;
}

double vector3_norm(const struct vector3 *vec)
{
    return sqrt(vector3_dot(vec, vec));
}

struct vector3 vector3_unit(const struct vector3 *vec)
{
    struct vector3 result;
    double length = vector3_norm(vec);
    result.x = vec->x / length;
    result.y = vec->y / length;
    result.z = vec->z / length;

    return result;
}
