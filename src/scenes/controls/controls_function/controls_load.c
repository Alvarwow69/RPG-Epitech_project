/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_loard
*/

#include "rpg.h"


void controls_node_create(global_data_t *data)
{
    node_create(data, "controls", "controls");
    node_create(data, "background_controls", "controls");
    node_create(data, "background_controls_2", "controls");
    node_create(data, "controls_first", "controls");
    node_create(data, "controls_last", "controls");
}

void controls_background_create(global_data_t *data)
{
    gameobject_create(data, "background_controls", \
"background_controls", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_controls", \
data->ressources->textures[CONTROLS_BACKGROUND]);
    gameobject_set_position(data, "background_controls", (sfVector2f){0, 0});
    gameobject_set_scale(data, "background_controls", \
(sfVector2f) {(float) data->save_render_window_size.x/1366, (float) \
data->save_render_window_size.y/1757});
    gameobject_create(data, "background_controls_2", \
"background_controls_2", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_controls_2", \
data->ressources->textures[CONTROLS_BACKGROUND_2]);
    gameobject_set_position(data, "background_controls_2", (sfVector2f){0, 0});
    gameobject_set_scale(data, "background_controls_2", \
(sfVector2f) {(float) data->save_render_window_size.x/1366, \
(float) data->save_render_window_size.y/1757});

}

void controls_set(global_data_t *data, scene_t *scene)
{
    text_create(data, "controls_title", "controls");
    gameobject_set_position(data, "controls_title", (sfVector2f) {850, 20});
    text_set_message(data, "controls_title", "Controls");
    text_set_font(data, "controls_title", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "controls_title", 40);
    text_set_view(data, "controls_title", scene->interface);
    text_create(data, "first_controls", "controls_first");
    gameobject_set_position(data, "first_controls", (sfVector2f) {800, 50});
    text_set_size(data, "first_controls", 30);
    text_create(data, "last_controls", "controls_last");
    gameobject_set_position(data, "last_controls", (sfVector2f) {800, 100});
    text_set_size(data, "last_controls", 30);
    node_set_layer(data, "controls", 4);
    node_set_layer(data, "background_controls_2", 3);
    node_set_layer(data, "controls_first", 2);
    node_set_layer(data, "controls_last", 2);
    node_set_layer(data, "background_controls", 1);
}

void controls_load_set(global_data_t *data)
{
    scene_t *scene = scene_get(data, "controls");

    controls_node_create(data);
    controls_background_create(data);
    controls_set(data, scene);
}

void controls_load(global_data_t *data)
{
    controls_load_set(data);
    button_create(data, "controls_return", "controls", \
data->ressources->textures[BUTTON]);
    button_set_position(data, "controls_return", (sfVector2f) {0, 0});
    button_set_other_texture(data, "controls_return", data->\
ressources->textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "controls_return", "Return", \
data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, "controls_return", (sfVector2f){14, 5});
    button_set_text_color(data, "controls_return", sfBlack);
    button_set_action(data, "controls_return", &controls_return_button);
    button_set_scale(data, "controls_return", \
button_scale_text(data, "controls_return", "Return"));
    if (data->controls_need_reload == 0)
        create_type_controls(data);
    if (data->controls_need_reload == 0)
        create_controls(data);
    data->controls_need_reload ++;
    data->controls->load_controls ++;
    data->loading->loaded = true;
}

