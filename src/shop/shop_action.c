/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** shop_action.c
*/

#include "rpg.h"

void buy_potato(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    (void)button;
    if (player->prop->money - consumable[CONSID_POTATO].price >= 0) {
        give_an_item(gdata, player, IID_POTATO);
        modify_money(gdata, player->prop, -consumable[CONSID_POTATO].price);
    }
}

void buy_apple(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    (void)button;
    if (player->prop->money - consumable[CONSID_APPLE].price >= 0) {
        give_an_item(gdata, player, IID_APPLE);
        modify_money(gdata, player->prop, -consumable[CONSID_APPLE].price);
    }
}

void buy_rice(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    (void)button;
    if (player->prop->money - consumable[CONSID_RICE].price >= 0) {
        give_an_item(gdata, player, IID_RICE);
        modify_money(gdata, player->prop, -consumable[CONSID_RICE].price);
    }
}

void buy_soup(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    (void)button;
    if (player->prop->money - consumable[CONSID_SOUP].price >= 0) {
        give_an_item(gdata, player, IID_SOUP);
        modify_money(gdata, player->prop, -consumable[CONSID_SOUP].price);
    }
}

void buy_bandage(global_data_t *gdata, button_t *button)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    (void)button;
    if (player->prop->money - consumable[CONSID_BANDAGE].price >= 0) {
        give_an_item(gdata, player, IID_BANDAGE);
        modify_money(gdata, player->prop, -consumable[CONSID_BANDAGE].price);
    }
}