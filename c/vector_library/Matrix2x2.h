/*  ============== Galen Helfter ==============  */
/*  ==============  Matrix2x2.h  ==============  */

#ifndef _MATRIX2X2_H_
#define _MATRIX2X2_H_

#include "Vector2.h"

struct matrix2x2
{
    struct vector2 c0;
    struct vector2 c1;
};

extern const struct matrix2x2 identity2x2;
extern const struct matrix2x2 empty2x2;

double matrix2x2_determinant(const struct matrix2x2 *m);

struct matrix2x2 matrix2x2_mul(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2);

struct vector2 matrix2x2_vec_mul(const struct matrix2x2 *m,
                                 const struct vector2 *v);

struct matrix2x2 matrix2x2_scale(const struct matrix2x2 *m,
                                 double s);

struct matrix2x2 matrix2x2_inverse(const struct matrix2x2 *m);

struct matrix2x2 matrix2x2_add(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2);
struct matrix2x2 matrix2x2_sub(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2);

#endif
