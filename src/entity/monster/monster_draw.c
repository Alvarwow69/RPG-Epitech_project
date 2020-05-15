/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_draw.c
*/

#include "rpg.h"

void monster_draw(sfRenderWindow *rwindow, monster_t *monster, sfRenderStates states)
{
    sfRenderWindow_drawSprite(rwindow, monster->anim->spr, &states);
}