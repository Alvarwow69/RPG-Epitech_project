/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_event
*/

#include "rpg.h"

void quest_event_check_quest(global_data_t *data, int i)
{
    if (data->quest->quest_setting[i].gest.active == -1) {
        check_button(data, sfMouse_getPositionRenderWindow(data->window), \
data->active_scene->interface, node_get(data, \
concat_fstring("succes_%s", data->quest->quest_setting[i].name)));
    }
    if (data->quest->quest_setting[i].gest.active == 1) {
        check_button(data, sfMouse_getPositionRenderWindow(data->window), \
data->active_scene->interface, node_get(data, \
data->quest->quest_setting[i].name));
    }
}

void quest_event_tab_gest(global_data_t *data)
{
    if (get_controls_event(data, "Quest") == 1) {
        if (data->quest->tab_quest->actif == 0 && \
data->quest->tab_quest->tmp == 1) {
            tab_quest_load(data);
            play_sound_reset(data, SOUND_OPEN_QUEST);
            data->quest->tab_quest->tmp = 0;
        }
        if (data->quest->tab_quest->actif == 1 && \
data->quest->tab_quest->tmp == 1) {
            play_sound_reset(data, SOUND_CLOSE_QUEST);
            data->quest->tab_quest->tmp = 0;
            tab_quest_unload(data);
        }
    }
}

void quest_event(global_data_t *data)
{
    quest_event_tab_gest(data);
    if (get_controls_event(data, "Quest") == 0) {
        data->quest->tab_quest->tmp = 1;
    }
    if (data->key->left_click) {
        if (data->quest->tab_quest->actif == 1)
            check_button(data, sfMouse_getPositionRenderWindow(data->window), \
data->active_scene->interface, node_get(data, "node_tab_quest"));
        for (int i = 0; i < data->quest->nbr_quest; i ++) {
            quest_event_check_quest(data, i);
        }
    }
}