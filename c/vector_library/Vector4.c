/*  ============== Galen Helfter ==============  */
/*  ==============   Vector4.c   ==============  */

#include <math.h>

#include "Vector4.h"

void vector4_init(struct vector4 *v)
{
    v->x = 0.0;
    v->y = 0.0;
    v->z = 0.0;
    v->w = 0.0;
}

struct vector4 vector4_add(struct vector4 *v1, struct vector4 *v2)
{
    struct vector4 res;
    res.x = v1->x + v2->x;
    res.y = v1->y + v2->y;
    res.z = v1->z + v2->z;
    res.w = v1->w + v2->w;

    return res;
}

struct vector4 vector4_sub(struct vector4 *v1, struct vector4 *v2)
{
    struct vector4 res;
    res.x = v1->x - v2->x;
    res.y = v1->y - v2->y;
    res.z = v1->z - v2->z;
    res.w = v1->w - v2->w;

    return res;
}

struct vector4 vector4_scale(struct vector4 *v, double scale)
{
    struct vector4 result;
    result.x = v->x * scale;
    result.y = v->y * scale;
    result.z = v->z * scale;
    result.w = v->w * scale;

    return result;
}

struct vector4 vector4_scale3d(struct vector4 *v, double scale)
{
    struct vector4 result;
    result.x = v->x * scale;
    result.y = v->y * scale;
    result.z = v->z * scale;
    result.w = v->w;

    return result;
}

struct vector4 vector4_scale_div(struct vector4*, double scale);

double vector4_dot(const struct vector4 *v1, const struct vector4 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w;
}

struct vector4 vector4_cross(struct vector4, struct vector4);

double vector4_norm(const struct vector4 *v1)
{
    return sqrt(vector4_dot(v1, v1));
}

struct vector4 vector4_unit(const struct vector4 *v)
{
    struct vector4 res;
    double length = vector4_norm(v);

    res.x = v->x / length;
    res.y = v->y / length;
    res.z = v->z / length;
    res.w = v->w;

    return res;
}
