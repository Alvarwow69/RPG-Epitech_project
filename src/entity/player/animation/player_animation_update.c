/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_animation_update.c
*/

#include "rpg.h"

void player_animation(sfClock *clock, player_t *player, armor_type type
                     , move move, armor_id id)
{
    sfIntRect offset = {0, 0, 129, 129};

    switch (type) {
        case AT_HELM:
            offset = set_helm_rect(player, move, id);
            sfSprite_setTextureRect(player->animation->head_spr, offset);
            break;
        case AT_CHEST:
            chest_animation(clock, player, move, id);
            break;
        case AT_ARMS:
            arms_animation(clock, player, move, id);
            break;
        case AT_PANTS:
            pants_animation(clock, player, move, id);
            break;
        case AT_NONE:
            break;
    }
}

void player_animation_update(global_data_t *gdata, player_t *player)
{
    item_t **items = player->inventory->items;

    player_animation(gdata->clock, player, AT_CHEST, player->move_status
    , (armor_id){chest[item_list[items[SLOT_CHEST]->id].armor_id.chest].id});
    player_animation(gdata->clock, player, AT_ARMS, player->move_status
    , (armor_id){chest[item_list[items[SLOT_CHEST]->id].armor_id.chest].arms_id});
    player_animation(gdata->clock, player, AT_PANTS, player->move_status
    , (armor_id){pants[item_list[items[SLOT_PANTS]->id].armor_id.pants].id});
    player_animation(gdata->clock, player, AT_HELM, player->move_status
    , (armor_id){helm[item_list[items[SLOT_HELM]->id].armor_id.helm].id});
}