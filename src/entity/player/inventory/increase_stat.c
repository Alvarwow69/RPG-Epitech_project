/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** increase_stat.c
*/

#include "rpg.h"

const pstat_list_t pstat_list[] = {
    {IRSC_PSTAT_VIT, "p_inv_pstat_vit", &increase_vitality},
    {IRSC_PSTAT_MSTR, "p_inv_pstat_mstr", &increase_melee_strenght},
    {IRSC_PSTAT_RSTR, "p_inv_pstat_rstr", &increase_range_strenght},
    {IRSC_PSTAT_MDEF, "p_inv_pstat_mdef", &increase_melee_defense},
    {IRSC_PSTAT_RDEF, "p_inv_pstat_rdef", &increase_range_defense},
    {IRSC_PSTAT_ACC, "p_inv_pstat_acc", &increase_accuracy},
    {IRSC_PSTAT_LUCK, "p_inv_pstat_luck", &increase_luck},
    {IRSC_PSTAT_DEXT, "p_inv_pstat_dext", &increase_dexterity},
    {IRSC_PSTAT_CEL, "p_inv_pstat_cel", &increase_celerity}
};

void increase_vitality(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->vit >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->vit += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->vit));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_melee_strenght(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->mstr >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->mstr += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->mstr));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_range_strenght(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->rstr >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->rstr += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->rstr));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_melee_defense(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->mdef >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->mdef += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->mdef));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_range_defense(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->rdef >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->rdef += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->rdef));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_accuracy(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->acc >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->acc += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->acc));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_luck(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->luck >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->luck += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->luck));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_dexterity(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->dext >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->dext += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->dext));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}

void increase_celerity(global_data_t *gdata, text_t *text)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    if (player == NULL)
        return;
    if (player->stats->cel >= 99 || player->prop->avl_point <= 0)
        return;
    player->stats->cel += 1;
    text_set_message(gdata, text->gameobject->name, get_integer_nbr(player->stats->cel));
    player->prop->avl_point -= 1;
    text_set_message(gdata, "p_inv_pstat_avl_text", get_integer_nbr(player->prop->avl_point));
}