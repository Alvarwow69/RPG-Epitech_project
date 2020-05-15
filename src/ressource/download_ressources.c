/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** download_ressources.c
*/

#include "rpg.h"

const sfIpAddress dl_ip = {"127.0.0.1"};

const unsigned short dl_port = 4990;

const download_rsc_prefab_t download_rsc_prefab[] = {
    {DL_RSC_1, "SoldierAnimation.png", "rsc/"},
    {DL_RSC_2, "LittleDemonAnimation.png", "rsc/"},
    {DL_RSC_END, NULL, NULL}
};