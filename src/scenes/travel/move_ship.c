/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** move_ship
*/

#include "rpg.h"

void move_ship3(global_data_t *data)
{
    if (data->travel->move == RIGHT)
        gameobject_set_position(data, "ship", (sfVector2f) \
{gameobject_get_local_position(data, "ship").x+1.667, \
gameobject_get_local_position(data, "ship").y+1});
    if (data->travel->move == LEFT)
        gameobject_set_position(data, "ship", (sfVector2f) \
{gameobject_get_local_position(data, "ship").x-1.667, \
gameobject_get_local_position(data, "ship").y-1});
}

void move_ship2(global_data_t *data)
{
    data->travel->time->dif = 0;
    data->travel->move_tmp++;
    move_ship3(data);
    if (data->travel->move == UP)
        gameobject_set_position(data, "ship", (sfVector2f) \
{gameobject_get_local_position(data, "ship").x+1.667, \
gameobject_get_local_position(data, "ship").y-1});
    if (data->travel->move == DOWN)
        gameobject_set_position(data, "ship", (sfVector2f) \
{gameobject_get_local_position(data, "ship").x-1.667, \
gameobject_get_local_position(data, "ship").y+1});
    if (data->travel->move_tmp >= 75) {
        data->travel->move = 0;
        data->travel->move_tmp = 0;
        set_layer_ship(data);
    }
}

void move_ship(global_data_t *data)
{
    scene_t *scene = scene_get(data, "travel");
    sfView_setCenter(scene->game, gameobject_get_local_position(data, "ship"));
    if (data->travel->move != 0) {
        data->travel->time->last = data->travel->time->actual;
        data->travel->time->actual = sfTime_asMicroseconds\
(sfClock_getElapsedTime(data->clock));
        data->travel->time->dif += data->travel->time->\
actual - data->travel->time->last;
        if (data->travel->time->dif >= 10000) {
            move_ship2(data);
        }
    }
}