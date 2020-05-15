/*
** EPITECH PROJECT, 2019
** button_texture.c
** File description:
** define texture button
*/

#include "rpg.h"

void button_set_texture(global_data_t *data, char *name, sfTexture *texture)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->stand = texture;
    button_set_press_position(data, button->gameobject->name,
    (sfVector2f) {0, 0});
}

void button_set_other_texture(global_data_t *data, char *name, sfTexture *hover,
sfTexture *press)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    button->hover = hover;
    button->press = press;
}

void button_set_help_texture(global_data_t *data, char *name, sfTexture *help)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    sfSprite_setTexture(button->help_sprite, help, sfTrue);
}