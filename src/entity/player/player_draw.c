/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_draw.c
*/

#include "rpg.h"

void player_draw(sfRenderWindow *rwindow, player_t *player, sfRenderStates states)
{
    sfRenderWindow_drawSprite(rwindow, player->animation->body_spr, &states);
    sfRenderWindow_drawSprite(rwindow, player->animation->legs_spr, &states);
    sfRenderWindow_drawSprite(rwindow, player->animation->head_spr, &states);
    sfRenderWindow_drawSprite(rwindow, player->animation->arms_spr, &states);
    if (player->inventory->wear->type == IT_WEARABLE
    && player->inventory->wear->wearable != NULL) {
        sfRenderWindow_drawSprite(rwindow, player->inventory->wear->wearable->spr, &states);
    }
}