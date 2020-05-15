/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_event.c
*/

#include "rpg.h"

void player_scene_event(global_data_t *gdata)
{
    scene_t *scene = scene_get(gdata, "player_scene");
    node_t *inv = node_get(gdata, "p_inv_node");

    if (gdata->key->left_click) {
        check_button(gdata, sfMouse_getPositionRenderWindow(gdata->window), scene->interface, inv);
    }
    player_update(gdata);
    pnj_update_all(gdata);
    monster_update(gdata, "Lilodon");
}