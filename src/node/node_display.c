/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_display.c
*/

#include "rpg.h"

void node_display(node_t *node)
{
    for (node_t *tmp = node; tmp != NULL; tmp = tmp->next) {
        my_printf("=> %s :\n", tmp->name);
        my_printf("\tscene : %s\n", tmp->scene);
        my_printf("\tlayer : %i\n", tmp->layer);
    }
}