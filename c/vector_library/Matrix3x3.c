/*  ============== Galen Helfter ==============  */
/*  ==============  Matrix3x3.c  ==============  */

#include "Matrix3x3.h"

const struct matrix3x3 identity3x3 = { {1.0, 0.0, 0.0}
                                     , {0.0, 1.0, 0.0}
                                     , {0.0, 0.0, 1.0} };

const struct matrix3x3 empty3x3 = { {0.0, 0.0, 0.0}
                                  , {0.0, 0.0, 0.0}
                                  , {0.0, 0.0, 0.0} };

double matrix3x3_determinant(const struct matrix3x3 *m)
{
    return m->c0.x * m->c1.y * m->c2.z +
           m->c1.x * m->c2.y * m->c0.z +
           m->c2.x * m->c0.y * m->c1.z -
          (m->c2.x * m->c1.y * m->c0.z +
           m->c1.x * m->c0.y * m->c2.z +
           m->c0.x * m->c2.y * m->c1.z);
}

struct matrix3x3 matrix3x3_add(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2)
{
    struct matrix3x3 result;

    result.c0.x = m1->c0.x + m2->c0.x;
    result.c0.y = m1->c0.y + m2->c0.y;
    result.c0.z = m1->c0.z + m2->c0.z;

    result.c1.x = m1->c1.x + m2->c1.x;
    result.c1.y = m1->c1.y + m2->c1.y;
    result.c1.z = m1->c1.z + m2->c1.z;

    result.c2.x = m1->c2.x + m2->c2.x;
    result.c2.y = m1->c2.y + m2->c2.y;
    result.c2.z = m1->c2.z + m2->c2.z;

    return result;
}

struct matrix3x3 matrix3x3_sub(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2)
{
    struct matrix3x3 result;

    result.c0.x = m1->c0.x - m2->c0.x;
    result.c0.y = m1->c0.y - m2->c0.y;
    result.c0.z = m1->c0.z - m2->c0.z;

    result.c1.x = m1->c1.x - m2->c1.x;
    result.c1.y = m1->c1.y - m2->c1.y;
    result.c1.z = m1->c1.z - m2->c1.z;

    result.c2.x = m1->c2.x - m2->c2.x;
    result.c2.y = m1->c2.y - m2->c2.y;
    result.c2.z = m1->c2.z - m2->c2.z;

    return result;
}

struct matrix3x3 matrix3x3_mul(const struct matrix3x3 *m1,
                               const struct matrix3x3 *m2)
{
    struct matrix3x3 result;

    /*  Calculate the first column  */
    result.c0.x = m1->c0.x * m2->c0.x + m1->c1.x * m2->c0.y
                  + m1->c2.x * m2->c0.z;
    result.c0.y = m1->c0.y * m2->c0.x + m1->c1.y * m2->c0.y
                  + m1->c2.y * m2->c0.z;
    result.c0.z = m1->c0.z * m2->c0.x + m1->c1.z * m2->c0.y
                  + m1->c2.z * m2->c0.z;

    /*  Calculate the second column  */
    result.c1.x = m1->c0.x * m2->c1.x + m1->c1.x * m2->c1.y
                  + m1->c2.x * m2->c1.z;
    result.c1.y = m1->c0.y * m2->c1.x + m1->c1.y * m2->c1.y
                  + m1->c2.y * m2->c1.z;
    result.c1.z = m1->c0.z * m2->c1.x + m1->c1.z * m2->c1.y
                  + m1->c2.z * m2->c1.z;

    /*  Calculate the third column  */
    result.c2.x = m1->c0.x * m2->c2.x + m1->c1.x * m2->c2.y
                  + m1->c2.x * m2->c2.z;
    result.c2.y = m1->c0.y * m2->c2.x + m1->c1.y * m2->c2.y
                  + m1->c2.y * m2->c2.z;
    result.c2.z = m1->c0.z * m2->c2.x + m1->c1.z * m2->c2.y
                  + m1->c2.z * m2->c2.z;

    return result;
}

struct vector3 matrix3x3_vec_mul(const struct matrix3x3 *m,
                                 const struct vector3 *v)
{
    struct vector3 result;

    result.x = m->c0.x * v->x + m->c1.x * v->y + m->c2.x * v->z;
    result.y = m->c0.y * v->x + m->c1.y * v->y + m->c2.y * v->z;
    result.z = m->c0.z * v->x + m->c1.z * v->y + m->c2.z * v->z;

    return result;
}

struct matrix3x3 matrix3x3_scale(const struct matrix3x3 *m, double s)
{
    struct matrix3x3 result;

    result.c0.x = m->c0.x * s;
    result.c0.y = m->c0.y * s;
    result.c0.z = m->c0.z * s;

    result.c1.x = m->c1.x * s;
    result.c1.y = m->c1.y * s;
    result.c1.z = m->c1.z * s;

    result.c2.x = m->c2.x * s;
    result.c2.y = m->c2.y * s;
    result.c2.z = m->c2.z * s;

    return result;
}
