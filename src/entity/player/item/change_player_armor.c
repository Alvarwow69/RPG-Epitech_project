/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** change_player_armor.c
*/

#include "rpg.h"

void change_player_chest(global_data_t *gdata, player_t *player, item_id iid)
{
    armor_set_texture(player->animation->body_spr
    , gdata->ressources->textures, AT_CHEST, item_list[iid].armor_id);
    set_chest_rect(player->animation->txt, player->animation->body_spr, player->move_status, item_list[iid].armor_id);
    armor_set_texture(player->animation->arms_spr
    , gdata->ressources->textures, AT_ARMS
    , (armor_id){chest[item_list[iid].armor_id.chest].arms_id});
    set_arms_rect(player->animation->txt, player->animation->arms_spr, player->move_status
    , (armor_id){chest[item_list[iid].armor_id.chest].arms_id});
}

void change_player_pants(global_data_t *gdata, player_t *player, item_id iid)
{
    armor_set_texture(player->animation->legs_spr,
    gdata->ressources->textures, AT_PANTS, item_list[iid].armor_id);
    set_pants_rect(player->animation->txt, player->animation->legs_spr, player->move_status, item_list[iid].armor_id);
}

void change_player_armor(global_data_t *gdata, item_id iid)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    switch (item_list[iid].armor_type) {
        case AT_CHEST:
            change_player_chest(gdata, player, iid);
            break;
        case AT_PANTS:
            change_player_pants(gdata, player, iid);
            break;
        default:
            break;
    }
}