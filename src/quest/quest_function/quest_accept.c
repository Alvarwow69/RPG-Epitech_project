/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_accept
*/

#include "rpg.h"

void accept_quest2(global_data_t *data, button_t *button, int i)
{
    if (cmp_string(data->quest->quest_setting[i].name, \
&button->gameobject->name[14]) == 0) {
        data->quest->quest_setting[i].gest.accepted = 1;
        data->quest->quest_setting[i].gest.active = 0;
        node_destroy(data, data->quest->quest_setting[i].name);
    }
}

void accepte_quest(global_data_t *data, button_t *button)
{
    for (int i = 0; i < QUEST_END; i ++) {
        if (data->quest->quest_setting[i].gest.active == 1) {
            accept_quest2(data, button, i);
        }
    }
}

void create_quest_accept(global_data_t *data, quest_setting_t setting)
{
    char *name_button_accept = concat_fstring\
("%s%s", "button_accept_", setting.name);
    sfVector2f pos = (sfVector2f) {10, 10};

    button_create(data, name_button_accept, setting.name, \
data->ressources->textures[BUTTON]);
    button_set_position(data, name_button_accept, \
(sfVector2f) {pos.x+5, pos.y+440});
    button_set_other_texture(data, name_button_accept, data->ressources->\
textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, name_button_accept, "accepte", \
data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, name_button_accept, (sfVector2f){14, 5});
    button_set_text_color(data, name_button_accept, sfBlack);
    button_set_action(data, name_button_accept, &accepte_quest);
    button_set_scale(data, name_button_accept, (sfVector2f) {3.3, 1});
}