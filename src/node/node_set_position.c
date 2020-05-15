/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** node_set_position
*/

#include "rpg.h"

void node_set_position(global_data_t *gdata, char *name, sfVector2f pos)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_set_position: can't modify %s%s%s position%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_setPosition(node->transform, pos);
}