/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** player
*/

#ifndef PLAYER_H
#define PLAYER_H

typedef struct save_s save_t;
typedef struct player_s player_t;
typedef struct armor_s armor_t;
typedef struct other_s other_t;
typedef struct inventory_s inventory_t;
typedef struct player_animation_s player_animation_t;
typedef struct value_s value_t;
typedef struct player_properties_s properties_t;

typedef enum player_action_e {
    PA_NONE,
    PA_INVENTORY,
    PA_SHOP
} player_action;

#include "armor.h"
#include "stats.h"
#include "move.h"
#include "item.h"
#include "entity.h"
#include "colision.h"
#include "gameobject.h"

typedef struct {
    move type;
    sfVector2i offset;
} move_prefab_t;

extern const move_prefab_t move_offset[];

struct save_s {
    char *save_txt;
    char **save_map;
    int size;
    item_id *tab_id_item;
    int *nbr_item;
    value_t *value;
    int *properties;
};

struct player_animation_s {
    texture_t *txt;
    texture_t *txt_attack;
    sfSprite *head_spr;
    sfSprite *body_spr;
    sfSprite *arms_spr;
    sfSprite *legs_spr;
    anim_t *arms_walk;
    anim_t *arms_run;
    anim_t *arms_jump;
    anim_t *arms_swip;
    anim_t *arms_pickaxe;
    anim_t *body_walk;
    anim_t *body_run;
    anim_t *body_jump;
    anim_t *legs_walk;
    anim_t *legs_run;
    anim_t *legs_jump;
};

struct inventory_s {
    item_t **items;
    item_t *pick;
    item_t *wear;
};

struct value_s {
    int act;
    int max;
};

struct player_properties_s {
    value_t hp; // 500
    value_t xp; // 100 -> 5 points
    value_t satiety; // 0-120   <30 -> hp -= 30-satiety   >100 hp += satiety-100 
    int money; // 150

    int strenght;
    int defense;
    int accuracy;
    int luck;
    int dexterity;
    int celerity;
    int avl_point;
    game_time_t *time;
};

struct player_s
{
    player_action action_status;
    move move_status;

    stats_t *stats;
    properties_t *prop;
    inventory_t *inventory;
    weapon_t *weapon;
    player_animation_t *animation;
    move_t *move;
    collide_shape_t *talk_collision;
    collide_shape_t *body_collision;

    save_t *save;
};

void load_save(global_data_t *data);
void create_save(global_data_t *data);

player_t *init_player(global_data_t *data);
stats_t *init_stats(void);
void player_armor_set_texture(sfSprite *spr, sfTexture **textures
                             , armor_type type, armor_id id);

void player_scene_load(global_data_t *gdata);
void player_scene_unload(global_data_t *gdata);
void player_scene_create(global_data_t *gdata);

void player_armor_set_texture_rect(sfSprite *spr, move move
                                   , armor_type type, armor_id id);

void player_update(global_data_t *gdata);
// Animation
void player_animation_update(global_data_t *gdata, player_t *player);
void arms_animation(sfClock *clock, player_t *player
                     , move move, armor_id id);
void chest_animation(sfClock *clock, player_t *player
                     , move move, armor_id id);
void pants_animation(sfClock *clock, player_t *player
                     , move move, armor_id id);

sfIntRect set_helm_rect(player_t *player, move move, armor_id id);
// --------
void player_move_update(global_data_t *gdata, player_t *player);

void player_draw(sfRenderWindow *rwindow, player_t *player, sfRenderStates states);

void apply_gravity(move_t *move, sfClock *clock);

void change_player_armor(global_data_t *gdata, item_id iid);

// Stat
void add_stat_point(global_data_t *gdata, button_t *button);
void increase_vitality(global_data_t *gdata, text_t *text);
void increase_melee_strenght(global_data_t *gdata, text_t *text);
void increase_range_strenght(global_data_t *gdata, text_t *text);
void increase_melee_defense(global_data_t *gdata, text_t *text);
void increase_range_defense(global_data_t *gdata, text_t *text);
void increase_accuracy(global_data_t *gdata, text_t *text);
void increase_luck(global_data_t *gdata, text_t *text);
void increase_dexterity(global_data_t *gdata, text_t *text);
void increase_celerity(global_data_t *gdata, text_t *text);
// ----

#endif