/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

typedef struct monster_s monster_t;
typedef struct monster_animation_s monster_animation_t;
typedef struct monster_prefab_s monster_prefab_t;

typedef enum monster_id_e {
    MSTID_LILODON
} monster_id;

typedef enum monster_action_e {
    MSTA_NONE,
    MSTA_FOLLOW,
    MSTA_ATTACK,
    MSTA_HIT,
    MSTA_DIE
} monster_action;

#include "colision.h"
#include "move.h"
#include "entity.h"

struct monster_animation_s {
    texture_t *txt;
    sfSprite *spr;
    anim_t *walk;
    anim_t *attack;
    anim_t *hit;
    anim_t *die;
};

struct monster_s {
    monster_id id;
    monster_action action_status;
    move move_status;

    monster_animation_t *anim;
    move_t *move;
    collide_shape_t *target_collision;
    collide_shape_t *melee_collision;
    collide_shape_t *body_collision;

    game_time_t *time;
    float move_loop;
    bool is_pause;
    int direction;

    int hp;
};

struct monster_prefab_s {
    monster_id id;
    texture_id_e txt_id;
    float move_loop;
    sfIntRect tile_rect;
    sfVector2i jump_offset;
    anim_ref_t walk;
    sfVector2i walk_offset;
    anim_ref_t attack;
    sfVector2i attack_offset;
    anim_ref_t hit;
    sfVector2i hit_offset;
    anim_ref_t die;
    sfVector2i die_offset;
    sfVector2f spawn;
};

extern const monster_prefab_t monster_list[];

void monster_create(global_data_t *gdata, char *name, char *scene_name, monster_id id);
void monster_destroy(global_data_t *gdata, monster_t *monster);
monster_t *monster_init(global_data_t *gdata, char *name, monster_id id);
void monster_draw(sfRenderWindow *rwindow, monster_t *monster, sfRenderStates states);
void monster_update(global_data_t *gdata, char *name);
void monster_update_all(global_data_t *gdata);

#endif