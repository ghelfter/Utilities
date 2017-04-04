/* -------------------- Galen Helfter -------------------- */
/* ----------------- ghelfter@gmail.com ------------------ */
/* -------------------- obj_parser.h  -------------------- */

#ifndef _OBJ_PARSER_
#define _OBJ_PARSER_

struct WavefrontOBJ
{
    /* Pointers to our vertices, faces, etc. */
    double *verts;
    double *uvs;
    double *norms;
    unsigned int *faces;
    unsigned int *lines;

    /* Array sizes */
    unsigned int nverts;
    unsigned int nuvs;
    unsigned int nnorms;
    unsigned int nfaces;
    unsigned int nlines;
};

/* Function to parse the object file */
int parse_obj_file(const char *filename, struct WavefrontOBJ *object);

void access_vertex(const struct WavefrontOBJ *object, double *x,
                   double *y, double *z, int loc);
void access_norm(const struct WavefrontOBJ *object, double *x,
                 double *y, double *z, int loc);

void free_obj_file(struct WavefrontOBJ *object);

#endif
