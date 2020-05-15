/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_add
*/

#include "rpg.h"

void add_ctrl_struct(global_data_t *data, sfKeyCode key, char *name, char *node)
{
    ctrl_t *new = malloc(sizeof(ctrl_t));
    type_controls_t *type = get_controls_type(data, node);

    new->name = name;
    new->base = key;
    new->actual = key;
    new->next = type->first;
    type->first = new;
}

void add_controls_set_up(global_data_t *data, \
char *name, char *node, type_controls_t *type)
{
    scene_t *scene = scene_get(data, "controls");

    text_create(data, name, node);
    gameobject_set_position(data, name, (sfVector2f) {850, type->pos.y});
    text_set_message(data, name, name);
    text_set_font(data, name, data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, name, 30);
    text_set_view(data, name, scene->interface);
    button_controls(data, name, node, type);
}

void add_controls_set(global_data_t *data, char *name, \
char *node, node_t *node_tmp)
{
    type_controls_t *type = data->controls->list_type->first;

    if (data->controls->tmp == 1) {
        node_move(data, node_tmp->name, (sfVector2f) {0, 50});
    }
    if (cmp_string(node, node_tmp->name) == 0) {
        while (cmp_string(type->name, node) != 0) {
            type = type->next;
        }
        data->controls->tmp = 1;
        add_controls_set_up(data, name, node, type);
        node_move(data, "controls_last", (sfVector2f) {0, 50});
        type->pos.y += 50;
    }
}

void add_controls(global_data_t *data, char *name, char *node, sfKeyCode key)
{
    scene_t *scene = scene_get(data, "controls");
    node_t *node_tmp = scene->node;
    data->controls->tmp = 0;

    add_ctrl_struct(data, key, name, node);
    while (node_tmp != NULL && cmp_string(scene->name, node_tmp->scene) == 0) {
        if (!(cmp_string(node_tmp->name, "background_controls_2") == 0 || \
cmp_string(node_tmp->name, "background_controls") == 0 || cmp_string(node_\
tmp->name, "controls") == 0 || cmp_string(node_tmp->name, "controls_first") \
== 0 || cmp_string(node_tmp->name, "controls_last") == 0)) {
            add_controls_set(data, name, node, node_tmp);
        }
        node_tmp = node_tmp->next;
    }
}

void add_type_controls(global_data_t *data, char *name_node, char *name)
{
    scene_t *scene = scene_get(data, "controls");
    node_t *node = scene->node;

    add_type_controls_struct(data, name_node);
    node_create(data, name_node, "controls");
    text_create(data, name_node, name_node);
    gameobject_set_position(data, name_node, (sfVector2f) {750, 50});
    text_set_message(data, name_node, name);
    text_set_font(data, name_node, data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, name_node, 30);
    node_set_layer(data, name_node, 2);
    while (cmp_string(scene->name, node->scene) == 0) {
        if (!(cmp_string(node->name, "background_controls_2") == 0 \
|| cmp_string(node->name, "background_controls") == 0 || cmp_string(node->\
name, "controls") == 0 || cmp_string(node->name, "controls_first") == 0)) {
            node_move(data, node->name, (sfVector2f) {0, 50});
        }
        node = node->next;
    }
}