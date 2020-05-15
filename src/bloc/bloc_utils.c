/*
** EPITECH PROJECT, 2020
** bloc_utils.c
** File description:
** 
*/

#include "rpg.h"

char *get_first_node_map(scene_t *scene)
{
    node_t *node = scene->node;

    if (!node)
        return (NULL);
    while (search_n_occurence(node->name, "map_level", 1) == -1)
        node = node->next;
    return (node->name);
}