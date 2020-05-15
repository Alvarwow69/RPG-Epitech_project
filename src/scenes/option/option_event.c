/*
** EPITECH PROJECT, 2020
** option_event.c
** File description:
** 
*/

#include "rpg.h"

void option_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "setting");

    if (data->key->left_click)
        check_button(data, sfMouse_getPositionRenderWindow(data->window),
        scene->interface, node_get(data, "setting"));
}