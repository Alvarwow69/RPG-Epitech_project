/*
** EPITECH PROJECT, 2019
** button_define_1.c
** File description:
** define some properties
*/

#include "rpg.h"

void button_set_clickable(global_data_t *data, char *name, int clickable)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->is_clickable = clickable;
}

void button_set_layer(global_data_t *data, char *name, int layer)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    gameobject_set_layer(data, button->gameobject->name, layer);
}

void button_set_tex_rect(global_data_t *data, char *name, sfIntRect rect)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->set_rect = rect;
}

void button_set_hover_rect(global_data_t *data, char *name, sfIntRect rect)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->hover_rect = rect;
}

void button_set_click_rect(global_data_t *data, char *name, sfIntRect rect)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->click_rect = rect;
}