/*
** EPITECH PROJECT, 2019
** button_help.c
** File description:
** define help pos
*/

#include "rpg.h"

void button_set_help_position(global_data_t *data, char *name, sfVector2f pos)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    sfTransformable_setPosition(button->h_transform, pos);
}