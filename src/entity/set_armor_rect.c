/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** set_armor_rect.c
*/

#include "rpg.h"

void set_pants_rect(texture_t *txt, sfSprite *spr, move move, armor_id id)
{
    sfVector2i offset = move_offset[move].offset;
    sfIntRect rect = {0, 0, 0, 0};

    offset = add_vectori(offset, pants[id.pants].offset);
    rect = add_recti_vectori(txt->tile_rect, offset);
    sfSprite_setTextureRect(spr, rect);
}

void set_chest_rect(texture_t *txt, sfSprite *spr, move move, armor_id id)
{
    sfVector2i offset = move_offset[move].offset;
    sfIntRect rect = {0, 0, 0, 0};

    offset = add_vectori(offset, chest[id.chest].offset);
    rect = add_recti_vectori(txt->tile_rect, offset);
    sfSprite_setTextureRect(spr, rect);
}

void set_arms_rect(texture_t *txt, sfSprite *spr, move move, armor_id id)
{
    sfVector2i offset = move_offset[move].offset;
    sfIntRect rect = {0, 0, 0, 0};

    offset = add_vectori(offset, arms[id.arms].offset);
    rect = add_recti_vectori(txt->tile_rect, offset);
    sfSprite_setTextureRect(spr, rect);
}