#include <stdio.h>
#include <stdlib.h>

#include "obj_parser.h"

int main()
{
    const char *fname = "./test.obj";
    struct WavefrontOBJ object;
    int res = 0;
    double x, y, z;

    object.verts = NULL;
    object.uvs = NULL;
    object.norms = NULL;

    /* Test our OBJ reader */
    res = parse_obj_file(fname, &object);

    if(res)
    {
        fprintf(stdout, "File failed to load.\n");
    }

    access_vertex(&object, &x, &y, &z, 0);
    fprintf(stdout, "Vertex: %0.3f %0.3f %0.3f\n", x, y, z);

    free_obj_file(&object);

    return 0;
}
