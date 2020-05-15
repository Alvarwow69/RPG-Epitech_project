/*
** EPITECH PROJECT, 2020
** cave_event.c
** File description:
** 
*/

#include "rpg.h"

void cave_key(global_data_t *data, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    node_t *inv = node_get(data, "p_inv_node");
    sfVector2f pixel_pos;

    if (get_controls_event(data, "Attaque")) {
        pixel_pos = sfRenderWindow_mapPixelToCoords\
(data->window, mouse_pos, scene->game);
        bloc_add_map(data, pixel_pos);
        if (inv->is_active == true)
            check_button(data, sfMouse_get\
PositionRenderWindow(data->window), scene->interface, inv);
        destroy_block(data, pixel_pos);
    }
    if (get_controls_event(data, "Pause")) {
        scene_draw(data, "pause", false, false);
        data->prev_game = scene;
    }
}

void cave_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "cave");

    sfMusic_setLoop(data->ressources->musics[MUSIC_CAVE], sfTrue);
    play_music_wait(data, MUSIC_CAVE);
    cave_key(data, scene);
    update_camera(data);
    map_key(data, scene);
    collide_shape_check_all(data);
    collide_bloc_check_all(data);
    collide_b_b_check_all(data);
    ui_update(data);
    update_block(data, scene);
    player_update(data);
    water_update(data, scene);
}