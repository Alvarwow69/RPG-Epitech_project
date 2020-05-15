/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_set_layer.c
*/

#include "rpg.h"

void replace_node2(node_t *node, node_t *tmp, node_t *tmp_prev)
{
    node->prev = tmp_prev;
    node->next = tmp;
}

void replace_node(global_data_t *data, scene_t *scene, node_t *node)
{
    node_t *tmp = scene->node;
    node_t *tmp_prev = NULL;

    while (tmp != NULL
    && cmp_string(tmp->scene, node->scene) == 0
    && tmp->layer < node->layer) {
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    replace_node2(node, tmp, tmp_prev);
    if (tmp_prev != NULL)
        tmp_prev->next = node;
    if (tmp != NULL) {
        tmp->prev = node;
        if (scene->node != NULL \
&& cmp_string(tmp->name, scene->node->name) == 0)
            scene->node = node;
        if (data->objects->node != NULL \
&& cmp_string(tmp->name, data->objects->node->name) == 0)
            data->objects->node = node;
    }
}

void node_set_layer(global_data_t *gdata, char *name, int layer)
{
    node_t *node = node_get(gdata, name);
    scene_t *scene = NULL;

    if (node == NULL) {
        my_printf("%snode_set_layer : can't modify %s%s%s layer.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    if (node->layer == layer)
        return;
    scene = scene_get(gdata, node->scene);
    my_printf("%snode_set_layer: set %s%s%s layer to %s%i%s.%s\n"
    , YELLOW, PURPLE, name, YELLOW, PURPLE, layer, YELLOW, RESET);
    node->layer = layer;
    node_remove_from_list(gdata, scene, node);
    replace_node(gdata, scene, node);
}