/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** tile_map.h
*/

#ifndef TILE_MAP_H
#define TILE_MAP_H

typedef struct tile_map_prefab_s tile_map_prefab_t;

typedef enum {
    TM_START,
    TM_CORE_FRAG,
    TM_COAL_ORE,
    TM_COPPER_ORE,
    TM_IRON_ORE,
    TM_GOLD_ORE,
    TM_GLOW_STONE,
    TM_DRY_DIRT,
    TM_STONE_1,
    TM_COBBLE_STAIR,
    TM_MOSSIE_COBBLE_STAIR,
    TM_CONCRET_STAIR,
    TM_STONE_BRIC_STAIR,
    TM_DIRT,
    TM_STONE_2,
    TM_COBBLE,
    TM_MOSSIE_COBBLE,
    TM_CONCRET,
    TM_STONE_BRICK,
    TM_GRASS,
    TM_CONCRET_SLAB,
    TM_STONE_BRICK_SLAB,
    TM_DRY_SAND,
    TM_GRANITE,
    TM_SAND_STONE_STAIR,
    TM_DARK_SAND_STONE_STAIR,
    TM_SAND_STONE_BRICK_STAIR,
    TM_SAND,
    TM_DESERT_STONE,
    TM_SAND_STONE,
    TM_DARk_SAND_STONE,
    TM_SAND_STONE_BRICK,
    TM_SAND_STONE_SLAB,
    TM_DARK_SAND_STONE_SLAB,
    TM_SAND_STONE_BRICK_SLAB,
    TM_FROZEN_DIRT,
    TM_CLAY,
    TM_GRAVEL,
    TM_IRON_BAR,
    TM_BRICK_STAIR,
    TM_HAY,
    TM_SNOW,
    TM_MUD,
    TM_OBSIDIAN,
    TM_GLASS,
    TM_BRICK,
    TM_SOD,
    TM_ICE,
    TM_LOG,
    TM_WOOD,
    TM_WINDOW_LATTICE,
    TM_WOODEN_STAIR,
    TM_ORNATE_LOG,
    TM_WOODEN_FENCE,
    TM_WOODEN_WINDOW,
    TM_WOODEN_SLAB,
    TM_COPPER_BLOCK_STAIR,
    TM_COPPER_FENCE,
    TM_COPPER_STAIR,
    TM_COPPER_BLOCK,
    TM_COPPER_WINDOW,
    TM_COPPER_SLAB,
    TM_SURFACE_WATER,
    TM_DEEP_WATER,
    TM_SING,
    TM_END
} tile_map_id;

#include "item.h"
#include "rpg.h"

struct tile_map_prefab_s {
    tile_map_id id;
    item_id iid;
    sfIntRect rect;
};

extern const tile_map_prefab_t tile_map[];

#endif