/*
** EPITECH PROJECT, 2020
** create_water.c
** File description:
** 
*/

#include "rpg.h"

void free_name(char **str)
{
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}

void create_water_bloc(global_data_t *data, scene_t *scene,
sfVector2i tile_pos, int name_index)
{
    char *name = NULL;
    char *name_tile = NULL;

    name = concat_fstring("Water-%i", name_index);
    name_tile = concat_fstring("tile-%i-%i-%i", tile_pos.x, tile_pos.y, 1);
    if (gameobject_get(data, name_tile))
        return;
    node_create(data, name, scene->name);
    bloc_create(data, name_tile, name, 1);
    bloc_set_texture(data, name_tile,
    data->ressources->textures[TEXTURE_WATER]);
    gameobject_set_position(data, name_tile,
    (sfVector2f) {(float) tile_pos.x * 48, (float) tile_pos.y * 48});
}

void create_water_tile(global_data_t *data, scene_t *scene, sfVector2i pos)
{
    int name_index = 0;
    sfVector2f pixel_pos;
    sfVector2i tile_pos;
    sfVector2f map = sfTransformable_getPosition
    (node_get(data, "map_level-map-0")->transform);

    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, pos, scene->game);
    tile_pos.x = ((abs((int) map.x) + (int) pixel_pos.x) / 48);
    tile_pos.y = ((abs((int) map.y) + (int) pixel_pos.y) / 48);
    while (node_get(data, concat_fstring("Water-%i", name_index)))
        name_index += 1;
    create_water_bloc(data, scene, tile_pos, name_index);
}