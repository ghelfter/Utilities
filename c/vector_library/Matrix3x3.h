/*  ============== Galen Helfter ==============  */
/*  ==============  Matrix3x3.h  ==============  */

#ifndef _MATRIX3X3_H_
#define _MATRIX3X3_H_

#include "Vector3.h"

extern const struct matrix3x3 identity3x3;
extern const struct matrix3x3 empty3x3;

/*  Create structure for matrix  */
struct matrix3x3
{
    struct vector3 c0;
    struct vector3 c1;
    struct vector3 c2;
};

double matrix3x3_determinant(const struct matrix3x3 *m);

struct matrix3x3 matrix3x3_add(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2);
struct matrix3x3 matrix3x3_sub(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2);
struct matrix3x3 matrix3x3_mul(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2);

struct matrix3x3 matrix3x3_scale(const struct matrix3x3 *m, double s);

/*
 * Multiply a vector by a given matrix.
 */
struct vector3 matrix3x3_vec_mul(const struct matrix3x3 *m,
                                 const struct vector3 *v);

#endif
