/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** main_create_button
*/

#include "rpg.h"

void create_button_option(global_data_t *data)
{
    button_create(data, "main_button_option", "interface",
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "main_button_option",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "main_button_option", "Option",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "main_button_option", (sfVector2f){2, 2});
    button_set_position(data, "main_button_option", (sfVector2f){760, 620});
    button_set_text_pos(data, "main_button_option", (sfVector2f){135, 25});
    button_set_text_color(data, "main_button_option", sfBlack);
    button_set_action(data, "main_button_option", &main_button_setting);
}

void create_button_edit(global_data_t *data)
{
    button_create(data, "main_button_edit", "interface",
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "main_button_edit",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "main_button_edit", "Edit your map!",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "main_button_edit", (sfVector2f){2, 2});
    button_set_position(data, "main_button_edit", (sfVector2f){760, 510});
    button_set_text_pos(data, "main_button_edit", (sfVector2f){80, 25});
    button_set_text_color(data, "main_button_edit", sfBlack);
    button_set_action(data, "main_button_edit", &main_button_edit);
    create_button_option(data);
}

void create_button_quit(global_data_t *data)
{
    button_create(data, "main_button_quit", "interface",
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "main_button_quit",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "main_button_quit", "Quit",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "main_button_quit", (sfVector2f){2, 2});
    button_set_position(data, "main_button_quit", (sfVector2f){760, 730});
    button_set_text_pos(data, "main_button_quit", (sfVector2f){150, 25});
    button_set_text_color(data, "main_button_quit", sfBlack);
    button_set_action(data, "main_button_quit", &main_button_close);
}

void create_main_button(global_data_t *data)
{
    button_create(data, "main_button_play", "interface",
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "main_button_play",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_position(data, "main_button_play", (sfVector2f){760, 400});
    button_set_text(data, "main_button_play", "Play",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "main_button_play", (sfVector2f){2, 2});
    button_set_text_pos(data, "main_button_play", (sfVector2f){150, 25});
    button_set_text_color(data, "main_button_play", sfBlack);
    button_set_action(data, "main_button_play", &main_button_play);
    create_button_quit(data);
}