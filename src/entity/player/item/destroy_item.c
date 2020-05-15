/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** destroy_item.c
*/

#include "rpg.h"

void destroy_weapon(global_data_t *gdata, weapon_t *weapon)
{
    animation_destroy(weapon->anim);
    collide_shape_destroy(gdata, weapon->cshape->name);
    sfSprite_destroy(weapon->spr);
    free(weapon->txt);
    free(weapon);
}

void destroy_item(global_data_t *gdata, item_t *item)
{
    free(item->name);
    free(item->stats);
    if (item->wearable != NULL)
        destroy_weapon(gdata, item->wearable);
    else if (item->consumable != NULL)
        free(item->consumable);
    free(item);
}