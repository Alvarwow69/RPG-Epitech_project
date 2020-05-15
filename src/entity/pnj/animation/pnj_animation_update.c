/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_animation_update.c
*/

#include "rpg.h"

void pnj_animation(sfClock *clock, pnj_t *pnj, armor_type type
                     , move move, armor_id id)
{
    sfIntRect offset = {0, 0, 129, 129};

    switch (type) {
        case AT_HELM:
            offset = pnj_set_helm_rect(pnj, move, id);
            sfSprite_setTextureRect(pnj->anim->head_spr, offset);
            break;
        case AT_CHEST:
            pnj_chest_animation(clock, pnj, move, id);
            break;
        case AT_ARMS:
            pnj_arms_animation(clock, pnj, move, id);
            break;
        case AT_PANTS:
            pnj_pants_animation(clock, pnj, move, id);
            break;
        case AT_NONE:
            break;
    }
}

void pnj_animation_update(global_data_t *gdata, pnj_t *pnj)
{
    pnj_animation(gdata->clock, pnj, AT_CHEST
        , pnj->move_status, (armor_id){pnj->chest_id});
    pnj_animation(gdata->clock, pnj, AT_ARMS
        , pnj->move_status, (armor_id){pnj->arms_id});
    pnj_animation(gdata->clock, pnj, AT_PANTS
        , pnj->move_status, (armor_id){pnj->pants_id});
    pnj_animation(gdata->clock, pnj, AT_HELM
        , pnj->move_status, (armor_id){pnj->helm_id});
}