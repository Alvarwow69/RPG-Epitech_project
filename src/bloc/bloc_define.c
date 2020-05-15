/*
** EPITECH PROJECT, 2020
** bloc_define.c
** File description:
** 
*/

#include "rpg.h"

void bloc_set_texture(global_data_t *data, char *name, sfTexture *texture)
{
    bloc_t *bloc = bloc_get(data, name);

    if (!bloc)
        return;
    sfSprite_setTexture(bloc->sprite, texture, sfTrue);
}

void bloc_set_scale(global_data_t *data, char *name, sfVector2f scale)
{
    bloc_t *bloc = bloc_get(data, name);

    if (!bloc)
        return;
    sfSprite_setScale(bloc->sprite, scale);
}

void bloc_set_texture_rect(global_data_t *data, char *name, sfIntRect rect)
{
    bloc_t *bloc = bloc_get(data, name);

    if (!bloc) {
        my_printf("%sbloc_set_texture_rect: can't set %"
        "s%s%s texture rect.%s\n", LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfSprite_setTextureRect(bloc->sprite, rect);
}