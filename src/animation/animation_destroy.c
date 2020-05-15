/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** animation_destroy.c
*/

#include "rpg.h"

void animation_destroy(anim_t *anim)
{
    free(anim->time);
    free(anim);
}