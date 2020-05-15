/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest
*/

#include "rpg.h"

void text_quest_create(global_data_t *data, quest_setting_t setting)
{
    char *text_quest;
    char *name_text = concat_fstring("%s%s", "quest_text_", setting.name);

    if (setting.type_quest == HUNT_TQ)
        text_quest = concat_fstring("%s%i%s\n%s", "Quest\nKill ", setting\
.quest.hunt.how_many, concat_fstring(" %s", setting.quest.hunt.name_mob), setting.description);
    if (setting.type_quest == FIND_TQ)
        text_quest = concat_fstring("%s%i%s\n%s", "Quest\nFind ", setting\
.quest.find_item.how_many, concat_fstring(" %s", setting.quest.\
find_item.name_item), setting.description);
    text_set_message(data, name_text, text_quest);
}

void create_quest_gest(global_data_t *data, quest_setting_t setting)
{
    char *name_button_accept = \
concat_fstring("%s%s", "button_accept_", setting.name);
    char *name_button_refuse = \
concat_fstring("%s%s", "button_refuse_", setting.name);
    char *name_text = concat_fstring("%s%s", "quest_text_", setting.name);
    char *name_background = concat_fstring("%s%s", "background_", setting.name);
    sfVector2f pos = (sfVector2f) {10, 10};

    text_create(data, name_text, setting.name);
    gameobject_set_position(data, name_text, (sfVector2f) {pos.x+20, pos.y+20});
    text_quest_create(data, setting);
    text_set_font(data, name_text, data->ressources->fonts[FONT_MAIN]);
    text_set_size(data, name_text, 30);
    create_quest_accept(data, setting);
    create_quest_refuse(data, setting);
    gameobject_set_layer(data, name_background, 1);
    gameobject_set_layer(data, name_text, 2);
    text_set_color(data, name_text, sfBlack);
    button_set_layer(data, name_button_accept, 2);
    button_set_layer(data, name_button_refuse, 2);
}

void create_quest(global_data_t *data, quest_setting_t setting)
{
    scene_t *scene = scene_get(data, setting.scene_name);
    sfVector2f pos = (sfVector2f) {10, 10};
    char *name_background = concat_fstring("%s%s", "background_", setting.name);

    node_create(data, setting.name, scene->name);
    node_set_layer(data, setting.name, 30);
    node_set_position(data, setting.name, (sfVector2f) {0, 200});
    gameobject_create(data, name_background, setting.name, TYPE_BACKGROUND);
    gameobject_set_texture(data, name_background, \
data->ressources->textures[QUEST_BACKGROUND]);
    gameobject_set_position(data, name_background, pos);
    gameobject_set_scale(data, name_background, (sfVector2f) {2, 2});
    create_quest_gest(data, setting);
    setting.gest.active = 1;
    setting.gest.accepted = 2;
    data->quest->nbr_quest++;
    data->quest->quest_setting[setting.id_quest] = setting;
}

quest_t *initialize_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));
    quest->quest_setting = malloc(sizeof(quest_setting_t) * QUEST_END);
    quest->nbr = -1;
    quest->one_quest_move = 0;
    quest->nbr_quest = 0;
    if (quest == NULL)
        return (print_error("Error: Can't create quest list\n"), NULL);
    quest->tab_quest = malloc(sizeof(tab_quest_t));
    quest->tab_quest->actif = 0;
    quest->tab_quest->tmp = 0;
    return (quest);
}

void init_quest(global_data_t *data)
{
    data->quest = initialize_quest();
}