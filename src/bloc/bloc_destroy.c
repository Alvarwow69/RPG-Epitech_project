/*
** EPITECH PROJECT, 2020
** bloc_destroy.c
** File description:
** 
*/

#include "rpg.h"

void bloc_destroy(global_data_t *data, bloc_t *bloc)
{
    sfSprite_destroy(bloc->sprite);
    collide_shape_destroy(data, bloc->collide_shape->name);
    free(bloc->move);
    free(bloc);
}