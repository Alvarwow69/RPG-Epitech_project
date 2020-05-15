/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_tab
*/

#include "rpg.h"



void tab_quest_unload(global_data_t *data)
{
    node_destroy(data, "node_tab_quest");
    data->quest->tab_quest->actif = 0;
    if (node_get(data, "node_resume_quest"))
        node_destroy(data, "node_resume_quest");
}

void tab_quest_init(global_data_t *data)
{
    gameobject_create(data, "background_tab_quest", \
"node_tab_quest", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_tab_quest", \
data->ressources->textures[QUEST_BACKGROUND]);
    gameobject_set_position(data, "background_tab_quest", (sfVector2f) {0, 0});
    gameobject_set_scale(data, "background_tab_quest", (sfVector2f) {5, 4});
    text_create(data, "tab_quest_text", "node_tab_quest");
    gameobject_set_position(data, "tab_quest_text", (sfVector2f) {1, 50});
    text_set_message(data, "tab_quest_text", "All Quests");
    text_set_font(data, "tab_quest_text", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "tab_quest_text", 50);
    text_set_color(data, "tab_quest_text", sfBlack);
}

void tab_quest_create_text(global_data_t *data, char *name_text, int cmp, int i)
{
    text_create(data, name_text, "node_tab_quest");
    gameobject_set_position(data, name_text, (sfVector2f) {200, 150+cmp});
    text_set_message(data, name_text, data->quest->quest_setting[i].name);
    text_set_font(data, name_text, data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, name_text, 40);
    text_set_color(data, name_text, sfBlack);
    gameobject_set_layer(data, name_text, 2);
}

void tab_quest_create_button(global_data_t *data, char *name_button, int cmp)
{
    button_create(data, name_button, "node_tab_quest", \
data->ressources->textures[BUTTON]);
    button_set_position(data, name_button, (sfVector2f) {0, 150+cmp});
    button_set_other_texture(data, name_button, data->ressources\
->textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, name_button, "Resume", data->ressources\
->fonts[FONT_MAIN]);
    button_set_text_pos(data, name_button, (sfVector2f){14, 5});
    button_set_text_color(data, name_button, sfBlack);
    button_set_action(data, name_button, &resume_quest);
    button_set_scale(data, name_button, (sfVector2f) {3.3, 1});
    gameobject_set_layer(data, name_button, 2);
}

void tab_quest_load(global_data_t *data)
{
    node_create(data, "node_tab_quest", data->active_scene->name);
    char *name_button;
    char *name_text;
    int cmp = 0;

    data->quest->tab_quest->actif = 1;
    tab_quest_init(data);
    for (int i = 0; i < QUEST_END; i ++) {
        if (data->quest->quest_setting[i].gest.accepted == 1) {
            name_button = concat_fstring("%s%s", \
"tab_quest_button_", data->quest->quest_setting[i].name);
            name_text = concat_fstring("%s%s", \
"tab_quest_text_", data->quest->quest_setting[i].name);
            tab_quest_create_button(data, name_button, cmp);
            tab_quest_create_text(data, name_text, cmp, i);
            cmp+= 50;
        }
    }
    node_set_layer(data, "node_tab_quest", 50);
    gameobject_set_layer(data, "background_tab_quest", 1);
    gameobject_set_layer(data, "tab_quest_text", 2);
}