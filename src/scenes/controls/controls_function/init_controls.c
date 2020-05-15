/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_controls
*/

#include "rpg.h"

void init_controls(global_data_t *data)
{
    data->controls = malloc(sizeof(controls_t));
    data->controls->scale_background = 0;
    data->controls->list_type = malloc(sizeof(list_type_controls_t));
    data->controls->list_type->first = malloc(sizeof(type_controls_t));
    data->controls->list_type->first->next = NULL;
}