/*  ============== Galen Helfter ==============  */
/*  ==============   Vector2.h   ==============  */

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include "Util.h"

struct vector2
{
    double x;
    double y;
};

void vector2_init(struct vector2*);

struct vector2 vector2_add(struct vector2, struct vector2);
struct vector2 vector2_sub(struct vector2, struct vector2);

struct vector2 vector2_scale(struct vector2, double scale);
struct vector2 vector2_scale_div(struct vector2, double scale);

double vector2_dot(struct vector2, struct vector2);

double vector2_norm(struct vector2);
struct vector2 vector2_unit(struct vector2);

#endif
