/*
** EPITECH PROJECT, 2020
** editor_unload.c
** File description:
** 
*/

#include "rpg.h"

void editor_unload(global_data_t *data)
{
    scene_t *scene = scene_get(data, "map_editor");

    map_save(data, "node_map_editor");
    for (node_t *node = scene->node;
        node != NULL && cmp_string(node->scene, scene->name) == 0;
        node = scene->node)
        node_destroy(data, node->name);
}