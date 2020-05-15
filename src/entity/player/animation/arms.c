/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** arms.c
*/

#include "rpg.h"

void weapon_animation(sfClock *clock, player_t *player, move move)
{
    sfIntRect rect = {0, 0, 0, 0};
    sfVector2i offset = {0, 0};
    int rect_id = player->animation->txt->tile_rect.left
                  / player->animation->txt->tile_rect.width + 1;
    
    switch (move) {
        case M_STAND:
            offset = head_offset_list[HEAD_OFS_STAND].offset;
            break;
        case M_SEET:
            offset = head_offset_list[HEAD_OFS_SEET].offset;
            break;
        case M_SNICK:
            offset = head_offset_list[HEAD_OFS_SNICK].offset;
            break;
        case M_WALK:
            offset = head_offset_list[rect_id + HEAD_OFS_WALK_BEGIN].offset;
            break;
        case M_RUN:
            offset = head_offset_list[rect_id + HEAD_OFS_RUN_BEGIN].offset;
            break;
        case M_JUMP:
            offset = head_offset_list[rect_id + HEAD_OFS_JUMP_BEGIN].offset;
            break;
        default:
            break;
    }
    if (player->inventory->wear->wearable->type == WT_SWORD)
        texture_time_gestion(player->animation->arms_swip, clock, player->animation->txt_attack);
    else
        texture_time_gestion(player->animation->arms_pickaxe, clock, player->animation->txt_attack);
    texture_time_gestion(player->inventory->wear->wearable->anim, clock, player->inventory->wear->wearable->txt);

    rect = player->animation->txt_attack->tile_rect;
    rect = add_recti_vectori(rect, weapon[player->inventory->wear->wearable->id].offset);
    rect = add_recti_vectori(rect, offset);

    sfSprite_setTextureRect(player->animation->arms_spr, rect);
    rect = player->inventory->wear->wearable->txt->tile_rect;
    rect = add_recti_vectori(rect, offset);
    sfSprite_setTextureRect(player->inventory->wear->wearable->spr, rect);
}

void anim_arms(sfClock *clock, player_animation_t *anim, move move)
{
    switch (move) {
        case M_WALK:
            texture_time_gestion(anim->arms_walk, clock, anim->txt);
            break;
        case M_RUN:
            texture_time_gestion(anim->arms_run, clock, anim->txt);
            break;
        case M_JUMP:
            texture_time_gestion(anim->arms_jump, clock, anim->txt);
            break;
        default:
            break;
    }
}

void arms_animation(sfClock *clock, player_t *player
                     , move move, armor_id id)
{
    if (player->inventory->wear->wearable == NULL) {
        anim_arms(clock, player->animation, move);
        set_arms_rect(player->animation->txt, player->animation->arms_spr, move, id);
    }
    else
        weapon_animation(clock, player, move);
}