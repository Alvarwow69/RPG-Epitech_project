/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** phisics.c
*/

#include "rpg.h"

void apply_gravity(move_t *move, sfClock *clock)
{
    move->time->last = move->time->actual;
    move->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    move->time->dif = move->time->actual - move->time->last;

    move->total_time += move->time->dif;
    move->vec.y = move->force + 9.81 * move->total_time;
}