/**
 * Project: Captain Geek
 * File: cg_context.h
 * Author: Ilija Djukic
 *
 * Platform definition:
 *   CG_ENABLE_GLFW
 *   CG_ENABLE_WIN32
 *   CG_ENABLE_X11
 */

#ifndef CG_CONTEXT_H
#define CG_CONTEXT_H

#include <stdlib.h>
#include <GL/gl.h>

typedef struct CG_Context
{
    int window_width;
    int window_height;
    void *target;
} *CG_Context_t;

CG_Context_t cgCreateContext(void);
void cgFreeContext(CG_Context_t context);
void cgResizeContext(CG_Context_t context, int width, int height);
void cgDrawContext(CG_Context_t context);
void cgUpdateContext(CG_Context_t context, float dt);

#endif // CG_CONTEXT_H
