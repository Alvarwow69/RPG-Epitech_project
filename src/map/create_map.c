/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** 
*/

#include "rpg.h"

void create_tile(global_data_t *data, char *name)
{
    bloc_set_texture(data, name, data->ressources->textures[TEXTURE_TILE_MAP]);
}

void create_bloc(global_data_t *data, char *node_name, int id, sfVector2i pos)
{
    char *name = NULL;
    int ore = (id > 5) ? 0 : 1;

    name = concat_fstring("tile-%i-%i-%i", pos.x, pos.y, id);
    bloc_create(data, name, node_name, id);
    create_tile(data, name);
    bloc_set_texture_rect(data, name,
    tile_map[id].rect);
    gameobject_set_position(data, name
    , (sfVector2f){(float)(pos.x % CHUNK) * 48
    , (float)pos.y * 48});
    set_layer_tile(data, name, ore, id);
}

void load_map(global_data_t *data, map_save_t *map, scene_t *scene)
{
    int node_index = 0;
    char *node_level = NULL;
    char *node_background = NULL;
    sfVector2i pos;

    for (int col = 0; col < scene->map_width; col++) {
        if (col % CHUNK == 0) {
            node_level = concat_fstring("map_level-%s-%i",
            scene->name, node_index);
            node_background = concat_fstring("map_background-%s-%i",
            scene->name, node_index);
            node_create(data, node_level, scene->name);
            node_create(data, node_background, scene->name);
            node_set_position(data, node_level, (sfVector2f){48.0f * CHUNK * (float)node_index, 0});
            node_set_position(data, node_background, (sfVector2f){48.0f * CHUNK * (float)node_index, 0});
            node_index += 1;
        }
        for (int line = 0; line < scene->map_height; line++) {
            pos.x = col;
            pos.y = line;
            if (map->background_block[line][col] != 0)
                create_bloc(data, node_background, map->background_block[line][col], pos);
            if (map->background_ore[line][col] != 0)
                create_bloc(data, node_background, map->background_ore[line][col], pos);
            if (map->ground_block[line][col] != 0)
                create_bloc(data, node_level, map->ground_block[line][col], pos);
            if (map->ground_ore[line][col] != 0)
                create_bloc(data, node_level, map->ground_ore[line][col], pos);
        }
    }
    while (!scene->node->gameobjects)
        node_destroy(data, scene->node->name);
}

void create_map(global_data_t *data, char *path, char *scene_name)
{
    map_save_t *map = malloc(sizeof(map_save_t));
    scene_t *scene = scene_get(data, scene_name);
    char **map_file = str_to_tab(read_read_file(path), "\n");
    int line = 0;
    int col = 0;
    char **tmp = str_to_tab(map_file[0], ":");
    int x = 0;
    int y = 0;
    char **line_content = NULL;
    char **bloc_content = NULL;

    for (line = 0; map_file[line]; line++);
    for (col = 0; tmp[col]; col++);
    scene->map_width = col;
    scene->map_height = line;
    preprare_lists(map, scene);
    for (int line_t = 0; map_file[line_t]; line_t++) {
        line_content = str_to_tab(map_file[line_t], ":");
        for (int bloc = 0; line_content[bloc]; bloc++) {
            bloc_content = str_to_tab(line_content[bloc], "/");
            load_bloc(map, bloc_content, (sfVector2i){x, y});
            x += 1;
            scene->map_width = bloc;
        }
        y += 1;
        x = 0;
        scene->map_height = line_t;
    }
    load_map(data, map, scene);
}