/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** item.h
*/

#ifndef ITEM_H
#define ITEM_H

typedef struct item_s item_t;
typedef struct item_prefab_s item_prefab_t;

typedef enum {
    IT_NONE,
    IT_HELM,
    IT_CHEST,
    IT_PANTS,
    IT_RING,
    IT_WEARABLE,
    IT_CONSUMABLE,
    IT_BLOCK
} item_type;

typedef enum {
    IID_NO_ITEM,
    IID_NO_HELM,
    IID_NO_CHEST,
    IID_NO_PANTS,
    IID_NO_RING,
    IID_ARMOR1_HELM,
    IID_ARMOR1_CHEST,
    IID_ARMOR1_PANTS,
    IID_SWORD,
    IID_PICKAXE,
    IID_POTATO,
    IID_APPLE,
    IID_RICE,
    IID_SOUP,
    IID_BANDAGE,

    IID_CORE_FRAG,
    IID_COAL,
    IID_COPPER,
    IID_IRON,
    IID_GOLD,
    IID_GLOW_STONE,
    IID_DRY_DIRT,
    IID_STONE,
    IID_COBBLE_STAIR,
    IID_MOSSIE_COBBLE_STAIR,
    IID_CONCRET_STAIR,
    IID_STONE_BRIC_STAIR,
    IID_DIRT,
    IID_COBBLE,
    IID_MOSSIE_COBBLE,
    IID_CONCRET,
    IID_STONE_BRICK,
    IID_GRASS,
    IID_SOD,
    IID_HAY,
    IID_CONCRET_SLAB,
    IID_STONE_BRICK_SLAB,
    IID_DRY_SAND,
    IID_GRANITE,
    IID_SAND_STONE_STAIR,
    IID_DARK_SAND_STONE_STAIR,
    IID_SAND_STONE_BRICK_STAIR,
    IID_BRICK_STAIR,
    IID_SAND,
    IID_DESERT_STONE,
    IID_SAND_STONE,
    IID_DARk_SAND_STONE,
    IID_SAND_STONE_BRICK,
    IID_BRICK,
    IID_ICE,
    IID_SAND_STONE_SLAB,
    IID_DARK_SAND_STONE_SLAB,
    IID_SAND_STONE_BRICK_SLAB,
    IID_FROZEN_DIRT,
    IID_CLAY,
    IID_GRAVEL,
    IID_IRON_BAR,
    IID_COPPER_BLOCK_STAIR,
    IID_COPPER_FENCE,
    IID_SNOW,
    IID_MUD,
    IID_OBSIDIAN,
    IID_GLASS,
    IID_COPPER_BLOCK,
    IID_COPPER_WINDOW,
    IID_LOG,
    IID_WOOD,
    IID_WINDOW_LATTICE,
    IID_WOODEN_STAIR,
    IID_COPPER_STAIR,
    IID_COPPER_SLAB,
    IID_ORNATE_LOG,
    IID_WOODEN_FENCE,
    IID_WOODEN_WINDOW,
    IID_WOODEN_SLAB
} item_id;

#include "consumable.h"
#include "weapon.h"
#include "armor.h"
#include "player.h"
#include "entity.h"

struct item_prefab_s {
    char *name;
    item_id id;
    item_type type;
    weapon_id wear_id;
    int stack;
    sfIntRect rect;
    armor_type armor_type;
    armor_id armor_id;
    cons_id cons_id;
};

struct item_s {
    char *name;
    item_id id;
    item_type type;

    game_object_t *go_inv;
    game_object_t *go_act;
    int number;
    weapon_t *wearable;
    consumable_t *consumable;

    stats_t *stats;
};

extern const item_prefab_t item_list[];

item_t *create_item(global_data_t *gdata, item_id id);
void display_item(item_t *item);
void destroy_item(global_data_t *gdata, item_t *item);
void delete_wear_item(global_data_t *gdata, player_t *player);
void delete_item(global_data_t *gdata, item_t **item, int ctr);
bool give_an_item(global_data_t *gdata, player_t *player, item_id id);
void delete_pick_item(global_data_t *gdata, player_t *player);
void set_item_count(global_data_t *gdata, item_t *item);
int search_item(inventory_t *inv, item_id id);
void delete_nbr_item(global_data_t *gdata, inventory_t *inv, item_id id, int count);

#endif