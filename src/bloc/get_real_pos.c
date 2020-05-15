/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** get_real_pos
*/

#include "rpg.h"

sfVector2i get_real_pos(global_data_t *data, sfVector2f position,
char *node_name)
{
    sfVector2f map = sfTransformable_getPosition
    (node_get(data, node_name)->transform);
    sfVector2i tile_pos;

    tile_pos.x = ((abs((int)map.x % CHUNK) + (int)position.x) / 48);
    tile_pos.y = ((abs((int)map.y) + (int)position.y) / 48);
    return (tile_pos);
}