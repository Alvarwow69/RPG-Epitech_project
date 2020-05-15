/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_create.c
*/

#include "rpg.h"

void place_node(global_data_t *gdata, scene_t *scene, node_t *node)
{
    if (scene->node == NULL) {
        node->prev = NULL;
        node->next = gdata->objects->node;
        if (gdata->objects->node != NULL)
            gdata->objects->node->prev = node;
        gdata->objects->node = node;
        scene->node = node;
    }
    else {
        if (cmp_string(scene->node->name, gdata->objects->node->name) == 0)
            gdata->objects->node = node;
        node->prev = scene->node->prev;
        node->next = scene->node;
        if (scene->node->prev != NULL)
            scene->node->prev->next = node;
        scene->node->prev = node;
        scene->node = node;
    }
}

node_t *check_node_not_exist(global_data_t *gdata, char *name)
{
    node_t *node = gdata->objects->node;

    while (node != NULL) {
        if (cmp_string(name, node->name) == 0)
            return (node);
        node = node->next;
    }
    return (NULL);
}

void node_create2(global_data_t *gdata, \
char *name, char *scene_name, node_t *node)
{
    node->name = string_dup(name);
    node->scene = string_dup(scene_name);
    node->is_draw = true;
    node->is_active = true;
    node->update = false;
    node->layer = 1;
    node->transform = sfTransformable_create();
    node->gameobjects = NULL;
}

void node_create(global_data_t *gdata, char *name, char *scene_name)
{
    scene_t *scene = scene_get(gdata, scene_name);
    node_t *check = check_node_not_exist(gdata, name);
    node_t *node = NULL;

    if (scene == NULL || check != NULL) {
        my_printf("%snode_create: can't create %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    node = malloc(sizeof(node_t));
    if (node == NULL) {
        my_printf("%snode_create: can't create %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    my_printf("%snode_create: create %s%s%s \
node.%s\n", YELLOW, PURPLE, name, YELLOW, RESET);
    node_create2(gdata, name, scene_name, node);
    place_node(gdata, scene, node);
}