/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** inventory.c
*/

#include "rpg.h"

void inventory_update(global_data_t *gdata)
{
    node_t *node = node_get(gdata, "p_inv_node");
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    verif_quest_find(gdata, player->inventory);
    if (node->is_active == false)
        return;

    sfVector2f pixel_pos = sfRenderWindow_mapPixelToCoords(gdata->window, sfMouse_getPositionRenderWindow(gdata->window), gdata->active_scene->interface);
    sfVector2f node_pos = node_get_position(gdata, "p_inv_node");
    sfVector2f mouse_pos = {pixel_pos.x - node_pos.x - (20 * INV_SCALE.x), pixel_pos.y - node_pos.y - (20 * INV_SCALE.x)};

    gameobject_set_position(gdata, player->inventory->pick->go_inv->name, mouse_pos);
    gameobject_set_position(gdata, concat_fstring("%s_count", player->inventory->pick->go_inv->name), mouse_pos);
}