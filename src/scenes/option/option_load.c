/*
** EPITECH PROJECT, 2020
** option_load.c
** File description:
** 
*/

#include "rpg.h"

void create_setting_music(global_data_t *data)
{
    char *value = get_integer_nbr(data->music_volume);

    text_create(data, "setting_music", "setting");
    gameobject_set_position(data, "setting_music", (sfVector2f) {300, 200});
    text_set_message(data, "setting_music", "Musics Volume");
    text_set_font(data, "setting_music", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "setting_music", 40);
    text_create(data, "setting_music_value", "setting");
    gameobject_set_position(data, "setting_music_value"
    , (sfVector2f) {450, 300});
    text_set_message(data, "setting_music_value", value);
    text_set_font(data, "setting_music_value"
    , data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "setting_music_value", 40);
    create_button_music(data);
}

void create_setting_sound(global_data_t *data)
{
    char *value = get_integer_nbr(data->sound_volume);

    text_create(data, "setting_sounds", "setting");
    gameobject_set_position(data, "setting_sounds", (sfVector2f) {1300, 200});
    text_set_message(data, "setting_sounds", "Sounds Volume");
    text_set_font(data, "setting_sounds", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "setting_sounds", 40);
    text_create(data, "setting_sound_value", "setting");
    gameobject_set_position(data, "setting_sound_value"
    , (sfVector2f) {1450, 300});
    text_set_message(data, "setting_sound_value", value);
    text_set_font(data, "setting_sound_value"
    , data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "setting_sound_value", 40);
    create_button_sounds(data);
}

void create_button_setting(global_data_t *data)
{
    button_create(data, "setting_menu", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "setting_menu",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "setting_menu", "menu",
    data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, "setting_menu", (sfVector2f){10, 20});
    button_set_position(data, "setting_menu", (sfVector2f){10, 10});
    button_set_text_scale(data, "setting_menu", 20);
    button_set_action(data, "setting_menu", &setting_main_menu);
    button_set_scale(data, "setting_menu", (sfVector2f){1.5f, 1.5f});
    button_set_text_color(data, "setting_menu", sfBlack);
}

void create_setting_background(global_data_t *data)
{
    node_create(data, "background_setting", "setting");
    node_set_layer(data, "setting", 2);
    node_set_layer(data, "background_setting", 1);
    gameobject_create(data, "background_setting", "background_setting",
    TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_setting", data->ressources->
    textures[CONTROLS_BACKGROUND]);
    gameobject_set_position(data, "background_setting", (sfVector2f){0, 0});
    gameobject_set_scale(data, "background_setting", (sfVector2f) {(float)\
data->save_render_window_size.x / 1366\
, (float) data->save_render_window_size.y/1757});
}

void setting_load(global_data_t *data)
{
    node_create(data, "setting", "setting");
    text_create(data, "setting_title", "setting");
    gameobject_set_position(data, "setting_title", (sfVector2f) {760, 100});
    text_set_message(data, "setting_title", "Setting");
    text_set_font(data, "setting_title", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "setting_title", 100);
    create_setting_background(data);
    create_setting_music(data);
    create_setting_sound(data);
    create_setting_controls(data);
    create_button_setting(data);
    data->loading->loaded = true;
}