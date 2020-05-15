/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** verif_quest
*/

#include "rpg.h"

void quest_success_verif_hunt(global_data_t *data, \
collide_object_t *cobj, int i)
{
    if (data->quest->quest_setting[i].type_quest == HUNT_TQ) {
        if (cobj->cshape->go->object.monster->id == data->quest\
->quest_setting[i].quest.hunt.type_mob) {
            data->quest->quest_setting[i].quest.hunt.actual ++;
        }
        if (data->quest->quest_setting[i].quest.hunt.actual == \
data->quest->quest_setting[i].quest.hunt.how_many) {
            data->quest->quest_setting[i].gest.active = -1;
            data->quest->quest_setting[i].gest.accepted = 2;
            quest_success(data, data->quest->quest_setting[i]);
        }
    }
}

void verif_quest(global_data_t *data, collide_object_t *cobj)
{
    for (int i = 0; i < data->quest->nbr_quest; i ++) {
        if (data->quest->quest_setting[i].gest.accepted == 1) {
            quest_success_verif_hunt(data, cobj, i);
        }
    }
}

