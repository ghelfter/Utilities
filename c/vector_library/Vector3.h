/*  ============== Galen Helfter ==============  */
/*  ==============   Vector3.h   ==============  */

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include "Vector2.h"

struct vector3
{
    double x;
    double y;
    double z;
};

void vector3_init(struct vector3*);

struct vector3 vector3_add(struct vector3*, struct vector3*);
struct vector3 vector3_sub(struct vector3*, struct vector3*);

struct vector3 vector3_scale(struct vector3*, double scale);
struct vector3 vector3_scale_div(struct vector3*, double scale);

double vector3_dot(const struct vector3*, const struct vector3*);
struct vector3 vector3_cross(struct vector3*, struct vector3*);
struct vector3 vector2_cross(struct vector2*, struct vector2*);

double vector3_norm(const struct vector3*);
struct vector3 vector3_unit(const struct vector3*);

#endif
