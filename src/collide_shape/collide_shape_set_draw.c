/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** collide_shape_is_draw.c
*/

#include "rpg.h"

void collide_shape_set_draw(collide_shape_t *cshape, bool is_draw)
{
    cshape->is_draw = is_draw;
}