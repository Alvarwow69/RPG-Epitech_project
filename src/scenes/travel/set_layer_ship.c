/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** set_layer_ship
*/

#include "rpg.h"

void set_layer_ship4(global_data_t *data)
{
    if (data->travel->x_map == 6 && (data->travel->y_map == 2))
        gameobject_set_layer(data, "ship", 8);
    if (data->travel->x_map == 6 && (data->travel->y_map == 1))
        gameobject_set_layer(data, "ship", 8);
    if (data->travel->x_map == 3 && (data->travel->y_map == 2))
        gameobject_set_layer(data, "ship", 12);
    if (data->travel->x_map == 3 && (data->travel->y_map == 1))
        gameobject_set_layer(data, "ship", 12);
    if (data->travel->x_map == 3 && (data->travel->y_map == 0))
        gameobject_set_layer(data, "ship", 12);
    if (data->travel->x_map == 2 && (data->travel->y_map == 0))
        gameobject_set_layer(data, "ship", 12);
}

void set_layer_ship(global_data_t *data)
{
    gameobject_set_layer(data, "ship", 40);
    set_layer_ship4(data);
    if (data->travel->x_map == 3 && (data->travel->y_map == 4))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 3 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 4 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 5 && (data->travel->y_map == 6))
        gameobject_set_layer(data, "ship", 16);
    if (data->travel->x_map == 6 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 16);
    if (data->travel->x_map == 6 && (data->travel->y_map == 6))
        gameobject_set_layer(data, "ship", 16);
}

void set_layer_ship3(global_data_t *data)
{
    if (data->travel->x_map == 6 && (data->travel->y_map == 2))
        gameobject_set_layer(data, "ship", 8);
    if (data->travel->x_map == 6 && (data->travel->y_map == 1))
        gameobject_set_layer(data, "ship", 8);
    if (data->travel->x_map == 3 && (data->travel->y_map == 3))
        gameobject_set_layer(data, "ship", 40);
    if (data->travel->x_map == 3 && (data->travel->y_map == 1))
        gameobject_set_layer(data, "ship", 12);
    if (data->travel->x_map == 3 && (data->travel->y_map == 0))
        gameobject_set_layer(data, "ship", 12);
    if (data->travel->x_map == 2 && (data->travel->y_map == 0))
        gameobject_set_layer(data, "ship", 12);
}

void set_layer_ship2(global_data_t *data)
{
    set_layer_ship3(data);
    if (data->travel->x_map == 3 && (data->travel->y_map == 4))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 3 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 4 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 18);
    if (data->travel->x_map == 4 && (data->travel->y_map == 6))
        gameobject_set_layer(data, "ship", 40);
    if (data->travel->x_map == 6 && (data->travel->y_map == 5))
        gameobject_set_layer(data, "ship", 16);
    if (data->travel->x_map == 6 && (data->travel->y_map == 6))
        gameobject_set_layer(data, "ship", 16);
}