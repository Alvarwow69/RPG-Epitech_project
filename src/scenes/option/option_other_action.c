/*
** EPITECH PROJECT, 2020
** option_other_action.c
** File description:
** 
*/

#include "rpg.h"

void setting_main_menu(global_data_t *data)
{
    scene_draw(data, data->prev_scene->name, true, false);
}