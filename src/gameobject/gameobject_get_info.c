/*
** EPITECH PROJECT, 2020
** gameobject_get_info.c
** File description:
** 
*/

#include "rpg.h"

int gameobject_get_layer(global_data_t *data, char *name)
{
    game_object_t *game = gameobject_get(data, name);

    if (!game)
        return (-1);
    return (game->layer);
}