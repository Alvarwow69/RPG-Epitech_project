/*
** EPITECH PROJECT, 2020
** editor_event.c
** File description:
** 
*/

#include "rpg.h"

void up_down(global_data_t *data, scene_t *scene)
{
    float offset = (get_controls_event(data, "Move up")) ? -5 : 5;
    sfVector2f pos = sfView_getCenter(scene->game);

    if (pos.y + offset < scene->init_pos.y)
        return;
    if (data->key->lmaj || data->key->rmaj)
        offset *= 2;
    sfView_move(scene->game, (sfVector2f) {0, offset});
}

void right_left(global_data_t *data, scene_t *scene)
{
    float offset = (get_controls_event(data, "Move right")) ? -5 : 5;
    sfVector2f pos = sfView_getCenter(scene->game);

    if (pos.x + offset < scene->init_pos.x)
        return;
    if (data->key->lmaj || data->key->rmaj)
        offset *= 2;
    sfView_move(scene->game, (sfVector2f) {offset, 0});
}

void move_cam(global_data_t *data, scene_t *scene)
{
    if (get_controls_event(data, "Move up") || \
get_controls_event(data, "Move down"))
        up_down(data, scene);
    if (get_controls_event(data, "Move right") || \
get_controls_event(data, "Move left"))
        right_left(data, scene);
}

void shortcut(global_data_t *data)
{
    if (get_controls_event(data, "Change level/background"))
        click_action(data, gameobject_get(data, "editor_b_background"));
}

void editor_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "map_editor");
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);

    if (data->key->left_click) {
        if (!check_button(data, mouse_pos, scene->interface,
            node_get(data, "interface_editor")) &&
            !check_button(data, mouse_pos, scene->interface,
            node_get(data, "selection_editor")))
            add_tile(data, mouse_pos, scene->game);
    }
    move_cam(data, scene);
    shortcut(data);
}