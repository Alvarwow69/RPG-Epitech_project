/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** gameobject_get_global_origin.c
*/

#include "rpg.h"

sfVector2f gameobject_get_global_origin(global_data_t *gdata, char *name)
{
    game_object_t *go = gameobject_get(gdata, name);
    node_t *node = NULL;
    sfVector2f pos = {0, 0};
    sfVector2f node_pos = {0, 0};

    if (go == NULL)
        my_printf("%sgameobject_get_global_origin: can't get %s%s%s"
        " origin position.%s\n", LRED, PURPLE, name, LRED, RESET);
    else {
        node = node_get(gdata, go->node);
        node_pos = sfTransformable_getOrigin(node->transform);
        pos = sfTransformable_getOrigin(go->transform);
        pos.x += node_pos.x;
        pos.y += node_pos.y;
    }
    return (pos);
}

sfVector2f gameobject_get_g_origin(global_data_t *gdata, game_object_t *game)
{
    node_t *node = NULL;
    sfVector2f pos = {0, 0};
    sfVector2f node_pos = {0, 0};

    node = node_get(gdata, game->node);
    node_pos = sfTransformable_getOrigin(node->transform);
    pos = sfTransformable_getOrigin(game->transform);
    pos.x += node_pos.x;
    pos.y += node_pos.y;
    return (pos);
}