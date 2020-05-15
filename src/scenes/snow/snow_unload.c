/*
** EPITECH PROJECT, 2020
** map_unload.c
** File description:
** 
*/

#include "rpg.h"

void snow_unload(global_data_t *data)
{
    scene_t *scene = scene_get(data, "snow");

    player_to_save(data);
    create_save(data);
    for (node_t *node = scene->node;
        node != NULL && cmp_string(node->scene, scene->name) == 0;
        node = scene->node)
        node_destroy(data, node->name);
    sfMusic_stop(data->ressources->musics[MUSIC_SNOW]);
}