/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** delete_an_item.c
*/

#include "rpg.h"

void delete_pick_item(global_data_t *gdata, player_t *player)
{
    game_object_t *go = player->inventory->pick->go_inv;

    if (gdata->key->lmaj == true || gdata->key->rmaj == true || player->inventory->pick->number == 1) {
        destroy_item(gdata, player->inventory->pick);
        player->inventory->pick = create_item(gdata, IID_NO_ITEM);
        player->inventory->pick->go_inv = go;
        gameobject_set_texture_rect(gdata, go->name, item_list[IID_NO_ITEM].rect);
        player->inventory->pick->go_inv->is_draw = false;
    }
    else
        player->inventory->pick->number -= 1;
    set_item_count(gdata, player->inventory->pick);
}

void delete_wear_item(global_data_t *gdata, player_t *player)
{
    game_object_t *go_inv = player->inventory->wear->go_inv;
    game_object_t *go_act = player->inventory->wear->go_act;

    if (gdata->key->lmaj == true || gdata->key->rmaj == true || player->inventory->wear->number == 1) {
        destroy_item(gdata, player->inventory->wear);
        player->inventory->wear = create_item(gdata, IID_NO_ITEM);
        player->inventory->wear->go_inv = go_inv;
        player->inventory->wear->go_act = go_act;
        gameobject_set_texture_rect(gdata, go_inv->name, item_list[IID_NO_ITEM].rect);
    }
    else
        player->inventory->wear->number -= 1;
    set_item_count(gdata, player->inventory->wear);
}

void delete_item(global_data_t *gdata, item_t **item, int ctr)
{
    game_object_t *go_inv = item[ctr]->go_inv;
    game_object_t *go_act = item[ctr]->go_act;

    if (item == NULL)
        return;
    if (item[ctr]->number == 1) {
        destroy_item(gdata, item[ctr]);
        item[ctr] = create_item(gdata, IID_NO_ITEM);
        item[ctr]->go_inv = go_inv;
        item[ctr]->go_act = go_act;
        gameobject_set_texture_rect(gdata, go_inv->name, item_list[IID_NO_ITEM].rect);
    }
    else
        item[ctr]->number -= 1;
    set_item_count(gdata, item[ctr]);
}

void delete_nbr_item(global_data_t *gdata, inventory_t *inv, item_id id, int count)
{
    if (search_item(inv, id) < count)
        return;
    for (int ctr = 0; ctr < INV_COUNT && count > 0; ctr += 1) {
        if (inv->items[ctr]->id != id)
            continue;
        for (int i = 0; inv->items[ctr]->number > 0 && count > 0; i += 1) {
            delete_item(gdata, inv->items, ctr);
            count -= 1;
        }
    }
}