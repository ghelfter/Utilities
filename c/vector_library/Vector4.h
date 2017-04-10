/*  ============== Galen Helfter ==============  */
/*  ==============   Vector4.h   ==============  */

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "Util.h"

struct vector4
{
    double x;
    double y;
    double z;
    double w;
};

void vector4_init(struct vector4*);

struct vector4 vector4_add(struct vector4*, struct vector4*);
struct vector4 vector4_sub(struct vector4*, struct vector4*);

struct vector4 vector4_scale3d(struct vector4*, double scale);
struct vector4 vector4_scale3d(struct vector4*, double scale);
struct vector4 vector4_scale_div(struct vector4*, double scale);

double vector4_dot(const struct vector4*, const struct vector4*);
struct vector4 vector4_cross(struct vector4, struct vector4);

double vector4_norm(const struct vector4*);
struct vector4 vector4_unit(const struct vector4*);

#endif
