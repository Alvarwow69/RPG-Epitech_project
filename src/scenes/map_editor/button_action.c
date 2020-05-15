/*
** EPITECH PROJECT, 2020
** button_action.c
** File description:
** 
*/

#include <engine/gameobject.h>
#include "rpg.h"

void editor_main_action(global_data_t *data, button_t*button)
{
    (void)button;
    scene_draw(data, "main", true, false);
}

void editor_change_bloc(global_data_t *data, button_t *button)
{
    char **name = str_to_tab(button->gameobject->name, "-");

    data->selected_block = get_number(name[1]);
}

void editor_hide(global_data_t *data, button_t *button)
{
    char *name = NULL;

    gameobject_destroy(data, button->gameobject->name);
    create_button_selection(data);
    for (int i = 0; i < TM_END; i++) {
        name = concat_fstring("block-%i", i);
        gameobject_destroy(data, name);
    }
}

void editor_change(global_data_t *data, button_t *button)
{
    (void)button;
    data->remove_tile = 0;
}

void editor_remove(global_data_t *data, button_t *button)
{
    (void)button;
    data->remove_tile = 1;
}