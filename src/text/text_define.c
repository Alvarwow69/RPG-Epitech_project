/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** check_text.c
*/

#include "rpg.h"

void text_set_message(global_data_t *data, char *name, char *msg)
{
    text_t *text = text_get(data, name);

    if (!text)
        return;
    sfText_setString(text->text, msg);
}

void text_set_color(global_data_t *data, char *name, sfColor color)
{
    text_t *text = text_get(data, name);

    if (!text)
        return;
    sfText_setColor(text->text, color);
}

void text_set_view(global_data_t *data, char *name, sfView *view)
{
    text_t *text = text_get(data, name);

    if (!text)
        return;
    text->view = view;
}

void text_set_size(global_data_t *data, char *name, unsigned int size)
{
    text_t *text = text_get(data, name);

    if (!text)
        return;
    sfText_setCharacterSize(text->text, size);
}

void text_set_font(global_data_t *data, char *name, sfFont *font)
{
    text_t *text = text_get(data, name);

    if (!text)
        return;
    sfText_setFont(text->text, font);
}