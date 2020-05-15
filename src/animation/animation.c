/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation.c
*/

#include "rpg.h"

void animation_reset(anim_t *anim)
{
    anim->is_anim = true;
    anim->rect_pos = 0;
}

void move_texture_rect(anim_t *anim)
{
    if (anim->rect_pos < anim->rect_max - anim->rect_move)
        anim->rect_pos += anim->rect_move;
    else if (anim->is_loop == false || anim->loop_time != 0) {
        anim->is_anim = false;
    } else
        anim->rect_pos = 0;
    anim->time->dif = 0;
}

void texture_time_gestion(anim_t *anim, sfClock *clock, texture_t *txt)
{
    if (anim->is_anim == false && anim->is_loop == false)
        return;
    anim->time->last = anim->time->actual;
    anim->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    anim->time->dif += anim->time->actual - anim->time->last;
    if (anim->is_anim == false && anim->loop_time != 0) {
        if (anim->time->dif < anim->loop_time)
            return;
        else {
            anim->is_anim = true;
            anim->time->dif = 0;
        }
    }
    if (anim->time->dif >= anim->anim_time)
        move_texture_rect(anim);
    txt->tile_rect.left = anim->rect_pos;
}