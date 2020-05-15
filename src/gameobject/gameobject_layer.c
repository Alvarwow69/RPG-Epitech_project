/*
** EPITECH PROJECT, 2020
** gameobject_layer.c
** File description:
** 
*/

#include "rpg.h"

static void switch_gameobject(global_data_t *gdata, game_object_t *tmp,
game_object_t *game, node_t *node)
{
    if (tmp != NULL) {
        tmp->prev = game;
        if (node->gameobjects != NULL
            && cmp_string(tmp->name, node->gameobjects->name) == 0)
            node->gameobjects = game;
        if (gdata->objects->game_object != NULL
            && cmp_string(tmp->name, gdata->objects->game_object->name) == 0)
            gdata->objects->game_object = game;
    }
}

void replace_gameobject(global_data_t *gdata, node_t *node, game_object_t *game)
{
    game_object_t *tmp = node->gameobjects;
    game_object_t *tmp_prev = NULL;

    while (tmp != NULL
    && cmp_string(tmp->node, game->node) == 0
    && tmp->layer < game->layer) {
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    game->prev = tmp_prev;
    game->next = tmp;
    if (tmp_prev != NULL)
        tmp_prev->next = game;
    switch_gameobject(gdata, tmp, game, node);
}

void gameobject_set_layer(global_data_t *data, char *name, int layer)
{
    game_object_t *game = gameobject_get(data, name);
    node_t *node = NULL;

    if (game == NULL) {
        my_printf("%s%s%s doesn't exist.%s\n", PURPLE, name, LRED, RESET);
        return;
    }
    if (game->layer == layer)
        return;
    node = node_get(data, game->node);
    my_printf("%sgameobject_set_layer: set %s%s%s layer to %s%i%s.%s\n"
    , YELLOW, PURPLE, name, YELLOW, PURPLE, layer, YELLOW, RESET);
    game->layer = layer;
    gameobject_remove_from_list(data, node, game);
    replace_gameobject(data, node, game);
}