/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** option_button_keyboard
*/

#include "rpg.h"

void option_button_controls(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "controls", true, false);
}

void create_setting_controls(global_data_t *data)
{
    button_create(data, "button_controls", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "button_controls",
    data->ressources->textures[BUTTON_HOVER]
    , data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "button_controls", "Controls",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "button_controls", (sfVector2f){500, 500});
    button_set_text_pos(data, "button_controls", (sfVector2f){14, 5});
    button_set_text_color(data, "button_controls", sfBlack);
    button_set_scale(data, "button_controls", (sfVector2f){4, 1});
    button_set_action(data, "button_controls", &option_button_controls);
}