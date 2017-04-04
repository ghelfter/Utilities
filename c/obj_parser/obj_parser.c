/* -----------------    Galen Helfter    ----------------- */
/* -----------------   Copyright 2017    ----------------- */
/* ----------------- ghelfter@gmail.com  ----------------- */
/* -----------------    obj_parser.c     ----------------- */

/* C standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Local headers */
#include "obj_parser.h"

/* Set local string variables for comparison */

/* Comment symbol */
static const char *l_comment = "#";

/* Vertex data */
static const char *l_geom_vert = "v";
static const char *l_text_vert = "vt";
static const char *l_vert_norm = "vn";
static const char *l_para_vert = "vp";

/* Element data */
static const char *l_point = "p";
static const char *l_line = "l";
static const char *l_face = "f";

/*static char parse_buffer[OBJ_PARSER_BUFFER_SIZE];*/

void clear_struct(struct WavefrontOBJ *object)
{
    memset(object, 0x00, sizeof(struct WavefrontOBJ));
}

int parse_obj_file(const char *filename, struct WavefrontOBJ *object)
{
    /* Vertex counts */
    unsigned int n_v = 0u;
    unsigned int n_vt = 0u;
    unsigned int n_vn = 0u;
    unsigned int n_vp = 0u;

    /* Vertex indices */
    unsigned int c_v = 0u;

    /* Element counts */
    unsigned int n_p = 0u;
    unsigned int n_l = 0u;
    unsigned int n_f = 0u;

    /*int bsize = OBJ_PARSER_BUFFER_SIZE;*/
    char *line = NULL;
    char *tokenized = NULL;
    char *tok_res = NULL;
    size_t lsize = 0;
    int result = 0;
    int rval = 0;
    FILE *in_file = NULL;

    /* Make sure that we receive a valid object */
    if(object == NULL)
    {
        return 1;
    }

    /* Clear our struct : Warning, will lose any allocated pointers, so
     * the struct should be clean */
    clear_struct(object);

    /* Open the file */
    in_file = fopen(filename, "r+");
    if(in_file == NULL)
    {
        return 2;
    }

    /* Go through the file */
    while(!feof(in_file))
    {
        /* Get line from the file */
        rval = getline(&line, &lsize, in_file);
        if(rval < 0)
        {
            continue;
        }

        /* Sanity print the lines */
        fprintf(stdout, "%d\n", rval);
        fprintf(stdout, "%s", line);

        /* Check for comment */
        if(!strncmp(line, l_comment, 1))
        {
            continue;
        }

        /* Go through the line and tokenize it */
        tok_res = strtok_r(line, " ", &tokenized);
        while(tok_res != NULL)
        {
            /* Check our vertex types */
            if(!strncmp(tok_res, l_text_vert, 2))
            {
                ++n_vt;
            }
            else if(!strncmp(tok_res, l_vert_norm, 2))
            {
                ++n_vn;
            }
            else if(!strncmp(tok_res, l_para_vert, 2))
            {
                ++n_vp;
            }
            else if(!strncmp(tok_res, l_geom_vert, 1))
            {
                ++n_v;
            }

            /* Now, check our element types */
            else if(!strncmp(tok_res, l_face, 1))
            {
                ++n_f;
            }
            else if(!strncmp(tok_res, l_point, 1))
            {
                ++n_p;
            }
            else if(!strncmp(tok_res, l_line, 1))
            {
                ++n_l;
            }
            tok_res = strtok_r(NULL, " ", &tokenized);
        }
    }

    /* Set structure array sizes */
    object->nverts = n_v;
    object->nuvs = n_vt;
    object->nnorms = n_vn;

    object->nfaces = n_f;
    object->nlines = n_l;

    /* Allocate our structure memory*/
    if(object->nverts)
    {
        object->verts = malloc(sizeof(double) * 3 * n_v);
    }

    /* Reset back to the beginning of the file */
    fseek(in_file, 0, SEEK_SET);

    /* Go through our second pass of the file */
    while(!feof(in_file))
    {
        /* Get line from the file */
        rval = getline(&line, &lsize, in_file);

        if(rval < 0)
        {
            continue;
        }

        /* Check for comment */
        if(!strncmp(line, l_comment, 1))
        {
            continue;
        }

        /* Go through the line and tokenize it */
        tok_res = strtok_r(line, " ", &tokenized);
        if(!strncmp(tok_res, l_text_vert, 2))
        {
        }
        else if(!strncmp(tok_res, l_vert_norm, 2))
        {
        }
        else if(!strncmp(tok_res, l_para_vert, 2))
        {
        }
        else if(!strncmp(tok_res, l_geom_vert, 1))
        {
            tok_res = strtok_r(NULL, " ", &tokenized);
            object->verts[c_v] = atof(tok_res);
            ++c_v;
            tok_res = strtok_r(NULL, " ", &tokenized);
            object->verts[c_v] = atof(tok_res);
            ++c_v;
            tok_res = strtok_r(NULL, " ", &tokenized);
            object->verts[c_v] = atof(tok_res);
            ++c_v;
        }
    }

    /* Close the file */
    fclose(in_file);

    /* Free our buffer */
    free(line);

    /* Return success */
    return result;
}

void access_vertex(const struct WavefrontOBJ *object, double *x,
                   double *y, double *z, int loc)
{
    int index = loc * 3;

    (*x) = *(object->verts + index);
    (*y) = *(object->verts + index + 1);
    (*z) = *(object->verts + index + 2);
}

void access_uv();

void access_norm(const struct WavefrontOBJ *object, double *x,
                 double *y, double *z, int loc)
{
    int index = loc * 3;

    (*x) = *(object->norms + index);
    (*y) = *(object->norms + index + 1);
    (*z) = *(object->norms + index + 2);
}

/* Function to provide for clearing the object file struct */
void free_obj_file(struct WavefrontOBJ *object)
{
    if(object->verts != NULL)
        free(object->verts);
    object->verts = NULL;
    object->nverts = 0u;

    if(object->uvs != NULL)
        free(object->uvs);
    object->uvs = NULL;
    object->nuvs = 0u;

    if(object->norms != NULL)
        free(object->norms);
    object->norms = NULL;
    object->nnorms = 0u;

    if(object->faces != NULL)
        free(object->faces);
    object->faces = NULL;
    object->nfaces = 0u;

    if(object->lines != NULL)
        free(object->lines);
    object->lines = NULL;
    object->nlines = 0u;
}
