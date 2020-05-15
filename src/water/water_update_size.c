/*
** EPITECH PROJECT, 2020
** water_update_size.c
** File description:
** 
*/

#include "rpg.h"

int get_first_layer(node_t *node)
{
    game_object_t *game = node->gameobjects;
    int layer = game->object.bloc->water_level;

    while (game && !cmp_string(game->node, node->name)) {
        if (game->object.bloc->water_level < layer)
            layer = game->object.bloc->water_level;
        game = game->next;
    }
    return (layer);
}

void destroy_water_level(global_data_t *data, node_t *node, int layer)
{
    game_object_t *game = node->gameobjects;
    game_object_t *delete = NULL;

    while (game && !cmp_string(game->node, node->name)) {
        if (game->object.bloc->water_level == layer) {
            delete = game;
            game = game->next;
            gameobject_destroy(data, delete->name);
            continue;
        }
        game = game->next;
    }
    if (!node->gameobjects)
        node_destroy(data, node->name);
}

float calcule_percent(node_t *node, int layer)
{
    game_object_t *game = node->gameobjects;
    int nbr_water = 0;
    float result = 0;

    while (game && !cmp_string(game->node, node->name)) {
        if (game->object.bloc->water_level == layer)
            nbr_water += 1;
        game = game->next;
    }
    result = 100 - (((float) nbr_water - 1) * 10);
    return ((result < 0) ? 0 : result);
}

void update_around_bloc(game_object_t *game, int layer, node_t *node)
{
    float percent = calcule_percent(node, layer);
    sfIntRect rect = {0, 0, 48, 48};

    if (game->object.bloc->percent <= percent &&
    node->gameobjects->object.bloc->water_level != layer) {
        game->object.bloc->percent -= 20;
        texture_rect_percent(game->object.bloc->sprite, rect,
        game->object.bloc->percent, "top");
    }
    else {
        texture_rect_percent(game->object.bloc->sprite, rect, percent, "top");
        game->object.bloc->percent = percent;
    }
}

void update_water_size(global_data_t *data, node_t *node)
{
    game_object_t *game = node->gameobjects;
    int layer = get_first_layer(node);
    float percent = calcule_percent(node, layer);

    if (layer == game->object.bloc->water_level && layer != 0)
        return;
    while (game && !cmp_string(game->node, node->name)) {
        if (game->object.bloc->water_level == layer) {
            if ((game->object.bloc->percent <= 0 || percent <= 0)) {
                destroy_water_level(data, node, layer);
                break;
            }
            update_around_bloc(game, layer, node);
        }
        game = game->next;
    }
}