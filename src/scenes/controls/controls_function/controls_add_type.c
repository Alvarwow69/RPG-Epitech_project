/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_add_type
*/

#include "rpg.h"

void add_type_controls_struct(global_data_t *data, char *name_node)
{
    type_controls_t *new = malloc(sizeof(type_controls_t));
    new->name = name_node;
    new->pos = (sfVector2f) {0, 100};
    new->first = NULL;
    new->next = data->controls->list_type->first;
    data->controls->list_type->first = new;

}