/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_event
*/

#include "rpg.h"

void mouse_wheel_up_move(global_data_t *data, \
scene_t *scene, node_t *node_tmp)
{
    (void)scene;
    if (!(cmp_string(node_tmp->name, "background_controls_2") == 0 || \
cmp_string(node_tmp->name, "background_controls") == 0 || cmp_string\
(node_tmp->name, "controls") == 0))
        node_move(data, node_tmp->name, (sfVector2f) {0, -10});
}

void mouse_wheel_up(global_data_t *data)
{
    scene_t *scene = scene_get(data, "controls");
    node_t *node_tmp = scene->node;

    if (data->key->mouse_wheel == 1)
        while (node_tmp != NULL && \
cmp_string(node_tmp->scene, "controls") == 0) {
            mouse_wheel_up_move(data, scene, node_tmp);
            node_tmp = node_tmp->next;
        }
}

void mouse_wheel_down_move(global_data_t *data, \
scene_t *scene, node_t *node_tmp)
{
    (void)scene;
    if (!(cmp_string(node_tmp->name, "background_controls_2") == 0 || \
cmp_string(node_tmp->name, "background_controls") == 0 || cmp_string\
(node_tmp->name, "controls") == 0))
        node_move(data, node_tmp->name, (sfVector2f) {0, 10});
}

void mouse_wheel_down(global_data_t *data)
{
    scene_t *scene = scene_get(data, "controls");
    node_t *node_tmp = scene->node;

    if (data->key->mouse_wheel == -1)
        while (node_tmp != NULL && cmp_string\
(node_tmp->scene, "controls") == 0) {
            mouse_wheel_down_move(data, scene, node_tmp);
            node_tmp = node_tmp->next;
        }
}

void controls_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "controls");
    node_t *node_tmp = scene->node;

    mouse_wheel_down(data);
    mouse_wheel_up(data);

    if (data->key->left_click)
        while (node_tmp != NULL && cmp_string(node_tmp->scene, \
"controls") == 0) {
            check_button(data, sfMouse_getPositionRenderWindow(data->window), \
scene->interface, node_tmp);
            node_tmp = node_tmp->next;
        }
}