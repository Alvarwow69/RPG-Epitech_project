/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_get.c
*/

#include "rpg.h"

node_t *node_get(global_data_t *gdata, char *name)
{
    node_t *node = gdata->objects->node;

    while (node != NULL) {
        if (cmp_string(name, node->name) == 0)
            return (node);
        node = node->next;
    }
    my_printf("%snode_get: %s%s%s doesn't exist.%s\n"
    , LRED, PURPLE, name, LRED, RESET);
    return (NULL);
}