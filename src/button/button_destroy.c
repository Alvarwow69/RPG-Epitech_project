/*
** EPITECH PROJECT, 2020
** button_destroy.c
** File description:
** destroy all one button
*/

#include "rpg.h"

void button_destroy(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTransformable_destroy(button->h_transform);
    free(button);
}