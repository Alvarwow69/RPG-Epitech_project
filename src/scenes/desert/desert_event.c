/*
** EPITECH PROJECT, 2020
** desert_event.c
** File description:
** 
*/

#include "rpg.h"

void desert_key(global_data_t *data, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    node_t *inv = node_get(data, "p_inv_node");
    node_t *shop = node_get(data, "shop_node");
    sfVector2f pixel_pos;

    if (get_controls_event(data, "Attaque")) {
        pixel_pos = sfRenderWindow_mapPixelToCoords\
(data->window, mouse_pos, scene->game);
        bloc_add_map(data, pixel_pos);
        if (inv->is_active == true)
            check_button(data, sfMouse_get\
PositionRenderWindow(data->window), scene->interface, inv);
        if (shop->is_active == true)
        check_button(data, sfMouse_get\
PositionRenderWindow(data->window), scene->interface, shop);
        destroy_block(data, pixel_pos);
    }
    if (get_controls_event(data, "Pause")) {
        scene_draw(data, "pause", false, false);
        data->prev_game = scene;
    }
}

void desert_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "desert");

    sfMusic_setLoop(data->ressources->musics[MUSIC_SAND], sfTrue);
    play_music_wait(data, MUSIC_SAND);
    desert_key(data, scene);
    update_camera(data);
    map_key(data, scene);
    collide_shape_check_all(data);
    collide_bloc_check_all(data);
    collide_b_b_check_all(data);
    ui_update(data);
    update_block(data, scene);
    player_update(data);
    water_update(data, scene);
    pnj_update_all(data);
}