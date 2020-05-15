/*
** EPITECH PROJECT, 2020
** pause_load.c
** File description:
** 
*/

#include "rpg.h"

void pause_option(global_data_t *data, char *node)
{
    button_create(data, "pause_button_option", node,
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "pause_button_option",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "pause_button_option", "Option",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "pause_button_option", (sfVector2f){2, 2});
    button_set_position(data, "pause_button_option", (sfVector2f){760, 560});
    button_set_text_pos(data, "pause_button_option", (sfVector2f){130, 25});
    button_set_text_color(data, "pause_button_option", sfBlack);
    button_set_action(data, "pause_button_option", &pause_button_setting);
}

void pause_create_menu(global_data_t *data, char *node)
{
    button_create(data, "pause_button_menu", node,
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "pause_button_menu",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "pause_button_menu", "Main menu",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "pause_button_menu", (sfVector2f){2, 2});
    button_set_position(data, "pause_button_menu", (sfVector2f){760, 670});
    button_set_text_pos(data, "pause_button_menu", (sfVector2f){120, 25});
    button_set_text_color(data, "pause_button_menu", sfBlack);
    button_set_action(data, "pause_button_menu", &pause_button_menu);
}

void create_pause_button(global_data_t *data, char *node)
{
    button_create(data, "pause_button_resume", node,
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "pause_button_resume",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "pause_button_resume", "Resume",
    data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, "pause_button_resume", (sfVector2f){2, 2});
    button_set_position(data, "pause_button_resume", (sfVector2f){760, 450});
    button_set_text_pos(data, "pause_button_resume", (sfVector2f){140, 25});
    button_set_text_color(data, "pause_button_resume", sfBlack);
    button_set_action(data, "pause_button_resume", &pause_button_resume);

}

void pause_create_background(global_data_t *data, char *name)
{
    gameobject_create(data, "pause_background", \
name, TYPE_BACKGROUND);
    gameobject_set_texture(data, "pause_background", \
data->ressources->textures[TEXTURE_BACK_PAUSE]);
}

void pause_load(global_data_t *data)
{
    char *name = "pause_interface";

    node_create(data, name, "pause");
    pause_option(data, name);
    create_pause_button(data, name);
    pause_create_menu(data, name);
    text_create(data, "pause_title", name);
    text_set_message(data, "pause_title", "Pause");
    text_set_font(data, "pause_title", data->ressources->fonts[FONT_MAIN]);
    gameobject_set_position(data, "pause_title", (sfVector2f) {800, 150});
    text_set_size(data, "pause_title", 100);
    pause_create_background(data, name);
    data->loading->loaded = true;
}