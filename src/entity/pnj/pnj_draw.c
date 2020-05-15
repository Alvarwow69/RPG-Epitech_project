/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** pnj_draw.c
*/

#include "rpg.h"

void pnj_draw(sfRenderWindow *rwindow, pnj_t *pnj, sfRenderStates states)
{
    sfRenderWindow_drawSprite(rwindow, pnj->anim->body_spr, &states);
    sfRenderWindow_drawSprite(rwindow, pnj->anim->legs_spr, &states);
    sfRenderWindow_drawSprite(rwindow, pnj->anim->head_spr, &states);
    sfRenderWindow_drawSprite(rwindow, pnj->anim->arms_spr, &states);
}