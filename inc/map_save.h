/*
** EPITECH PROJECT, 2020
** map_save.h
** File description:
** 
*/

#ifndef MUL_RPG_2019_MAP_SAVE
#define MUL_RPG_2019_MAP_SAVE

#include "rpg.h"

typedef struct map_save_s
{
    int **background_block;
    int **background_ore;
    int **ground_block;
    int **ground_ore;
} map_save_t;

#endif //MUL_RPG_2019_MAP_SAVE
