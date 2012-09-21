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

void cgDrawPair(CG_Pair_t pair)
{
    // TODO: draw paired pages...
}

void cgUpdatePair(CG_Pair_t pair, float dt)
{
    // TODO: update page turning animation...
}
