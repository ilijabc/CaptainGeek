/**
 * Project: Captain Geek
 * File: cg_pair.h
 * Author: Ilija Djukic
 */

#ifndef CG_PAIR_H
#define CG_PAIR_H

#include "cg_common.h"

typedef struct CG_Pair
{
    GLuint page_tex[2];
    int single_tex;
    float page_anim_time[2];
    int current_anim;
} *CG_Pair_t;

CG_Pair_t cgCreatePair();
void cgFreePair(CG_Pair_t pair);
void cgDrawPair(CG_Pair_t pair);
void cgUpdatePair(CG_Pair_t pair, float dt);

#endif // CG_PAIR_H
