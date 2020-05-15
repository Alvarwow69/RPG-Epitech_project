/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** colide_shape_add_point.c
*/

#include "rpg.h"

sfVertex get_vertex(sfVector2f pos)
{
    sfVertex new;

    new.position = pos;
    new.color = sfRed;
    new.texCoords = (sfVector2f){0, 0};
    return (new);
}

void collide_shape_add_point(collide_shape_t *shape, sfVector2f pos)
{
    sfVertex vertex = get_vertex(pos);
    sfVector2f *new_points = malloc(sizeof(sfVector2f) * (shape->count_point + 1));

    sfVertexArray_append(shape->array, vertex);
    for (int ctr = 0; ctr < shape->count_point; ctr += 1)
        new_points[ctr] = shape->points[ctr];
    new_points[shape->count_point] = pos;
    shape->count_point += 1;
    free(shape->points);
    shape->points = new_points;
    shape->max.left = (pos.x < shape->max.left || shape->count_point == 1 ? pos.x : shape->max.left);
    shape->max.width = (pos.x > shape->max.width || shape->count_point == 1 ? pos.x : shape->max.width);
    shape->max.top = (pos.y < shape->max.top || shape->count_point == 1 ? pos.y : shape->max.top);
    shape->max.height = (pos.y > shape->max.height || shape->count_point == 1 ? pos.y : shape->max.height);
}