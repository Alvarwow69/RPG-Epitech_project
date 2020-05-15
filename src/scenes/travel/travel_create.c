/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** travel_create
*/

#include "rpg.h"

void travel_unload(global_data_t *data)
{
    (void)data;
    sfMusic_stop(data->ressources->musics[MUSIC_TRAVEL]);
}

void create_travel_scene(global_data_t *data)
{
    scene_create(data, "travel");
    scene_set_load(data, "travel", &travel_load);
    scene_set_unload(data, "travel", &travel_unload);
    scene_set_event(data, "travel", &travel_act_keybind);
}

void move_ship_map(global_data_t *data)
{
    move_ship_up(data);
    move_ship_down(data);
    move_ship_right(data);
    move_ship_left(data);
}

void travel_act_keybing_2(global_data_t *data)
{
    if (get_controls_event(data, "Sud") == 1 && data->travel->move == 0) {
        gameobject_set_texture(data, "ship", \
data->ressources->textures[TRAVEL_SHIP_W]);
        data->travel->move = DOWN;
        move_ship_map(data);
    }
    if (get_controls_event(data, "West") == 1 && data->travel->move == 0) {
        gameobject_set_texture(data, "ship", \
data->ressources->textures[TRAVEL_SHIP_N]);
        data->travel->move = LEFT;
        move_ship_map(data);
    }
}