/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** armor.h
*/

#ifndef ARMOR_H
#define ARMOR_H

typedef struct head_offset_s head_offset_t;
typedef struct helm_prefab_s helm_prefab_t;
typedef struct arms_prefab_s arms_prefab_t;
typedef struct chest_prefab_s chest_prefab_t;
typedef struct pants_prefab_s pants_prefab_t;

typedef enum armor_type_e {
    AT_HELM,
    AT_CHEST,
    AT_PANTS,
    AT_ARMS,
    AT_NONE
} armor_type;

typedef enum head_offset_e {
    HEAD_OFS_STAND,
    HEAD_OFS_SEET,
    HEAD_OFS_SNICK,
    HEAD_OFS_WALK_BEGIN,
    HEAD_OFS_WALK1,
    HEAD_OFS_WALK2,
    HEAD_OFS_WALK3,
    HEAD_OFS_WALK4,
    HEAD_OFS_WALK5,
    HEAD_OFS_WALK6,
    HEAD_OFS_WALK7,
    HEAD_OFS_WALK_END,
    HEAD_OFS_RUN_BEGIN,
    HEAD_OFS_RUN1,
    HEAD_OFS_RUN2,
    HEAD_OFS_RUN3,
    HEAD_OFS_RUN4,
    HEAD_OFS_RUN5,
    HEAD_OFS_RUN6,
    HEAD_OFS_RUN7,
    HEAD_OFS_RUN_END,
    HEAD_OFS_JUMP_BEGIN,
    HEAD_OFS_JUMP1,
    HEAD_OFS_JUMP2,
    HEAD_OFS_JUMP3,
    HEAD_OFS_JUMP4,
    HEAD_OFS_JUMP5,
    HEAD_OFS_JUMP6,
    HEAD_OFS_JUMP7,
    HEAD_OFS_JUMP8,
    HEAD_OFS_JUMP9,
    HEAD_OFS_JUMP10,
    HEAD_OFS_JUMP_END
} head_offset;

typedef enum helm_id {
    HELM_BARE1,
    HELM_BARE2,
    HELM_BARE3,
    HELM_BARE4,
    HELM_BARE5,
    HELM_BARE6,
    HELM_BARE7,
    HELM_BARE8,
    HELM_BARE9,
    HELM_ARMOR1_1,
    HELM_ARMOR1_2,
    HELM_ARMOR1_3,
    HELM_ARMOR1_4,
    HELM_ARMOR1_5,
    HELM_ARMOR1_6,
    HELM_ARMOR1_7,
    HELM_ARMOR1_8,
    HELM_ARMOR1_9
} helm_id;

typedef enum arms_id {
    ARMS_BARE,
    ARMS_ARMOR1
} arms_id;

typedef enum chest_id {
    CHEST_BARE,
    CHEST_ARMOR1
} chest_id;

typedef enum pants_id {
    PANTS_BARE,
    PANTS_ARMOR1
} pants_id;

typedef union armor_id {
    helm_id helm;
    chest_id chest;
    pants_id pants;
    arms_id arms;
} armor_id;

#include "move.h"
#include "entity.h"

struct head_offset_s {
    head_offset id;
    sfVector2i offset;
};

struct helm_prefab_s {
    helm_id id;
    texture_id_e txt_id;
    sfVector2i offset;
};

struct arms_prefab_s {
    arms_id id;
    texture_id_e txt_id;
    sfVector2i offset;
};

struct chest_prefab_s {
    chest_id id;
    texture_id_e txt_id;
    sfVector2i offset;
    arms_id arms_id;
};

struct pants_prefab_s {
    pants_id id;
    texture_id_e txt_id;
    sfVector2i offset;
};

extern const head_offset_t head_offset_list[];
extern const helm_prefab_t helm[];
extern const arms_prefab_t arms[];
extern const chest_prefab_t chest[];
extern const pants_prefab_t pants[];

void armor_set_texture_rect(sfSprite *spr, move move
                           , armor_type type, armor_id id);
void armor_set_texture(sfSprite *spr, sfTexture **textures
                      , armor_type type, armor_id id);
sfSprite *armor_create(sfTexture **textures, armor_type type, armor_id id);

void set_pants_rect(texture_t *txt, sfSprite *spr, move move, armor_id id);
void set_chest_rect(texture_t *txt, sfSprite *spr, move move, armor_id id);
void set_arms_rect(texture_t *txt, sfSprite *spr, move move, armor_id id);
void set_weapon_rect(texture_t *txt, sfSprite *spr, move move, armor_id id);

#endif