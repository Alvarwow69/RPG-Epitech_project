/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** gameobject_remove_from_list.c
*/

#include "rpg.h"

void gameobject_remove_from_list(global_data_t *gdata, node_t *node,
game_object_t *go)
{
    game_object_t *tmp = go->next;
    game_object_t *tmp_prev = go->prev;

    if (cmp_string(node->gameobjects->name, go->name) == 0) {
        if (node->gameobjects->next != NULL \
&& cmp_string(node->name, node->gameobjects->next->node) == 0)
            node->gameobjects = node->gameobjects->next;
        else
            node->gameobjects = NULL;
    }
    if (cmp_string(gdata->objects->game_object->name, go->name) == 0) {
        if (gdata->objects->game_object->next != NULL)
            gdata->objects->game_object = gdata->objects->game_object->next;
        else
            gdata->objects->game_object = NULL;
    }
    if (go->prev != NULL)
        go->prev->next = tmp;
    if (go->next != NULL)
        go->next->prev = tmp_prev;
}