/*
** EPITECH PROJECT, 2020
** add_tile.c
** File description:
** 
*/

#include "rpg.h"

void check_bloc(global_data_t *data, char **name_list, char *name,
game_object_t *game)
{
    int gameobject_layer = gameobject_get_layer(data, game->name);
    int current_layer = (data->background) ? -2 : 1;

    if (data->selected_block >= 1 && data->selected_block <= 5 &&
    get_number(name_list[3]) > 5) {
        add_ore(data, name, game->next);
    } else if (data->selected_block > 5 && gameobject_layer == current_layer) {
        change_tile(data, game);
    } else {
        add_block(data, name);
    }
}

int same_pos(global_data_t *data, int x, int y, char *name)
{
    game_object_t *game = node_get(data, "node_map_editor")->gameobjects;
    char **name_list = NULL;

    while (game && !cmp_string(game->node, "node_map_editor")) {
        if (!cmp_string(name, game->name) && \
gameobject_get_layer(data, game->name) >= 0)
            return (1);
        name_list = str_to_tab(game->name, "-");
        if (get_number(name_list[1]) == x &&
        get_number(name_list[2]) == y) {
            check_bloc(data, name_list, name, game);
            return (1);
        }
        game = game->next;
    }
    return (0);
}

void remove_tile(global_data_t *data, sfVector2i pos)
{
    game_object_t *game = node_get(data, "node_map_editor")->gameobjects;
    char **name_list = NULL;

    while (game && !cmp_string(game->node, "node_map_editor")) {
        name_list = str_to_tab(game->name, "-");
        if (get_number(name_list[1]) == (int)pos.x &&
        get_number(name_list[2]) == (int)pos.y) {
            gameobject_destroy(data, game->name);
            return;
        }
        game = game->next;
    }
}

sfVector2i get_pos(global_data_t *data, sfVector2i position, sfView *game)
{
    sfVector2f pixel_pos;
    sfVector2f map = sfTransformable_getPosition
    (node_get(data, "node_map_editor")->transform);
    sfVector2i tile_pos;

    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, position, game);
    tile_pos.x = ((abs((int)map.x) + (int)pixel_pos.x) / 48);
    tile_pos.y = ((abs((int)map.y) + (int)pixel_pos.y) / 48);
    return (tile_pos);
}

void add_tile(global_data_t *data, sfVector2i position, sfView *game)
{
    sfVector2i tile_pos;
    char *name = NULL;

    tile_pos = get_pos(data, position, game);
    if (data->remove_tile) {
        remove_tile(data, tile_pos);
        return;
    }
    check_size(data, tile_pos);
    name = concat_fstring("tile-%i-%i-%i",
    tile_pos.x, tile_pos.y, data->selected_block);
    if (same_pos(data, tile_pos.x, tile_pos.y, name))
        return;
    if (data->selected_block >= 1 && data->selected_block <= 5)
        create_new_tile(data, name, tile_pos, 2);
    else
        create_new_tile(data, name, tile_pos, 1);
}