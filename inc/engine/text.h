/*
** EPITECH PROJECT, 2019
** Test
** File description:
** text.h
*/

#ifndef TEXT_H
#define TEXT_H

#include "rpg.h"

struct text_s {
    game_object_t *gameobject;
    sfText *text;
    sfColor color;
    sfView *view;
};

void text_create(global_data_t *data, char *name, char *node);
void text_destroy(text_t *text);

text_t *init_text_struct(game_object_t *game);

text_t *text_get(global_data_t *data, char *name);

void text_set_message(global_data_t *data, char *name, char *msg);

void text_set_color(global_data_t *data, char *name, sfColor color);

void draw_text(global_data_t *data, game_object_t *game, sfRenderStates state);

void text_set_view(global_data_t *data, char *name, sfView *view);

void text_set_size(global_data_t *data, char *name, unsigned int size);

void text_set_font(global_data_t *data, char *name, sfFont *font);

#endif