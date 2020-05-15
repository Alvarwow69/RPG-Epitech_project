/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_get_position.c
*/

#include "rpg.h"

sfVector2f node_get_position(global_data_t *gdata, char *name)
{
    node_t *node = node_get(gdata, name);
    sfVector2f pos = {0, 0};

    if (node == NULL)
        my_printf("%snode_get_position: can't take %s%s%s position.%s"
        , LRED, PURPLE, name, LRED, RESET);
    else
        pos = sfTransformable_getPosition(node->transform);
    return (pos);
}