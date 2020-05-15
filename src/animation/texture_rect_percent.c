/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** texture_rect_percent.c
*/

#include "rpg.h"

void texture_rect_percent(sfSprite *spr, sfIntRect rect
                         , float percent, char *direction)
{
    sfIntRect actual = sfSprite_getTextureRect(spr);
    sfIntRect result = rect;

    if (cmp_string(direction, "top") == 0) {
        result.top = (rect.top + rect.height) - ((rect.height * percent) / 100);
        result.height = (rect.top + rect.height) - result.top;
    }
    else if (cmp_string(direction, "left") == 0) {
        result.left = rect.width - ((rect.width * percent) / 100);
        result.width = rect.height - result.top;
    }
    else if (cmp_string(direction, "bottom") == 0)
        result.height = (rect.height * percent) / 100;
    else if (cmp_string(direction, "right") == 0)
        result.width = (rect.width * percent) / 100;
    sfSprite_move(spr, (sfVector2f){result.left - actual.left
                                   , result.top - actual.top});
    sfSprite_setTextureRect(spr, result);
}