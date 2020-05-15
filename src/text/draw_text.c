/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** draw_text.c
*/

#include "rpg.h"

void draw_text(global_data_t *data, game_object_t *game, sfRenderStates state)
{
    if (game->object.text->view)
        sfRenderWindow_setView(data->window, game->object.text->view);
    sfRenderWindow_drawText(data->window, game->object.text->text, &state);
}