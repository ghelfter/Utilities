/*  ============== Galen Helfter ==============  */
/*  ==============  Matrix2x2.c  ==============  */

#include "Matrix2x2.h"

const struct matrix2x2 identity2x2 = { {1.0, 0.0}, {0.0, 1.0} };
const struct matrix2x2 empty2x2 = { {0.0, 0.0}, {0.0, 0.0} };

double matrix2x2_determinant(const struct matrix2x2 *m)
{
    return m->c0.x * m->c1.y - m->c1.x * m->c0.y;
}

struct matrix2x2 matrix2x2_mul(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2)
{
    struct matrix2x2 result;

    result.c0.x = m1->c0.x * m2->c0.x + m1->c1.x * m2->c0.y;
    result.c1.x = m1->c0.x * m2->c1.x + m1->c1.x * m2->c1.y;

    result.c0.y = m1->c0.y * m2->c0.x + m1->c1.y * m2->c0.y;
    result.c1.y = m1->c0.y * m2->c1.x + m1->c1.y * m2->c1.y;

    return result;
}


struct vector2 matrix2x2_vec_mul(const struct matrix2x2 *m,
                                 const struct vector2 *v)
{
    struct vector2 result;

    result.x = (m->c0.x * v->x) + (m->c1.x * v->y);
    result.y = (m->c0.y * v->x) + (m->c1.y * v->y);

    return result;
}

struct matrix2x2 matrix2x2_scale(const struct matrix2x2 *m,
                                 double s)
{
    struct matrix2x2 result;

    result.c0.x = m->c0.x * s;
    result.c0.y = m->c0.y * s;
    result.c1.x = m->c1.x * s;
    result.c1.y = m->c1.y * s;

    return result;
}

struct matrix2x2 matrix2x2_inverse(const struct matrix2x2 *m)
{
    struct matrix2x2 result = empty2x2;
    double det = matrix2x2_determinant(m);

    /*  Only calculate the inverse if the determinant is nonzero  */
    if(!(det < EPS && det > -EPS))
    {
        det = 1 / det;
        result.c0.x = m->c1.y * det;
        result.c0.y = m->c0.y * -det;
        result.c1.x = m->c1.x * -det;
        result.c1.y = m->c0.x * det;
    }

    return result;
}

struct matrix2x2 matrix2x2_add(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2)
{
    struct matrix2x2 result;

    result.c0.x = m1->c0.x + m2->c0.x;
    result.c0.y = m1->c0.y + m2->c0.y;
    result.c1.x = m1->c1.x + m2->c1.x;
    result.c1.y = m1->c1.y + m2->c1.y;

    return result;
}

struct matrix2x2 matrix2x2_sub(const struct matrix2x2 *m1,
                               const struct matrix2x2 *m2)
{
    struct matrix2x2 result;

    result.c0.x = m1->c0.x - m2->c0.x;
    result.c0.y = m1->c0.y - m2->c0.y;
    result.c1.x = m1->c1.x - m2->c1.x;
    result.c1.y = m1->c1.y - m2->c1.y;

    return result;
}
