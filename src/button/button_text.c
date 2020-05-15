/*
** EPITECH PROJECT, 2020
** button_text.c
** File description:
** define text on the button
*/

#include "rpg.h"

void button_set_text(global_data_t *data, char *name, char *str, sfFont *font)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    if (!button->text)
        button->text = sfText_create();
    sfText_setString(button->text, str);
    sfText_setFont(button->text, font);
}

void button_set_text_pos(global_data_t *data, char *name, sfVector2f pos)
{
    button_t *button = button_get(data, name);
    sfVector2f new_pos;
    sfVector2f button_pos;

    if (!button || !button->text)
        return;
    button_pos = sfTransformable_getPosition(button->gameobject->transform);
    new_pos.x = pos.x + button_pos.x;
    new_pos.y = pos.y + button_pos.y;
    sfTransformable_setPosition(button->text_pos, new_pos);
}

void button_set_text_scale(global_data_t *data, char *name, int size)
{
    button_t *button = button_get(data, name);

    if (!button || !button->text)
        return;
    sfText_setCharacterSize(button->text, size);
}

void button_set_text_color(global_data_t *data, char *name, sfColor color)
{
    button_t *button = button_get(data, name);

    if (!button || !button->text)
        return;
    sfText_setColor(button->text, color);
}