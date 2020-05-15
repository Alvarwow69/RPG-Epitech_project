/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** shop_ressources.c
*/

#include "rpg.h"

const shop_prefab_t shop_rsc[] = {
    {SRSC_BUY_POTATO,  {161,  42}, {186, 1, 16, 16}, {203, 1, 16, 16}, {220, 1, 16, 16}, &buy_potato},
    {SRSC_BUY_APPLE,   {161,  78}, {186, 1, 16, 16}, {203, 1, 16, 16}, {220, 1, 16, 16}, &buy_apple},
    {SRSC_BUY_RICE,    {161, 114}, {186, 1, 16, 16}, {203, 1, 16, 16}, {220, 1, 16, 16}, &buy_rice},
    {SRSC_BUY_SOUP,    {161, 150}, {186, 1, 16, 16}, {203, 1, 16, 16}, {220, 1, 16, 16}, &buy_soup},
    {SRSC_BUY_BANDAGE, {161, 186}, {186, 1, 16, 16}, {203, 1, 16, 16}, {220, 1, 16, 16}, &buy_bandage}
};