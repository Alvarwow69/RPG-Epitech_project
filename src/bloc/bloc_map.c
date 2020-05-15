/*
** EPITECH PROJECT, 2020
** bloc_map.c
** File description:
** 
*/

#include "rpg.h"

void bloc_add_map(global_data_t *data, sfVector2f pos)
{
    player_t *player = gameobject_get(data, "player_go")->object.player;
    char *name = NULL;
    int id = player->inventory->wear->id;
    node_t *node =
    node_get(data, get_chunk(data, player->body_collision)->node);
    int ore = (id <= 5) ? 1 : 0;
    sfVector2i gird_pos = get_real_pos(data, pos, node->name);

    id -= 14;
    if (id < 0)
        return;
    name = concat_fstring("tile-%i-%i-%i", gird_pos.x, gird_pos.y, id);
    bloc_create(data, name, node->name, id);
    bloc_set_texture(data, name, data->ressources->textures[TEXTURE_TILE_MAP]);
    bloc_set_texture_rect(data, name,
    tile_map[id].rect);
    gameobject_set_position(data, name
    , (sfVector2f){(float)(gird_pos.x % CHUNK * 48)
    , (float)gird_pos.y * 48});
    set_layer_tile(data, name, ore, id);
    delete_wear_item(data, player);
}