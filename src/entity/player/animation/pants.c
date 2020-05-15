/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** legs.c
*/

#include "rpg.h"

void anim_pants(sfClock *clock, player_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->legs_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->legs_run, clock, anim->txt);
            break;
        case M_JUMP:
            texture_time_gestion(anim->legs_jump, clock, anim->txt);
            break;
        default:
            break;
    }
}

void pants_animation(sfClock *clock, player_t *player
                     , move move, armor_id id)
{
    anim_pants(clock, player->animation, move);
    set_pants_rect(player->animation->txt, player->animation->legs_spr, move, id);
}