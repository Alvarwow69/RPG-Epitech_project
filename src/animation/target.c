/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** target.c
*/

#include "rpg.h"

target_t *target_create(sfVector2f pos, float loop_time)
{
    target_t *target = malloc(sizeof(target_t));

    target->pos = pos;
    target->loop_time = loop_time;
    target->time = game_time_create();
    return (target);
}

void target_destroy(target_t *target)
{
    free(target->time);
    free(target);
}

bool check_loop(target_t *target, sfClock *clock)
{
    target->time->last = target->time->actual;
    target->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    target->time->dif += target->time->actual - target->time->last;
    if (target->time->dif >= target->loop_time) {
        target->time->dif = 0;
        return (true);
    }
    return (false);
}

sfVector2f move_transform_to_target
(sfTransformable *transform, target_t *target, sfClock *clock, float cel)
{
    sfVector2f pos = sfTransformable_getPosition(transform);
    float vector[3] = {0, 0, 0};
    float x = 0;
    float y = 0;

    if (check_loop(target, clock) == true)
        return ((sfVector2f) {0, 0});
    vector[0] = target->pos.x - pos.x;
    vector[1] = target->pos.y - pos.y;
    if (vector[0] != 0 && vector[1] != 0) {
        vector[2] = sqrt(pow(vector[0], 2) + pow(vector[1], 2));
        if (vector[2] > cel) {
            x = vector[0] / (vector[2] / cel);
            y = vector[1] / (vector[2] / cel);
        }
    }
    return ((sfVector2f){x, y});
}