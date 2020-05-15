/*
** EPITECH PROJECT, 2020
** main_button_action.c
** File description:
** 
*/

#include "rpg.h"

void main_button_edit(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "map_editor", true, false);
}

void main_button_close(global_data_t *data, button_t *button)
{
    (void)button;
    destroy_all_sounds(data);
    destroy_all_music(data);
    sfRenderWindow_close(data->window);
}

void main_button_play(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, data->prev_game->name, true, true);
}

void main_button_setting(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "setting", false, false);
}