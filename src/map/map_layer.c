/*
** EPITECH PROJECT, 2020
** map_layer.c
** File description:
** 
*/

#include "rpg.h"

void set_layer_tile(global_data_t *data, char *name, int ore, int id)
{
    if (id == 0) {
        if (ore == 0)
            gameobject_set_layer(data, name, -2);
        else
            gameobject_set_layer(data, name, -1);
    } else {
        if (ore == 0)
            gameobject_set_layer(data, name, 1);
        else
            gameobject_set_layer(data, name, 2);
    }
}

void load_bloc(map_save_t *map, char **bloc_content, sfVector2i pos)
{
    char **ore_content = NULL;

    for (int ore = 0; bloc_content[ore]; ore++) {
        ore_content = str_to_tab(bloc_content[ore], "-");
        for (int i = 0; ore_content[i]; i++) {
            if (ore == 0) {
                if (i == 0)
                    map->background_block[pos.y][pos.x] = get_number(ore_content[i]);
                else
                    map->background_ore[pos.y][pos.x] = get_number(ore_content[i]);
            } else {
                if (i == 0)
                    map->ground_block[pos.y][pos.x] = get_number(ore_content[i]);
                else
                    map->ground_ore[pos.y][pos.x] = get_number(ore_content[i]);
            }
        }
    }
}