/*
** EPITECH PROJECT, 2020
** main_button_action.c
** File description:
** 
*/

#include "rpg.h"

void pause_button_menu(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "main", true, false);
    scene_unload(data, data->prev_game);
}

void pause_button_resume(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, data->prev_game->name, true, true);
}

void pause_button_setting(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "setting", false, false);
}