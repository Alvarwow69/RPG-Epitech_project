/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** move_ship_map_right
*/

#include "rpg.h"

void move_ship_right2(global_data_t *data)
{
    if (data->travel->map[data->travel->y_map+1][data->travel->x_map] == '4') {
        scene_draw(data, "snow", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map+1][data->travel->x_map] == '3') {
        scene_draw(data, "desert", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map+1][data->travel->x_map] == '2') {
        scene_draw(data, "map", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map+1][data->travel->x_map] == '1') {
        scene_draw(data, "cave", true, true);
        data->travel->leave_travel = 0;
    }
}

void move_ship_right(global_data_t *data)
{
    if (data->travel->move == RIGHT) {
        if (data->travel->y_map == 9) {
            data->travel->move = 0;
            return;
        }
        move_ship_right2(data);
        if ((data->travel->y_map < 9) && (data->travel->map\
[data->travel->y_map+1][data->travel->x_map] == '.')) {
            data->travel->map[data->travel->y_map][data->travel->x_map] = '.';
            data->travel->y_map++;
            data->travel->map[data->travel->y_map][data->travel->x_map] = 'S';
            set_layer_ship2(data);
        }
        else
            data->travel->move = 0;
    }
}