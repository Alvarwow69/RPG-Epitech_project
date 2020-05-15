/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** map
*/

#include "rpg.h"

void travel_act_keybind(global_data_t *data)
{
    if (data->travel->move == 0 && get_controls_event(data, "Nord") == 1) {
        data->travel->pos_ship = gameobject_get_local_position(data, "ship");
        gameobject_set_texture(data, "ship", \
data->ressources->textures[TRAVEL_SHIP_E]);
        data->travel->move = UP;
        move_ship_map(data);
    }
    travel_act_keybing_2(data);
    if (get_controls_event(data, "Est") == 1 && data->travel->move == 0) {
        data->travel->pos_ship = gameobject_get_local_position(data, "ship");
        gameobject_set_texture(data, "ship", \
data->ressources->textures[TRAVEL_SHIP_S]);
        data->travel->move = RIGHT;
        move_ship_map(data);
    }
}

void travel_gest_view_scene(global_data_t *data, scene_t *scene)
{
    scene->size_game.x = sfRenderWindow_getSize(data->window).x;
    scene->size_game.y = sfRenderWindow_getSize(data->window).y;
    sfView_setSize(scene->game, (sfVector2f) {scene->size_game.x, \
scene->size_game.y});
    if (data->key->left_click == 1 && data->travel->tmp == 0) {
        data->travel->move_center_map = sfView_getCenter(scene->game);
        data->travel->t_map = sfMouse_getPositionRenderWindow(data->window);
        data->travel->tmp = 1;
    }
}

void travel_gest_view(global_data_t *data, scene_t *scene)
{
    travel_gest_view_scene(data, scene);
    if (data->key->left_click == 1 && data->travel->tmp == 1) {
        data->travel->t_diff_map = \
sfMouse_getPositionRenderWindow(data->window);
        data->travel->center_map.x = ((data->travel->\
t_diff_map.x - data->travel->t_map.x)*1);
        data->travel->center_map.y = ((data->travel->\
t_diff_map.y - data->travel->t_map.y)*1);
        sfView_setCenter(scene->game, (sfVector2f) {data->travel->\
move_center_map.x - data->travel->center_map.x, data->travel->\
move_center_map.y - data->travel->center_map.y});
        sfRenderWindow_setView(data->window, scene->game);
    }
    if (data->key->left_click == 0 && data->travel->tmp == 1)
        data->travel->tmp = 0;
}

void travel_act(global_data_t *data)
{
    scene_t *scene = scene_get(data, "travel");

    start_travel(data, START);
    if (cmp_string(data->active_scene->name, "travel") == 0) {
        sfMusic_setLoop(data->ressources->musics[MUSIC_TRAVEL], sfTrue);
        play_music_wait(data, MUSIC_TRAVEL);
        travel_act_keybind(data);
        move_ship(data);
        travel_gest_view(data, scene);
    }
}

void start_travel(global_data_t *data, isle_e isle)
{
    if (cmp_string(data->active_scene->name, "travel") == 0) {
        if (isle == START && data->travel->start_travel == 0) {
            gameobject_set_position(data, "ship", (sfVector2f){175, 755});
            gameobject_set_texture(data, "ship", \
data->ressources->textures[TRAVEL_SHIP_S]);
            gameobject_set_layer(data, "ship", 40);
            data->travel->map[6][1] = 'S';
            data->travel->x_map = 1;
            data->travel->y_map = 6;
            data->travel->start_travel = 1;
        }
    }
}