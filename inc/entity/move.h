/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** move.h
*/

#ifndef MOVE_H
#define MOVE_H

typedef struct object_movement_s move_t;

typedef enum move_e {
    M_STAND,
    M_SEET,
    M_SNICK,
    M_WALK,
    M_RUN,
    M_JUMP,
    M_FALL
} move;

#include "entity.h"

struct object_movement_s {
    sfVector2f vec;
    float force;
    float total_time;
    game_time_t *time;
};

/* Create a move_t structure */
move_t *move_create(void);

#endif