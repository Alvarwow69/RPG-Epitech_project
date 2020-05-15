/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_set_status.c
*/

#include "rpg.h"

void node_set_draw(global_data_t *gdata, char *name, bool draw)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_set_draw: can't modify %s%s%s draw status.%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    node->is_draw = draw;
}

void node_set_active(global_data_t *gdata, char *name, bool active)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_set_active: can't modify %s%s%s active status.%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    node->is_active = active;
}