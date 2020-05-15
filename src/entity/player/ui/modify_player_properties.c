/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** modify_player_properties.c
*/

#include "rpg.h"

void modify_vitality(global_data_t *gdata, properties_t *prop, int value)
{
    game_object_t *go_ui = gameobject_get(gdata, "p_ui_hp_bar");
    game_object_t *go_inv = gameobject_get(gdata, "p_inv_hp_bar");
    float percent = 0;

    if ((prop->hp.act + value) > 0 && (prop->hp.act + value) < prop->hp.max)
        prop->hp.act += value;
    else if ((prop->hp.act + value) < 0)
        prop->hp.act = 0;
    else if ((prop->hp.act + value) > prop->hp.max)
        prop->hp.act = prop->hp.max;
    percent = (prop->hp.act * 100) / prop->hp.max;
    texture_rect_percent(go_ui->object.sprite, (sfIntRect){0, 163, 266, 8}, percent, "right");
    texture_rect_percent(go_inv->object.sprite, inv_rsc[IRSC_HP_BAR].normal, percent, "right");
}

void modify_experience(global_data_t *gdata, properties_t *prop, int value)
{
    game_object_t *go_ui = gameobject_get(gdata, "p_ui_xp_bar");
    game_object_t *go_inv = gameobject_get(gdata, "p_inv_xp_bar");
    float percent = 0;

    if ((prop->xp.act + value) > 0 && (prop->xp.act + value) < prop->xp.max)
        prop->xp.act += value;
    else if ((prop->xp.act + value) < 0)
        prop->xp.act = 0;
    else if ((prop->xp.act + value) > prop->xp.max)
        prop->xp.act = prop->xp.max;
    percent = (prop->xp.act * 100) / prop->xp.max;
    texture_rect_percent(go_ui->object.sprite, (sfIntRect){0, 163, 236, 8}, percent, "right");
    texture_rect_percent(go_inv->object.sprite, inv_rsc[IRSC_XP_BAR].normal, percent, "right");
}

void modify_satiety(global_data_t *gdata, properties_t *prop, int value)
{
    game_object_t *go = gameobject_get(gdata, "p_ui_st_bar");
    float percent = 0;

    if ((prop->satiety.act + value) > 0 && (prop->satiety.act + value) < prop->satiety.max)
        prop->satiety.act += value;
    else if ((prop->satiety.act + value) < 0)
        prop->satiety.act = 0;
    else if ((prop->satiety.act + value) > prop->satiety.max)
        prop->satiety.act = prop->satiety.max;
    if (prop->satiety.act < 30)
        modify_vitality(gdata, prop, -(ABS(prop->satiety.act - 30)));
    else if (prop->satiety.act > 100)
        modify_vitality(gdata, prop, ABS(prop->satiety.act - 100));
    percent = (prop->satiety.act * 100) / prop->satiety.max;
    texture_rect_percent(go->object.sprite, (sfIntRect){0, 181, 206, 8}, percent, "right");
}

void modify_money(global_data_t *gdata, properties_t *prop, int value)
{
    float percent = 0;

    if ((prop->money + value) < 0)
        return;
    prop->money += value;
    text_set_message(gdata, "p_ui_money_text", get_integer_nbr(prop->money));
}