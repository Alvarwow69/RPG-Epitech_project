/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_button_reset
*/

#include "rpg.h"

void button_controls_reset(global_data_t *data, char *name, \
char *node, type_controls_t *type)
{
    char *name_button = concat_fstring("%s%s", "button_", name);
    char *name_button_reset = concat_fstring("%s%s", "reset_", name_button);

    button_create(data, name_button_reset, node, data->\
ressources->textures[BUTTON]);
    button_set_position(data, name_button_reset, (sfVector2f) \
{200, type->pos.y});
    button_set_other_texture(data, name_button_reset, data->ressources\
->textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, name_button_reset, "reset", \
data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, name_button_reset, (sfVector2f){14, 5});
    button_set_text_color(data, name_button_reset, sfBlack);
    button_set_action(data, name_button_reset, &reset_button);
    button_set_scale(data, name_button_reset, \
button_scale_text(data, name_button_reset, "Resett"));
}