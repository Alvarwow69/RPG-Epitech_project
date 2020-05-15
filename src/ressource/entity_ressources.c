/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_ressources.c
*/

#include "rpg.h"

const head_offset_t head_offset_list[] = {
    {HEAD_OFS_STAND,      {0, 0}},
    {HEAD_OFS_SEET,       {0, -3}},
    {HEAD_OFS_SNICK,      {-3, -24}},
    {HEAD_OFS_WALK_BEGIN, {0, 0}},
    {HEAD_OFS_WALK1,      {0, -3}},
    {HEAD_OFS_WALK2,      {0, -6}},
    {HEAD_OFS_WALK3,      {0, -3}},
    {HEAD_OFS_WALK4,      {0, 0}},
    {HEAD_OFS_WALK5,      {0, -3}},
    {HEAD_OFS_WALK6,      {0, -6}},
    {HEAD_OFS_WALK7,      {0, -3}},
    {HEAD_OFS_WALK_END,   {0, 0}},
    {HEAD_OFS_RUN_BEGIN,  {0, 0}},
    {HEAD_OFS_RUN1,       {-3, 0}},
    {HEAD_OFS_RUN2,       {-3, 3}},
    {HEAD_OFS_RUN3,       {-3, 0}},
    {HEAD_OFS_RUN4,       {-3, -3}},
    {HEAD_OFS_RUN5,       {-3, -0}},
    {HEAD_OFS_RUN6,       {-3, 3}},
    {HEAD_OFS_RUN7,       {-3, 0}},
    {HEAD_OFS_RUN_END,    {0, 0}},
    {HEAD_OFS_JUMP_BEGIN, {0, 0}},
    {HEAD_OFS_JUMP1,      {-3, -3}},
    {HEAD_OFS_JUMP2,      {0, 3}},
    {HEAD_OFS_JUMP3,      {0, 3}},
    {HEAD_OFS_JUMP4,      {0, 3}},
    {HEAD_OFS_JUMP5,      {0, 3}},
    {HEAD_OFS_JUMP6,      {0, 3}},
    {HEAD_OFS_JUMP7,      {0, 3}},
    {HEAD_OFS_JUMP8,      {0, 3}},
    {HEAD_OFS_JUMP9,      {0, 3}},
    {HEAD_OFS_JUMP10,     {0, 3}},
    {HEAD_OFS_JUMP_END,   {0, 0}}
};

const move_prefab_t move_offset[] = {
    {M_STAND, {0,    129}},
    {M_SEET,  {0,    516}},
    {M_SNICK, {0,    903}},
    {M_WALK,  {129,  129}},
    {M_RUN,   {129,  516}},
    {M_JUMP,  {129,  903}},
    {M_FALL,  {1290, 903}},
};

const helm_prefab_t helm[] = {
    {HELM_BARE1, TEXTURE_BARE_CHARACTER, {0,    0}},
    {HELM_BARE2, TEXTURE_BARE_CHARACTER, {129,  0}},
    {HELM_BARE3, TEXTURE_BARE_CHARACTER, {258,  0}},
    {HELM_BARE4, TEXTURE_BARE_CHARACTER, {387,  0}},
    {HELM_BARE5, TEXTURE_BARE_CHARACTER, {516,  0}},
    {HELM_BARE6, TEXTURE_BARE_CHARACTER, {645,  0}},
    {HELM_BARE7, TEXTURE_BARE_CHARACTER, {774,  0}},
    {HELM_BARE8, TEXTURE_BARE_CHARACTER, {903,  0}},
    {HELM_BARE9, TEXTURE_BARE_CHARACTER, {1032, 0}},
    {HELM_ARMOR1_1, TEXTURE_ARMOR1_CHARACTER, {0,    0}},
    {HELM_ARMOR1_2, TEXTURE_ARMOR1_CHARACTER, {129,  0}},
    {HELM_ARMOR1_3, TEXTURE_ARMOR1_CHARACTER, {258,  0}},
    {HELM_ARMOR1_4, TEXTURE_ARMOR1_CHARACTER, {387,  0}},
    {HELM_ARMOR1_5, TEXTURE_ARMOR1_CHARACTER, {516,  0}},
    {HELM_ARMOR1_6, TEXTURE_ARMOR1_CHARACTER, {645,  0}},
    {HELM_ARMOR1_7, TEXTURE_ARMOR1_CHARACTER, {774,  0}},
    {HELM_ARMOR1_8, TEXTURE_ARMOR1_CHARACTER, {903,  0}},
    {HELM_ARMOR1_9, TEXTURE_ARMOR1_CHARACTER, {1032, 0}}
};

const chest_prefab_t chest[] = {
    {CHEST_BARE, TEXTURE_BARE_CHARACTER, {0, 0}, ARMS_BARE},
    {CHEST_ARMOR1, TEXTURE_ARMOR1_CHARACTER, {0, 0}, ARMS_ARMOR1}
};

const arms_prefab_t arms[] = {
    {ARMS_BARE, TEXTURE_BARE_CHARACTER, {0, 129}},
    {ARMS_ARMOR1, TEXTURE_ARMOR1_CHARACTER, {0, 129}}
};

const pants_prefab_t pants[] = {
    {PANTS_BARE, TEXTURE_BARE_CHARACTER, {0, 258}},
    {PANTS_ARMOR1, TEXTURE_ARMOR1_CHARACTER, {0, 258}}
};

const weapon_prefab_t weapon[] = {
    {WEAPON_NONE,    WT_NONE,    TEXTURE_END,     {0,    0},
    {0, 0, 0, 0}, {0, 0, 0, 0}},
    {WEAPON_SWORD,   WT_SWORD,   TEXTURE_SWORD,   {0, 1419},
    {0, 0, 256, 129}, {0.07, -1, 0, 1536}},
    {WEAPON_PICKAXE, WT_PICKAXE, TEXTURE_PICKAXE, {0, 1548},
    {0, 0, 136, 144}, {0.2, -1, 0, 544}}
};