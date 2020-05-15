/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** texture.h
*/

#ifndef TEXTURE_H
#define TEXTURE_H

typedef struct texture_prefab_s texture_prefab_t;

typedef enum {
    BACK,
    BUTTON,
    BUTTON_HOVER,
    BUTTON_PRESS,
    BUTTON_L,
    BUTTON_L_HOVER,
    BUTTON_L_PRESS,
    QUEST_BACKGROUND,
    CONTROLS_BACKGROUND,
    CONTROLS_BACKGROUND_2,
    TRAVEL_WATER,
    TRAVEL_SHIP_E,
    TRAVEL_SHIP_N,
    TRAVEL_SHIP_S,
    TRAVEL_SHIP_W,
    TRAVEL_SAND,
    TRAVEL_CAVE,
    TRAVEL_SNOW,
    TRAVEL_JUNGLE,
    TEXTURE_TILE_MAP,
    TEXTURE_BACK,
    TEXTURE_TRAVEL_BACKGROUND,
    TEXTURE_TRAVEL_BACKGROUND2,
    TEXTURE_INV_ICON,
    TEXTURE_BARE_CHARACTER,
    TEXTURE_ARMOR1_CHARACTER,
    TEXTURE_PLAYER_INVENTORY,
    TEXTURE_UI_BAR,
    TEXTURE_ACTIVE_BAR,
    TEXTURE_WATER,
    TEXTURE_MOB_LILODON,
    TEXTURE_MHP_BAR,
    TEXTURE_SWORD,
    TEXTURE_PICKAXE,
    TEXTURE_BACK_MAIN,
    TEXTURE_BACK_PAUSE,
    TEXTURE_BACK_DESERT,
    TEXTURE_BACK_CAVE,
    TEXTURE_BACK_SNOW,
    TEXTURE_LOADING,
    TEXTURE_SHOP_SCREEN,
    TEXTURE_END
} texture_id_e;

#include "csfml.h"

struct texture_prefab_s {
    texture_id_e id;
    char const *path;
};

extern const texture_prefab_t texture_prefab[];

sfTexture **initialize_textures(void);

#endif