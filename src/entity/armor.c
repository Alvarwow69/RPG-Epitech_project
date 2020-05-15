/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** armor.c
*/

#include "rpg.h"

void armor_set_texture_rect(sfSprite *spr, move move
                           , armor_type type, armor_id id)
{
    sfIntRect offset = {move_offset[move].offset.x, move_offset[move].offset.y, 129, 129};

    switch (type) {
        case AT_NONE:
            break;
        case AT_HELM:
            sfSprite_setTextureRect(spr, add_recti_vectori((sfIntRect){0, 0, 129, 129}, helm[id.helm].offset));
            break;
        case AT_CHEST:
            sfSprite_setTextureRect(spr, add_recti_vectori(offset, chest[id.chest].offset));
            break;
        case AT_PANTS:
            sfSprite_setTextureRect(spr, add_recti_vectori(offset, pants[id.pants].offset));
            break;
        case AT_ARMS:
            sfSprite_setTextureRect(spr, add_recti_vectori(offset, arms[id.arms].offset));
            break;
    }
}

void armor_set_texture(sfSprite *spr, sfTexture **textures
                      , armor_type type, armor_id id)
{
    switch (type) {
        case AT_NONE:
            break;
        case AT_HELM:
            sfSprite_setTexture(spr, textures[helm[id.helm].txt_id], sfTrue);
            break;
        case AT_CHEST:
            sfSprite_setTexture(spr, textures[chest[id.chest].txt_id], sfTrue);
            break;
        case AT_PANTS:
            sfSprite_setTexture(spr, textures[pants[id.pants].txt_id], sfTrue);
            break;
        case AT_ARMS:
            sfSprite_setTexture(spr, textures[arms[id.arms].txt_id], sfTrue);
            break;
    }
}

sfSprite *armor_create(sfTexture **textures, armor_type type, armor_id id)
{
    sfSprite *spr = sfSprite_create();

    armor_set_texture(spr, textures, type, id);
    armor_set_texture_rect(spr, M_STAND, type, id);
    return (spr);
}