/*
** EPITECH PROJECT, 2020
** editor_create_bloc.cpp
** File description:
** 
*/

#include "rpg.h"

void change_tile(global_data_t *data, game_object_t *game)
{
    char **name = str_to_tab(game->name, "-");

    free(game->name);
    game->name = concat_fstring("tile-%s-%s-%i", name[1], name[2],
    data->selected_block);
    gameobject_set_texture_rect(data, game->name,
    tile_map[data->selected_block].rect);
}

void define_new_layer(global_data_t *data, node_t *node, char *name, int layer)
{
    static int first = -1;

    first = (!cmp_string(node->name, node->gameobjects->next->node)) ? 0 : 1;
    if (!first)
        gameobject_set_layer(data, name, 10);
    else
        first = 0;
    if (data->background) {
        if (layer == 1)
            gameobject_set_layer(data, name, -2);
        else
            gameobject_set_layer(data, name, -1);
    } else
        gameobject_set_layer(data, name, layer);
}

void create_new_tile(global_data_t *data, char *name, sfVector2i tile_pos,
int layer)
{
    node_t *node = node_get(data, "node_map_editor");

    gameobject_create(data, name, "node_map_editor", TYPE_IMAGE);
    gameobject_set_texture(data, name,
    data->ressources->textures[TEXTURE_TILE_MAP]);
    gameobject_set_texture_rect(data, name,
    tile_map[data->selected_block].rect);
    gameobject_set_position(data, name,
    (sfVector2f){(float)tile_pos.x * 48, (float)tile_pos.y * 48});
    define_new_layer(data, node, name, layer);
}

void add_ore(global_data_t *data, char *name, game_object_t *game)
{
    char **name_list = str_to_tab(name, "-");
    char **go_list = NULL;
    game_object_t *gameobject = game;

    while (gameobject && !cmp_string(gameobject->node, "node_map_editor")) {
        go_list = str_to_tab(gameobject->name, "-");
        if (get_number(name_list[1]) == get_number(go_list[1]) &&
            get_number(name_list[2]) == get_number(go_list[2]))
            change_tile(data, gameobject);
        gameobject = gameobject->next;
    }
    create_new_tile(data, name, (sfVector2i){get_number(name_list[1])\
, get_number(name_list[2])}, 2);
}

void add_block(global_data_t *data, char *name)
{
    char **name_list = str_to_tab(name, "-");

    create_new_tile(data, name,
    (sfVector2i){get_number(name_list[1]), get_number(name_list[2])}, 1);
}