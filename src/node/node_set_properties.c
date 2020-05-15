/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_set_properties.c
*/

#include "rpg.h"

void node_move(global_data_t *gdata, char *name, sfVector2f offset)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_move: can't modify %s%s%s position%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_move(node->transform, offset);
}

void node_set_scale(global_data_t *gdata, char *name, sfVector2f scale)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_set_scale: can't modify %s%s%s scale%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_setScale(node->transform, scale);
}

void node_scale(global_data_t *gdata, char *name, sfVector2f scale)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_scale: can't modify %s%s%s scale%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_scale(node->transform, scale);
}

void node_set_rotation(global_data_t *gdata, char *name, float angle)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_set_rotation: can't modify %s%s%s rotation%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_setRotation(node->transform, angle);
}

void node_rotate(global_data_t *gdata, char *name, float angle)
{
    node_t *node = node_get(gdata, name);

    if (node == NULL) {
        my_printf("%snode_rotate: can't modify %s%s%s rotation%s"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_rotate(node->transform, angle);
}