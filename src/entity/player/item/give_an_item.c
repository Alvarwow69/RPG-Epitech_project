/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** give_an_item.c
*/

#include "rpg.h"

bool give_an_item(global_data_t *gdata, player_t *player, item_id id)
{
    int ctr = SLOT_ACTIVE[0];
    game_object_t *go_inv;
    game_object_t *go_act;

    while (ctr < SLOT_COUNT - 1) {
        if (player->inventory->items[ctr]->id == IID_NO_ITEM
        || (player->inventory->items[ctr]->id == id
        && player->inventory->items[ctr]->number + 1 <= item_list[id].stack))
            break;
        ctr += 1;
    }
    if (player->inventory->items[ctr]->id == IID_NO_ITEM) {
        go_inv = player->inventory->items[ctr]->go_inv;
        go_act = player->inventory->items[ctr]->go_act;
        destroy_item(gdata, player->inventory->items[ctr]);
        player->inventory->items[ctr] = create_item(gdata, id);
        player->inventory->items[ctr]->go_inv = go_inv;
        player->inventory->items[ctr]->go_act = go_act;
        gameobject_set_texture_rect(gdata, go_inv->name, item_list[id].rect);
    } else if (player->inventory->items[ctr]->id == id
    && player->inventory->items[ctr]->number + 1 <= item_list[id].stack)
        player->inventory->items[ctr]->number += 1;
    else
        return (false);
    set_item_count(gdata, player->inventory->items[ctr]);
    return (true);
}