/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_remove_from_list.c
*/

#include "rpg.h"

void node_remove_from_list(global_data_t *gdata, scene_t *scene, node_t *node)
{
    node_t *tmp = node->next;
    node_t *tmp_prev = node->prev;

    if (cmp_string(scene->node->name, node->name) == 0) {
        if (scene->node->next != NULL \
&& cmp_string(scene->name, scene->node->next->scene) == 0)
            scene->node = scene->node->next;
        else
            scene->node = NULL;
    }
    if (cmp_string(gdata->objects->node->name, node->name) == 0) {
        if (gdata->objects->node->next != NULL)
            gdata->objects->node = gdata->objects->node->next;
        else
            gdata->objects->node = NULL;
    }
    if (node->prev != NULL)
        node->prev->next = tmp;
    if (node->next != NULL)
        node->next->prev = tmp_prev;
}