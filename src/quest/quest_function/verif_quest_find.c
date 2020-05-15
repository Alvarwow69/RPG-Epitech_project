/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** verif_quest_find
*/

#include "rpg.h"

int verif_quest_search(global_data_t *data, inventory_t *inv, int nbr, int i)
{
    for (int y = 0; y < SLOT_COUNT; y++) {
        if (inv->items[y]->id == data->quest->quest_\
setting[i].quest.find_item.type_item) {
            nbr += inv->items[y]->number;
        }
    }
    return (nbr);
}

void verif_quest_delete_item(global_data_t *\
data, inventory_t *inv, int i, int nbr)
{
    int actual_nbr = 0;

    if (nbr >= data->quest->quest_setting[i].quest.find_item.how_many) {
        actual_nbr = data->quest->quest_setting[i].quest.find_item.how_many;
        delete_nbr_item(data, inv, data->quest->quest_\
setting[i].quest.find_item.type_item, actual_nbr);
        actual_nbr = 0;
        if (actual_nbr == 0) {
            data->quest->quest_setting[i].gest.active = -1;
            data->quest->quest_setting[i].gest.accepted = 2;
            quest_success(data, data->quest->quest_setting[i]);
        }
    }
}

void verif_quest_gest(global_data_t *data, inventory_t *inv, int i)
{
    int nbr = 0;

    if (data->quest->quest_setting[i].gest.accepted == 1) {
        if (data->quest->quest_setting[i].type_quest == FIND_TQ) {
            nbr = verif_quest_search(data, inv, nbr, i);
            data->quest->quest_setting[i].quest.find_item.actual = nbr;
            verif_quest_delete_item(data, inv, i, nbr);
        }
    }
}

void verif_quest_find(global_data_t *data, inventory_t *inv)
{
    for (int i = 0; i < data->quest->nbr_quest; i ++) {
        verif_quest_gest(data, inv, i);
    }
}
