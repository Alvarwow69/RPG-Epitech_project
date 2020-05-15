/*
** EPITECH PROJECT, 2020
** editor_load_button.c
** File description:
** 
*/

#include "rpg.h"

void create_button_menu(global_data_t *data)
{
    button_create(data, "editor_menu", "interface_editor",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "editor_menu",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "editor_menu", "menu",
    data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, "editor_menu", (sfVector2f){10, 25});
    button_set_position(data, "editor_menu", (sfVector2f){10, 10});
    button_set_text_scale(data, "editor_menu", 15);
    button_set_action(data, "editor_menu", &editor_main_action);
    button_set_scale(data, "editor_menu", (sfVector2f){1.5f, 1.5f});
    button_set_press_position(data, "editor_menu", (sfVector2f){0, 10});
}

void create_button_selection(global_data_t *data)
{
    button_create(data, "editor_selector", "selection_editor",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "editor_selector",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "editor_selector", "Block",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "editor_selector", (sfVector2f){1850, 100});
    button_set_text_pos(data, "editor_selector", (sfVector2f){5, 20});
    button_set_text_scale(data, "editor_selector", 15);
    button_set_action(data, "editor_selector", &editor_selector_action);
    button_set_scale(data, "editor_selector", (sfVector2f){1.5f, 1.5f});
    button_set_press_position(data, "editor_selector", (sfVector2f){0, 10});
}