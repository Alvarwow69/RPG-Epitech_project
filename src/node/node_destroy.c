/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_destroy.c
*/

#include "rpg.h"

void node_destroy(global_data_t *gdata, char *name)
{
    node_t *node = node_get(gdata, name);
    scene_t *scene = scene = scene_get(gdata, node->scene);

    if (node == NULL || scene == NULL) {
        my_printf("%snode_destroy: can't destroy %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    my_printf("%snode_destroy: destroy %s%s%s.%s\n"
    , YELLOW, PURPLE, name, YELLOW, RESET);
    for (game_object_t *go = node->gameobjects; \
go != NULL && cmp_string(go->node, node->name) == 0; \
go = node->gameobjects)
        gameobject_destroy(gdata, go->name);
    node_remove_from_list(gdata, scene, node);
    free(node->name);
    free(node->scene);
    sfTransformable_destroy(node->transform);
    free(node);
}