/**
 * Project: Captain Geek
 * File: cg_pair.c
 * Author: Ilija Djukic
 */

#include "cg_pair.h"

CG_Pair_t cgCreatePair()
{
    CG_Pair_t pair = malloc(sizeof(struct CG_Pair));
    return pair;
}

void cgFreePair(CG_Pair_t pair)
{
    free(pair);
}

static void cg_draw_rect(float x1, float y1, float x2, float y2,
                         float u1, float v1, float u2, float v2)
{
    glBegin(GL_QUADS);
    glTexCoord2f(u1, v1);
    glVertex2f(x1, y1);
    glTexCoord2f(u2, v1);
    glVertex2f(x2, y1);
    glTexCoord2f(u2, v2);
    glVertex2f(x2, y2);
    glTexCoord2f(u1, v2);
    glVertex2f(x1, y2);
    glEnd();
}

void cgDrawPair(CG_Pair_t pair)
{
    //left page
    glPushMatrix();
    glColor3f(1, 1, 1);
    cg_draw_rect(-21, 0, 0, 27,
                 0, 0, 1, 1);
    glPopMatrix();
    //right page
    glPushMatrix();
    glColor3f(1, 1, 0);
    cg_draw_rect(0, 0, 21, 27,
                 0, 0, 1, 1);
    glPopMatrix();
}

void cgUpdatePair(CG_Pair_t pair, float dt)
{
    // TODO: update page turning animation...
}
