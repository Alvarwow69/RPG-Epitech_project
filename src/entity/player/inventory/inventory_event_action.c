/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** inventory_event_action.c
*/

#include "rpg.h"

void open_inventory(global_data_t *gdata)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;
    node_t *inventory = node_get(gdata, "p_inv_node");

    play_sound_wait(gdata, SOUND_OPEN_INV);
    player->action_status = PA_INVENTORY;
    inventory->is_draw = true;
    inventory->is_active = true;
    gdata->key->i = false;
}

void close_inventory(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;
    node_t *inventory = node_get(gdata, "p_inv_node");

    (void)button;
    gdata->key->left_click = false;
    play_sound_wait(gdata, SOUND_CLOSE_INV);
    player->action_status = PA_NONE;
    inventory->is_draw = false;
    inventory->is_active = false;
    gdata->key->i = false;
    player->move->total_time = 0;
    player->move->force = 0;
}

void add_stat_point(global_data_t *gdata, button_t *button)
{
    text_t *text = gameobject_get(gdata, concat_fstring("%s_text", button->gameobject->name))->object.text;

    for (int ctr = 0; ctr < PSTAT_COUNT; ctr += 1)
        if (cmp_string(button->gameobject->name, pstat_list[ctr].name) == 0) {
            play_sound_reset(gdata, SOUND_UP_STAT);
            pstat_list[ctr].action(gdata, text);
        }

}

void inventory_trash(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (cmp_string(button->gameobject->name, "p_inv_trash") == 0)
        delete_pick_item(gdata, player);
}

void inv_action(global_data_t *gdata, button_t *button)
{
    (void)gdata;
    (void)button;
    my_printf("Et c'est Patrick !\n");
}