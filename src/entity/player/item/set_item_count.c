/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** set_item_count.c
*/

#include "rpg.h"

void set_item_count(global_data_t *gdata, item_t *item)
{
    char *name = concat_fstring("%s_count", item->go_inv->name);
    char *ui_name = NULL;
    game_object_t *go = gameobject_get(gdata, name);

    if (go != NULL)
        go->is_draw = (item->number <= 1 ? false : true);
    text_set_message(gdata, name, get_integer_nbr(item->number));
    if (item->go_act != NULL) {
        ui_name = concat_fstring("%s_count", item->go_act->name);
        go = gameobject_get(gdata, ui_name);
        if (go != NULL)
            go->is_draw = (item->number <= 1 ? false : true);
        text_set_message(gdata, ui_name, get_integer_nbr(item->number));
    }
}