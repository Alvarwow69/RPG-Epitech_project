/*
** EPITECH PROJECT, 2019
** main_load.c
** File description:
** 
*/

#include "rpg.h"

void main_create_background(global_data_t *data)
{
    gameobject_create(data, "main_background",
    "interface", TYPE_BACKGROUND);
    gameobject_set_texture(data, "main_background",
    data->ressources->textures[TEXTURE_BACK_MAIN]);
    gameobject_set_scale(data, "main_background", \
(sfVector2f) {(float) data->save_render_window_size.x/2337, (float) \
data->save_render_window_size.y/1350});
}

void main_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "main");

    node_create(data, "interface", "main");
    create_main_button(data);
    create_button_edit(data);
    text_create(data, "main_title", "interface");
    gameobject_set_position(data, "main_title", (sfVector2f) {760, 100});
    text_set_message(data, "main_title", "ZI BEST\n  RPG");
    text_set_font(data, "main_title", data->ressources->fonts[FONT_MAIN]);
    text_set_view(data, "main_title", scene->interface);
    text_set_size(data, "main_title", 100);
    main_create_background(data);
}