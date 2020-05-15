/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** arms.c
*/

#include "rpg.h"

void pnj_anim_arms(sfClock *clock, pnj_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->arms_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->arms_run, clock, anim->txt);
            break;
        default:
            break;
    }
}

void pnj_arms_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id)
{
    pnj_anim_arms(clock, pnj->anim, move);
    set_arms_rect(pnj->anim->txt, pnj->anim->arms_spr, move, id);
}