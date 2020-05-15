/*
** EPITECH PROJECT, 2020
** water_update.c
** File description:
** 
*/

#include "rpg.h"

void create_around(global_data_t *data, node_t *node, sfVector2i tile_pos)
{
    if (!get_solid_tile(data, (sfVector2i) {tile_pos.x - 1, tile_pos.y}, node))
        create_new_water(data, node,
        (sfVector2i) {tile_pos.x - 1, tile_pos.y});
    if (!get_solid_tile(data, (sfVector2i) {tile_pos.x + 1, tile_pos.y}, node))
        create_new_water(data, node,
        (sfVector2i) {tile_pos.x + 1, tile_pos.y});
}

void update_tile(global_data_t *data, node_t *node)
{
    game_object_t *game = node->gameobjects;
    char **tile_name = NULL;
    sfVector2i tile_pos;
    game_object_t *new = NULL;

    while (game && !cmp_string(game->node, node->name)) {
        tile_name = str_to_tab(game->name, "-");
        tile_pos.x = get_number(tile_name[1]);
        tile_pos.y = get_number(tile_name[2]);
        if (!get_solid_tile(data,
        (sfVector2i) {tile_pos.x, tile_pos.y + 1}, node)) {
            new = create_new_water(data, node,
            (sfVector2i) {tile_pos.x, tile_pos.y + 1});
            new->object.bloc->water_level = game->object.bloc->water_level + 1;
            break;
        }
        create_around(data, node, tile_pos);
        game = game->next;
    }
    update_water_size(data, node);
}

void update_pack_water(global_data_t *data, scene_t *scene)
{
    node_t *node = scene->node;

    while (node && !cmp_string(node->scene, scene->name)) {
        if (search_n_occurence(node->name, "Water-", 1) != -1)
            update_tile(data, node);
        node = node->next;
    }
}

void water_update(global_data_t *data, scene_t *scene)
{
    static float update = 0.0f;
    sfTime time = sfClock_getElapsedTime(data->clock);

    if ((time.microseconds - update) / 1000000 < 0.4f)
        return;
    update_pack_water(data, scene);
    update = time.microseconds;
}