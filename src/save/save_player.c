/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** save_player
*/

#include "rpg.h"

void save_to_player(global_data_t *data)
{
    player_t *player = gameobject_get(data, "player_go")->object.player;

    for (int i = 7; i != SLOT_COUNT; i ++)
        for (int y = 0; y != player->save->nbr_item[i]; y++) {
            give_an_item(data, player, player->save->tab_id_item[i]);
    }
    player->prop->hp.act = player->save->value[0].act;
    player->prop->hp.max = player->save->value[0].max;
    player->prop->xp.act = player->save->value[1].act;
    player->prop->xp.max = player->save->value[1].max;
    player->prop->satiety.act = player->save->value[2].act;
    player->prop->satiety.max = player->save->value[2].max;

    player->prop->money = player->save->properties[0];
    player->prop->strenght = player->save->properties[1];
    player->prop->defense = player->save->properties[2];
    player->prop->accuracy = player->save->properties[3];
    player->prop->luck = player->save->properties[4];
    player->prop->dexterity = player->save->properties[5];
    player->prop->celerity = player->save->properties[6];
    player->prop->avl_point = player->save->properties[7];

}

void player_to_save(global_data_t *data)
{
    player_t *player = gameobject_get(data, "player_go")->object.player;

    for (int i = 4; i != SLOT_COUNT; i ++) {
        player->save->tab_id_item[i-4] = player->inventory->items[i-4]->id;
        player->save->nbr_item[i-4] = player->inventory->items[i-4]->number;
    }
    player->save->value[0].act = player->prop->hp.act;
    player->save->value[0].max = player->prop->hp.max;
    player->save->value[1].act = player->prop->xp.act;
    player->save->value[1].max = player->prop->xp.max;
    player->save->value[2].act = player->prop->satiety.act;
    player->save->value[2].max = player->prop->satiety.max;
    player->save->properties[0] = player->prop->money;
    player->save->properties[1] = player->prop->strenght;
    player->save->properties[2] = player->prop->defense;
    player->save->properties[3] = player->prop->accuracy;
    player->save->properties[4] = player->prop->luck;
    player->save->properties[5] = player->prop->dexterity;
    player->save->properties[6] = player->prop->celerity;
    player->save->properties[7] = player->prop->avl_point;
}