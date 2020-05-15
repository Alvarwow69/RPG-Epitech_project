/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** body.c
*/

#include "rpg.h"

void anim_chest(sfClock *clock, player_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->body_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->body_run, clock, anim->txt);
            break;
        case M_JUMP:
            texture_time_gestion(anim->body_jump, clock, anim->txt);
            break;
        default:
            break;
    }
}

void chest_animation(sfClock *clock, player_t *player
                     , move move, armor_id id)
{
    anim_chest(clock, player->animation, move);
    set_chest_rect(player->animation->txt, player->animation->body_spr, move, id);
}