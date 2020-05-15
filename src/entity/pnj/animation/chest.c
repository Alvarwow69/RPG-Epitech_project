/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** body.c
*/

#include "rpg.h"

void pnj_anim_chest(sfClock *clock, pnj_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->body_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->body_run, clock, anim->txt);
            break;
        default:
            break;
    }
}

void pnj_chest_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id)
{
    pnj_anim_chest(clock, pnj->anim, move);
    set_chest_rect(pnj->anim->txt, pnj->anim->body_spr, move, id);
}