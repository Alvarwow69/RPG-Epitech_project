/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** ui_update.c
*/

#include "rpg.h"

void update_satiety(global_data_t *gdata, player_t *player)
{
    player->prop->time->last = player->prop->time->actual;
    player->prop->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(gdata->clock));
    player->prop->time->dif += player->prop->time->actual - player->prop->time->last;
    if (player->prop->time->dif >= 2) {
        modify_satiety(gdata, player->prop, -1);
        player->prop->time->dif = 0;
    }
}

void switch_weared_item(global_data_t *gdata, inventory_t *inv, ui_rsc_id id)
{
    char *name = concat_fstring("%s_wear", inv->wear->go_act->name);

    gameobject_set_texture_rect(gdata, name, ui_rsc[UIRSC_SLOT].normal);
    inv->wear = inv->items[SLOT_ACTIVE[id]];
    name = concat_fstring("%s_wear", inv->wear->go_act->name);
    gameobject_set_texture_rect(gdata, name, ui_rsc[UIRSC_SLOT].select);
}

void ui_update(global_data_t *gdata)
{
    player_t *player = NULL;

    if (!gameobject_get(gdata, "player_go"))
        return;
    player = gameobject_get(gdata, "player_go")->object.player;
    if (get_controls_event(gdata, "Hotbar Slot 1") == true)
        switch_weared_item(gdata, player->inventory, UIRSC_ACTIVE_SLOT1);
    if (get_controls_event(gdata, "Hotbar Slot 2") == true)
        switch_weared_item(gdata, player->inventory, UIRSC_ACTIVE_SLOT2);
    if (get_controls_event(gdata, "Hotbar Slot 3") == true)
        switch_weared_item(gdata, player->inventory, UIRSC_ACTIVE_SLOT3);
    if (get_controls_event(gdata, "Hotbar Slot 4") == true)
        switch_weared_item(gdata, player->inventory, UIRSC_ACTIVE_SLOT4);
    if (get_controls_event(gdata, "Hotbar Slot 5") == true)
        switch_weared_item(gdata, player->inventory, UIRSC_ACTIVE_SLOT5);
    update_satiety(gdata, player);
}