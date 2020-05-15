/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** animation_create.c
*/

#include "rpg.h"

anim_t *animation_create(texture_t *txt, float anim_time
                        , float loop_time, sfVector2i pos_and_max)
{
    anim_t *anim = malloc(sizeof(anim_t));

    anim->rect_pos = pos_and_max.x;
    anim->rect_max = pos_and_max.y;
    anim->rect_move = txt->tile_size.x;
    anim->is_anim = false;
    anim->is_loop = false;
    if (anim_time != -1)
        anim->is_anim = true;
    if (loop_time != -1)
        anim->is_loop = true;
    anim->anim_time = anim_time;
    anim->loop_time = loop_time;
    anim->time = game_time_create();
    return (anim);
}