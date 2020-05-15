/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** pnj_update_all.c
*/

#include "rpg.h"

void pnj_update_all(global_data_t *gdata)
{
    game_object_t **pnj_tab = gameobject_get_type(gdata, TYPE_PNJ);

    for (int ctr = 0; pnj_tab[ctr] != NULL; ctr += 1)
        pnj_update(gdata, pnj_tab[ctr]->node);
}