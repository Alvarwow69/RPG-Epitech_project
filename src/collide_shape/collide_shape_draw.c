/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** collide_shape_draw.c
*/

#include "rpg.h"

void collide_shape_draw(sfRenderWindow *rwindow, collide_shape_t *cshape
                       , sfRenderStates states)
{
    if (cshape->is_draw == true && cshape->is_active == true)
        sfRenderWindow_drawVertexArray(rwindow, cshape->array, &states);
}