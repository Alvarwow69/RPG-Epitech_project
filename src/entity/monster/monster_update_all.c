/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_update_all.c
*/

#include "rpg.h"

void monster_update_all(global_data_t *gdata)
{
    game_object_t **monster_tab = gameobject_get_type(gdata, TYPE_MONSTER);

    if (monster_tab[0] == NULL)
        monster_create(gdata, "Lilodon", "map", MSTID_LILODON);
    for (int ctr = 0; monster_tab[ctr] != NULL; ctr += 1)
        monster_update(gdata, monster_tab[ctr]->node);
}