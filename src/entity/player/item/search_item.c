/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** search_item.c
*/

#include "rpg.h"

int search_item(inventory_t *inv, item_id id)
{
    int find_count = 0;

    for (int ctr = 0; ctr < INV_COUNT; ctr += 1)
        if (inv->items[ctr]->id == id)
            find_count += inv->items[ctr]->number;
    return (find_count);
}