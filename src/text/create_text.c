/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_text.c
*/

#include "rpg.h"

text_t *text_get(global_data_t *data, char *name)
{
    game_object_t *text = data->objects->game_object;

    while (text) {
        if (!cmp_string(text->name, name) && text->type == TYPE_TEXT)
            return (text->object.text);
        text = text->next;
    }
    my_printf("%stext_get: can't get %s%s%s text.%s\n"
    , LRED, PURPLE, name, LRED, RESET);
    return (NULL);
}

text_t *init_text_struct(game_object_t *game)
{
    text_t *text = malloc(sizeof(text_t));

    if (!text) {
        my_printf("%sText: can't create text.%s\n"
        , LRED, RESET);
        return (NULL);
    }
    text->text = sfText_create();
    text->gameobject = game;
    text->color = sfWhite;
    text->view = NULL;
    return (text);
}

void text_create(global_data_t *data, char *name, char *node)
{
    gameobject_create(data, name, node, TYPE_TEXT);
}