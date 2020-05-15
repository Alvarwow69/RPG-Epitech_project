/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** consumable.h
*/

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

typedef enum consumable_id_e {
    CONSID_POTATO,
    CONSID_APPLE,
    CONSID_RICE,
    CONSID_SOUP,
    CONSID_BANDAGE,
    CONSID_NONE
} cons_id;

typedef enum consumable_type_e {
    CONST_FOOD,
    CONST_MEDICINE,
    CONST_NONE
} cons_type;

#include "item.h"

typedef struct consumable_s {
    cons_id id;
    cons_type type;
    int vitality_regen;
    int satiety_regen;
} consumable_t;

typedef struct consumable_prefab_s {
    cons_id id;
    cons_type type;
    item_id iid;
    int price;
    int vitality_regen;
    int satiety_regen;
} consumable_prefab_t;

extern const consumable_prefab_t consumable[];

#endif