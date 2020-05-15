/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_succes
*/

#include "rpg.h"

void close_success_quest(global_data_t *data, button_t *button)
{
    (void)button;
    for (int i = 0; i < QUEST_END; i ++) {
        if (data->quest->quest_setting[i].gest.active == -1) {
            data->quest->quest_setting[i].gest.accepted = 0;
            data->quest->quest_setting[i].gest.active = 0;
            node_destroy(data, concat_fstring("succes_%s", \
data->quest->quest_setting[i].name));
            return;
        }
    }
}

void quest_success_button(global_data_t *data, quest_setting_t setting)
{
    char *name_succes = concat_fstring("succes_%s", setting.name);
    char *name_button = concat_fstring("close_%s", name_succes);
    sfVector2f pos = (sfVector2f) {10, 10};

    button_create(data, name_button, name_succes, \
data->ressources->textures[BUTTON]);
    button_set_position(data, name_button, (sfVector2f) {pos.x+105, pos.y+440});
    button_set_other_texture(data, name_button, data->ressources->\
textures[BUTTON_HOVER], data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, name_button, "Close", \
data->ressources->fonts[FONT_MAIN]);
    button_set_text_pos(data, name_button, (sfVector2f){14, 5});
    button_set_text_color(data, name_button, sfBlack);
    button_set_action(data, name_button, &close_success_quest);
    button_set_scale(data, name_button, (sfVector2f) {3.3, 1});
}

void quest_success_text(global_data_t *data, quest_setting_t setting)
{
    char *name_succes = concat_fstring("succes_%s", setting.name);
    char *name_text = concat_fstring("text_%s", name_succes);
    char *text_quest;
    sfVector2f pos = (sfVector2f) {10, 10};

    text_create(data, name_text, name_succes);
    gameobject_set_position(data, name_text, (sfVector2f) {pos.x+20, pos.y+20});
    text_quest = concat_fstring("\nQuest\n%s\nSuccess\n\n\n  \
Reward:\n%i:gold\n%i:xp earn", setting.name, setting.reward_q\
uest.gold, setting.reward_quest.xp);
    text_set_message(data, name_text, text_quest);
    text_set_font(data, name_text, data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, name_text, 25);
}

void quest_success(global_data_t *data, quest_setting_t setting)
{
    scene_t *scene = scene_get(data, setting.scene_name);
    char *name_succes = concat_fstring("succes_%s", setting.name);
    char *name_background = concat_fstring("background_%s", name_succes);
    char *name_text = concat_fstring("text_%s", name_succes);
    char *name_button = concat_fstring("close_%s", name_succes);
    sfVector2f pos = (sfVector2f) {10, 10};

    node_create(data, name_succes, scene->name);
    node_set_layer(data, name_succes, 30);
    node_set_position(data, name_succes, (sfVector2f) {0, 200});
    gameobject_create(data, name_background, name_succes, TYPE_BACKGROUND);
    gameobject_set_texture(data, name_background, \
data->ressources->textures[QUEST_BACKGROUND]);
    gameobject_set_position(data, name_background, pos);
    gameobject_set_scale(data, name_background, (sfVector2f) {2, 2});
    quest_success_button(data, setting);
    quest_success_text(data, setting);
    gameobject_set_layer(data, name_background, 1);
    gameobject_set_layer(data, name_text, 2);
    text_set_color(data, name_text, sfBlack);
    button_set_layer(data, name_button, 2);
}