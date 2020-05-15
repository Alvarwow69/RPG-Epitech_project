/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** legs.c
*/

#include "rpg.h"

void pnj_anim_pants(sfClock *clock, pnj_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->legs_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->legs_run, clock, anim->txt);
            break;
        default:
            break;
    }
}

void pnj_pants_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id)
{
    pnj_anim_pants(clock, pnj->anim, move);
    set_pants_rect(pnj->anim->txt, pnj->anim->legs_spr, move, id);
}