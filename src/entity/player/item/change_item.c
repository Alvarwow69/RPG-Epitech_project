/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** change_item.c
*/

#include "rpg.h"

void check_id_and_type(global_data_t *gdata, item_t *slot, item_t *pick)
{
    item_id id_tmp = pick->id;
    item_type type_tmp = pick->type;

    if (search_n_occurence(slot->go_inv->name, "p_inv_inv", 1) == -1
    && search_n_occurence(slot->go_inv->name, "p_inv_active", 1) == -1
    && pick->id == IID_NO_ITEM) {
        pick->id = slot->id;
        pick->type = slot->type;
        gameobject_set_texture_rect(gdata, pick->go_inv->name
        , item_list[pick->type].rect);
        slot->id = item_list[slot->type].id;
    } else {
        pick->id = slot->id;
        slot->id = id_tmp;
        pick->type = slot->type;
        slot->type = type_tmp;
    }
}

void check_armor(global_data_t *gdata, item_t *slot, item_t *pick)
{
    if (pick->id == IID_NO_HELM || pick->id == IID_NO_CHEST
    || pick->id == IID_NO_PANTS || pick->id == IID_NO_RING) {
        pick->id = IID_NO_ITEM;
        pick->type = IT_NONE;
        gameobject_set_texture_rect(gdata, pick->go_inv->name
        , item_list[pick->type].rect);
    }
    if (search_n_occurence(slot->go_inv->name, "p_inv_inv", 1) == -1
    && search_n_occurence(slot->go_inv->name, "p_inv_active", 1) == -1
    && item_list[slot->id].armor_type != AT_NONE)
        change_player_armor(gdata, slot->id);
}

void permute_item(global_data_t *gdata, item_t *slot, item_t *pick)
{   
    char *name_tmp = pick->name;
    int nbr_tmp = pick->number;
    stats_t *stats_tmp = pick->stats;
    sfSprite *item_tmp = pick->go_inv->object.sprite;

    weapon_t *weapon_tmp = pick->wearable;
    consumable_t *cons_tmp = pick->consumable;

    if ((search_n_occurence(slot->go_inv->name, "p_inv_inv", 1) == -1
    && search_n_occurence(slot->go_inv->name, "p_inv_active", 1) == -1
    && item_list[slot->id].armor_type != item_list[pick->id].armor_type 
    && (slot->id != IID_NO_ITEM && pick->id != IID_NO_ITEM))
    || (slot->type == IT_RING && pick->type != IT_RING))
        return;
    check_id_and_type(gdata, slot, pick);

    pick->wearable = slot->wearable;
    slot->wearable = weapon_tmp;
    pick->consumable = slot->consumable;
    slot->consumable = cons_tmp;

    pick->name = slot->name;
    slot->name = name_tmp;
    pick->number = slot->number;
    slot->number = nbr_tmp;
    pick->stats = slot->stats;
    slot->stats = stats_tmp;
    pick->go_inv->object.sprite = slot->go_inv->object.sprite;
    slot->go_inv->object.sprite = item_tmp;
    if (slot->go_act != NULL)
        slot->go_act->object.sprite = item_tmp;
    set_item_count(gdata, pick);
    set_item_count(gdata, slot);
    check_armor(gdata, slot, pick);
}

void change_item(global_data_t *gdata, button_t *button)
{
    char *name = concat_fstring("%s_item", button->gameobject->name);
    inventory_t *inventory =\
    gameobject_get(gdata, "player_go")->object.player->inventory;
    item_t *inv_item = NULL;

    for (int ctr = 0; ctr < SLOT_COUNT; ctr += 1)
        if (cmp_string(inventory->items[ctr]->go_inv->name, name) == 0) {
            inv_item = inventory->items[ctr];
            break;
        }
    if (inv_item->id == IID_NO_ITEM
    && inventory->pick->id == IID_NO_ITEM)
        return;
    permute_item(gdata, inv_item, inventory->pick);
    if (inventory->pick->id == IID_NO_ITEM)
        inventory->pick->go_inv->is_draw = false;
    else
        inventory->pick->go_inv->is_draw = true;
}