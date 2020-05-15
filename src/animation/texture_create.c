/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** texture_create.c
*/

#include "rpg.h"

texture_t *texture_create(sfTexture *txt, bool repeat
                         , sfVector2f scale, sfIntRect tile_rect)
{
    texture_t *texture = malloc(sizeof(texture_t));

    texture->repeat = repeat;
    texture->scale = scale;
    texture->tile_size = (sfVector2u){tile_rect.width, tile_rect.height};
    texture->tile_rect = tile_rect;
    texture->txt_size = sfTexture_getSize(txt);
    return (texture);
}