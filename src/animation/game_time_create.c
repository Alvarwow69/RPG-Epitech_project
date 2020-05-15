/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** game_time.c
*/

#include "rpg.h"

game_time_t *game_time_create(void)
{
    game_time_t *time = malloc(sizeof(game_time_t));

    time->actual = 0;
    time->last = 0;
    time->dif = 0;
    return (time);
}