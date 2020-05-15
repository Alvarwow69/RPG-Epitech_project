/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** move_create.c
*/

#include "rpg.h"

move_t *move_create(void)
{
    move_t *new = malloc(sizeof(move_t));

    new->vec = (sfVector2f){0, 0};
    new->force = 0;
    new->total_time = 0;
    new->time = game_time_create();
    return (new);
}