/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_travel
*/

#include "rpg.h"

void init_travel(global_data_t *data)
{
    data->travel = malloc(sizeof(travel_t));

    data->travel->center_map = (sfVector2i) {0, 0};
    data->travel->t_map = (sfVector2i) {0, 0};
    data->travel->t_diff_map = (sfVector2i) {0, 0};
    data->travel->move_center_map = (sfVector2f) {0, 0};
    data->travel->tmp = 0;
    data->travel->move = 0;
    data->travel->start_travel = 0;
    data->travel->move_tmp = 0;
    data->travel->time = game_time_create();
    data->travel->choice_map = 0;
    data->travel->scale_ship = 0;
    data->travel->scale_background = 0;
    data->travel->leave_travel = 0;
}

void set_water(global_data_t *data, char *node, char *name, sfVector2i coord)
{
    gameobject_create(data, name, node, TYPE_IMAGE);
    gameobject_set_texture(data, name, \
data->ressources->textures[TRAVEL_WATER]);
    gameobject_set_position(data, name, (sfVector2f){coord.y, coord.x});
}