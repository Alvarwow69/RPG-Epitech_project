/*
** EPITECH PROJECT, 2020
** map_editor_utils.c
** File description:
** 
*/

#include "rpg.h"

void check_size(global_data_t *data, sfVector2i pos)
{
    scene_t *scene = scene_get(data, "map_editor");

    if (pos.x > scene->map_width)
        scene->map_width += abs(pos.x - scene->map_width);
    if (pos.y > scene->map_height)
        scene->map_height += abs(pos.y - scene->map_height);
}