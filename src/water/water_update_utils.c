/*
** EPITECH PROJECT, 2020
** water_update_utils.c
** File description:
** 
*/

#include "rpg.h"

int check_block(node_t *node, sfVector2i pos)
{
    game_object_t *game = node->gameobjects;
    char **tile_name = NULL;

    while (game && !cmp_string(game->node, node->name)) {
        tile_name = str_to_tab(game->name, "-");
        if (tile_name && get_number(tile_name[1]) == pos.x &&
        get_number(tile_name[2]) == pos.y) {
            free_name(tile_name);
            return (1);
        }
        free_name(tile_name);
        game = game->next;
    }
    return (0);
}

int is_water(global_data_t *data, sfVector2i pos, node_t *node)
{
    scene_t *scene = scene_get(data, node->scene);
    node_t *map_node = scene->node;

    while (map_node && !cmp_string(map_node->scene, scene->name)) {
        if (search_n_occurence(node->name, "Water-", 1) != -1
        && check_block(map_node, pos)) {
            return (1);
        }
        map_node = map_node->next;
    }
    return (0);
}

int get_solid_tile(global_data_t *data, sfVector2i pos, node_t *node)
{
    scene_t *scene = scene_get(data, node->scene);
    node_t *map_node = scene->node;

    while (map_node && !cmp_string(map_node->scene, scene->name)) {
        if (search_n_occurence(map_node->name, "map_level", 1) != -1
        && check_block(map_node, pos)) {
            return (1);
        }
        map_node = map_node->next;
    }
    return (is_water(data, pos, node));
}

game_object_t *create_new_water(global_data_t *data, node_t *node,
sfVector2i pos)
{
    char *name = concat_fstring("tile-%i-%i-%i", pos.x, pos.y, 1);

    bloc_create(data, name, node->name, 1);
    bloc_set_texture(data, name, data->ressources->textures[TEXTURE_WATER]);
    gameobject_set_position(data, name,
    (sfVector2f) {(float) pos.x * 48, (float) pos.y * 48});
    return (gameobject_get(data, name));
}