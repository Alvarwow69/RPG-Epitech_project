/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** pnj.h
*/

#ifndef PNJ_H
#define PNJ_H

typedef struct pnj_s pnj_t;
typedef struct pnj_animation_s pnj_animation_t;
typedef struct pnj_prefab_s pnj_prefab_t;

typedef enum pnj_id_e {
    PNJID_NONE,
    PNJID_VILLAGER_1,
    PNJID_VILLAGER_2,
    PNJID_VILLAGER_3,
    PNJID_VILLAGER_4,
    PNJID_SNOW_1,
    PNJID_SNOW_2,
    PNJID_SAND_1,
    PNJID_SAND_2
} pnj_id;

typedef enum pnj_action_e {
    PNJA_NONE,
    PNJA_TALK
} pnj_action;

#include "entity.h"
#include "gameobject.h"

struct pnj_animation_s {
    texture_t *txt;
    sfSprite *head_spr;
    sfSprite *body_spr;
    sfSprite *arms_spr;
    sfSprite *legs_spr;
    anim_t *arms_walk;
    anim_t *arms_run;
    anim_t *body_walk;
    anim_t *body_run;
    anim_t *legs_walk;
    anim_t *legs_run;
};

struct pnj_s {
    pnj_id id;
    pnj_action action_status;
    move move_status;

    pnj_animation_t *anim;
    move_t *move;
    collide_shape_t *talk_collision;
    collide_shape_t *body_collision;

    helm_id helm_id;
    chest_id chest_id;
    arms_id arms_id;
    pants_id pants_id;

    float max_right;
    float max_left;
    game_time_t *time;
    float move_loop;
    bool is_pause;
    int direction;
};

struct pnj_prefab_s {
    pnj_id id;
    char *name;
    helm_id helm_id;
    chest_id chest_id;
    arms_id arms_id;
    pants_id pants_id;
    float move_loop;
    float max_left;
    float max_right;
    sfVector2f pos;
};

extern const pnj_prefab_t pnj_list[];

void pnj_create(global_data_t *gdata, char *name, char *scene_name, pnj_id id);
pnj_t *pnj_init(global_data_t *gdata, char *go_name, pnj_id id);
void pnj_draw(sfRenderWindow *rwindow, pnj_t *pnj, sfRenderStates states);
void pnj_update_all(global_data_t *gdata);
void pnj_update(global_data_t *gdata, char *name);

// Animation
void pnj_animation_update(global_data_t *gdata, pnj_t *pnj);
void pnj_arms_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id);
void pnj_chest_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id);
void pnj_pants_animation(sfClock *clock, pnj_t *pnj
                     , move move, armor_id id);

sfIntRect pnj_set_helm_rect(pnj_t *pnj, move move, armor_id id);

#endif