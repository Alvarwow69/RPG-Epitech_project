/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** move_ship_map_down
*/

#include "rpg.h"

void move_ship_down2(global_data_t *data)
{
    if (data->travel->map[data->travel->y_map][data->travel->x_map-1] == '4') {
        scene_draw(data, "snow", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map][data->travel->x_map-1] == '3') {
        scene_draw(data, "desert", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map][data->travel->x_map-1] == '2') {
        scene_draw(data, "map", true, true);
        data->travel->leave_travel = 0;
    }
    if (data->travel->map[data->travel->y_map][data->travel->x_map-1] == '1') {
        scene_draw(data, "cave", true, true);
        data->travel->leave_travel = 0;
    }
}

void move_ship_down(global_data_t *data)
{
    if (data->travel->move == DOWN) {
        if (data->travel->x_map == 0) {
            data->travel->move = 0;
            return;
        }
        move_ship_down2(data);
        if ((data->travel->x_map > 0) && (data->travel->map\
[data->travel->y_map][data->travel->x_map-1] == '.')) {
            data->travel->map[data->travel->y_map][data->travel->x_map] = '.';
            data->travel->x_map--;
            data->travel->map[data->travel->y_map][data->travel->x_map] = 'S';
            set_layer_ship2(data);
        }
        else
            data->travel->move = 0;
    }
}