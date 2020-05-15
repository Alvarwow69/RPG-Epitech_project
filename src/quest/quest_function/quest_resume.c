/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_resume
*/

#include "rpg.h"

void resume_quest_set_text(global_data_t *data, int cmp)
{
    char *text_quest;

    if (data->quest->quest_setting[cmp].type_quest == HUNT_TQ)
        text_quest = concat_fstring("%s%i%s\n%i/%i\n%s", "Quest\nKill ", \
data->quest->quest_setting[cmp].quest.hunt.how_many, concat_fstring(" \
%s", data->quest->quest_setting[cmp].quest.hunt.name_mob), data->quest\
->quest_setting[cmp].quest.hunt.actual, data->quest->quest_setting[cmp]\
.quest.hunt.how_many, data->quest->quest_setting[cmp].description);
    if (data->quest->quest_setting[cmp].type_quest == FIND_TQ)
        text_quest = concat_fstring("%s%i%s\n%i/%i\n%s", "Quest\nFind ", \
data->quest->quest_setting[cmp].quest.find_item.how_many, concat_fstr\
ing(" %s", data->quest->quest_setting[cmp].quest.find_item.name_item)\
, data->quest->quest_setting[cmp].quest.find_item.actual, data->quest\
->quest_setting[cmp].quest.find_item.how_many, data->quest->quest_setting[cmp].description);
    text_set_message(data, "tab_resume_text", text_quest);
}

void resume_quest_init(global_data_t *data)
{
    node_create(data, "node_resume_quest", data->active_scene->name);
    gameobject_create(data, "background_resume_quest", \
"node_resume_quest", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_resume_quest", \
data->ressources->textures[QUEST_BACKGROUND]);
    gameobject_set_position(data, "background_resume_quest", \
(sfVector2f) {500, 200});
    gameobject_set_scale(data, "background_resume_quest", (sfVector2f) {2, 2});
    gameobject_set_layer(data, "background_resume_quest", 1);
}

int resume_quest2(global_data_t *data, int i, int cmp, button_t *button)
{
    if (data->quest->quest_setting[i].gest.accepted == 1) {
        if (cmp_string(&button->gameobject->name[17], \
data->quest->quest_setting[i].name) == 0)
            cmp = i;
    }
    return (cmp);
}

void resume_quest(global_data_t *data, button_t *button)
{
    int cmp = 0;
    for (int i = 0; i < QUEST_END; i ++) {
        cmp = resume_quest2(data, i, cmp, button);
    }
    if (node_get(data, "node_resume_quest"))
        node_destroy(data, "node_resume_quest");
    resume_quest_init(data);
    text_create(data, "tab_resume_text", "node_resume_quest");
    gameobject_set_position(data, "tab_resume_text", (sfVector2f) {550, 250});
    resume_quest_set_text(data, cmp);
    text_set_font(data, "tab_resume_text", data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, "tab_resume_text", 20);
    text_set_color(data, "tab_resume_text", sfBlack);
    node_set_layer(data, "node_resume_quest", 51);
    gameobject_set_layer(data, "tab_resume_text", 2);
}