/*
** EPITECH PROJECT, 2020
** game_camera.c
** File description:
** 
*/

#include "rpg.h"

sfVector2f update_camera2(global_data_t *data, \
sfVector2f move, sfVector2f cam_pos, sfVector2f player_pos)
{
    scene_t *scene = scene_get(data, node_get(data, "player_node")->scene);
    game_object_t *player = node_get(data, "player_node")->gameobjects;

    if (player_pos.x - cam_pos.x > 400 && cam_pos.x < scene->max_width) {
        move.x = player->object.player->move->vec.x;
        move.x *= (move.x < 0) ? -1 : 1;
    } else if (player_pos.x - cam_pos.x < -400 &&
    (cam_pos.x - player->object.player->move->vec.x > scene->init_pos.x)){
        move.x = -player->object.player->move->vec.x;
        move.x *= (move.x > 0) ? -1 : 1;
    }
    return (move);
}

void update_camera(global_data_t *data)
{
    game_object_t *player = node_get(data, "player_node")->gameobjects;
    scene_t *scene = scene_get(data, node_get(data, "player_node")->scene);
    sfVector2f player_pos = gameobject_get_g_position(data, player);
    sfVector2f cam_pos = sfView_getCenter(scene->game);
    sfVector2f move = {0, 0};

    move = update_camera2(data, move, cam_pos, player_pos);
    if (player_pos.y - cam_pos.y > 200 && cam_pos.y < scene->max_height) {
        move.y = player->object.player->move->vec.y;
        move.y *= (move.y < 0) ? -1 : 1;
    } else if (player_pos.y - cam_pos.y < -200){
        move.y = -player->object.player->move->vec.y;
        move.y *= (move.y > 0) ? -1 : 1;
    }
    sfView_move(scene->game, move);
}