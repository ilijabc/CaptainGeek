/**
 * Project: Captain Geek
 * File: cg_context.c
 * Author: Ilija Djukic
 */

#include "cg_context.h"

CG_Context_t cgCreateContext(void)
{
    CG_Context_t context = malloc(sizeof(struct CG_Context));
    memset(context, 0, sizeof(struct CG_Context));
    return context;
}

void cgFreeContext(CG_Context_t context)
{
    free(context);
}

void cgResizeContext(CG_Context_t context, int width, int height)
{
    context->window_width = width;
    context->window_height = height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, context->window_width, 0, context->window_height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void cgDrawContext(CG_Context_t context)
{
    // reset view matrix
    glLoadIdentity();
    // draw background
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0, 0);
    glColor3f(0, 0, 0);
    glVertex2f(context->window_width, 0);
    glColor3f(0, 0.5, 0);
    glVertex2f(context->window_width, context->window_height);
    glColor3f(0, 0.5, 0);
    glVertex2f(0, context->window_height);
    glEnd();
}

void cgUpdateContext(CG_Context_t context, float dt)
{
    // TODO: page turning animation
}