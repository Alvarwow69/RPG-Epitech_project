/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_button
*/

#include "rpg.h"

void controls_return_button(global_data_t *data, button_t *button)
{
    (void)button;
    scene_draw(data, "setting", true, false);
    while (sfMouse_isButtonPressed(sfMouseLeft));
}

sfVector2f button_scale_text(global_data_t *data, char *name, char *text)
{
    (void)data;
    (void)name;
    sfVector2f pos = {1, 1};
    pos.x = string_len(text, '\0')/2.4;
    pos.x += 1;
    if (string_len(text, '\0') == 1)
        pos.x = 1;
    return (pos);
}

void reset_button(global_data_t *data, button_t *button)
{
    char *name = &(button->gameobject->name[13]);
    char *name_button = concat_fstring("%s%s", "button_", name);

    ctrl_t *ctrl = get_controls_name(data, name);
    ctrl->actual = ctrl->base;
    button_set_text(data, name_button, text_key(data, name)\
, data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, name_button, button_scale_text\
(data, name_button, text_key(data, name)));

}

void change_button(global_data_t *data, button_t *button)
{
    char *name = &(button->gameobject->name[7]);

    ctrl_t *ctrl = get_controls_name(data, name);
    ctrl->actual = recup_key(data);
    button_set_text(data, button->gameobject->name, \
text_key(data, name), data->ressources->fonts[FONT_MAIN]);
    button_set_scale(data, button->gameobject->name, \
button_scale_text(data, button->gameobject->name, text_key(data, name)));

}

void button_controls(global_data_t *data, char *name, char *node, \
type_controls_t *type)
{
    char *name_button = concat_fstring("%s%s", "button_", name);

    button_create(data, name_button, node, data->ressources->textures[BUTTON]);
    button_set_position(data, name_button, (sfVector2f) {400, type->pos.y});
    button_set_other_texture(data, name_button, data->ressources->\
textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, name_button, text_key(data, name), \
data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, name_button, (sfVector2f){14, 5});
    button_set_text_color(data, name_button, sfBlack);
    button_set_action(data, name_button, &change_button);
    button_set_scale(data, name_button, button_scale_text\
(data, name_button, text_key(data, name)));
    button_controls_reset(data, name, node, type);


}