/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** shop.h
*/

#ifndef SHOP_H
#define SHOP_H

typedef enum shop_ressources_id_e {
    SRSC_BUY_POTATO,
    SRSC_BUY_APPLE,
    SRSC_BUY_RICE,
    SRSC_BUY_SOUP,
    SRSC_BUY_BANDAGE,
} shop_rsc_id;

#include "rpg.h"

typedef struct shop_prefab_s {
    shop_rsc_id id;
    sfVector2f pos;
    sfIntRect normal;
    sfIntRect hover;
    sfIntRect click;
    void (*action)(global_data_t *, button_t *button);
} shop_prefab_t;

extern const shop_prefab_t shop_rsc[];

void init_shop(global_data_t *gdata, char *scene);
void shop_event(global_data_t *gdata, button_t *button);

void buy_potato(global_data_t *gdata, button_t *button);
void buy_apple(global_data_t *gdata, button_t *button);
void buy_rice(global_data_t *gdata, button_t *button);
void buy_soup(global_data_t *gdata, button_t *button);
void buy_bandage(global_data_t *gdata, button_t *button);

#endif