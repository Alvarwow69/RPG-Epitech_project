/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** weapon.h
*/

#ifndef WEAPON_H
#define WEAPON_H

typedef struct weapon_s weapon_t;
typedef struct weapon_prefab_s weapon_prefab_t;

typedef enum weapon_type_e {
    WT_NONE,
    WT_SWORD,
    WT_PICKAXE
} weapon_type;

typedef enum weapon_id_e {
    WEAPON_NONE,
    WEAPON_SWORD,
    WEAPON_PICKAXE
} weapon_id;

#include "colision.h"
#include "entity.h"

struct weapon_s {
    weapon_id id;
    weapon_type type;
    texture_t *txt;
    sfSprite *spr;
    anim_t *anim;
    collide_shape_t *cshape;
};

struct weapon_prefab_s {
    weapon_id id;
    weapon_type type;
    texture_id_e txt_id;
    sfVector2i offset;
    sfIntRect tile_rect;
    anim_ref_t anim_ref;
};

extern const weapon_prefab_t weapon[];

#endif