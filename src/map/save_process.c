/*
** EPITECH PROJECT, 2020
** save_process.c
** File description:
** 
*/

#include "rpg.h"

void set_end_line(map_save_t *map, scene_t *scene, int i)
{
    map->background_block[i][scene->map_width + 1] = -1;
    map->background_ore[i][scene->map_width + 1] = -1;
    map->ground_block[i][scene->map_width + 1] = -1;
    map->ground_ore[i][scene->map_width + 1] = -1;
    map->background_block[scene->map_height + 1] = NULL;
    map->background_ore[scene->map_height + 1] = NULL;
    map->ground_block[scene->map_height + 1] = NULL;
    map->ground_ore[scene->map_height + 1] = NULL;
}

void preprare_lists(map_save_t *map, scene_t *scene)
{
    int size = scene->map_height + 2;
    int size_w = scene->map_width + 2;

    map->background_block = malloc(sizeof(int *) * (size));
    map->background_ore = malloc(sizeof(int *) * (size));
    map->ground_block = malloc(sizeof(int *) * (size));
    map->ground_ore = malloc(sizeof(int *) * (size));
    for (int i = 0; i < scene->map_height + 1; i++) {
        map->background_block[i] = malloc(sizeof(int) * (size_w));
        map->background_ore[i] = malloc(sizeof(int) * (size_w));
        map->ground_block[i] = malloc(sizeof(int) * (size_w));
        map->ground_ore[i] = malloc(sizeof(int) * (size_w));
        for (int c = 0; c < scene->map_width + 1; c++) {
            map->background_block[i][c] = 00;
            map->background_ore[i][c] = 00;
            map->ground_block[i][c] = 00;
            map->ground_ore[i][c] = 00;
        }
        set_end_line(map, scene, i);
    }
}