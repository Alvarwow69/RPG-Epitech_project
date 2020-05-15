/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** textures.c
*/

#include "rpg.h"

const texture_prefab_t texture_prefab[] = {
        {BACK, "rsc/back.png"},
        {BUTTON, "rsc/button.png"},
        {BUTTON_HOVER, "rsc/button_hover.png"},
        {BUTTON_PRESS, "rsc/button_press.png"},
        {BUTTON_L, "rsc/button_l.png"},
        {BUTTON_L_HOVER, "rsc/button_l_hover.png"},
        {BUTTON_L_PRESS, "rsc/button_l_press.png"},
        {QUEST_BACKGROUND, "rsc/quest/quest.png"},
        {CONTROLS_BACKGROUND, "rsc/controls/background_controls.png"},
        {CONTROLS_BACKGROUND_2, "rsc/controls/background_controls_2.png"},
        {TRAVEL_WATER, "rsc/travel/water.png"},
        {TRAVEL_SHIP_E, "rsc/travel/ship.e.png"},
        {TRAVEL_SHIP_N, "rsc/travel/ship.n.png"},
        {TRAVEL_SHIP_S, "rsc/travel/ship.s.png"},
        {TRAVEL_SHIP_W, "rsc/travel/ship.w.png"},
        {TRAVEL_SAND, "rsc/travel/sand.png"},
        {TRAVEL_CAVE, "rsc/travel/cave.png"},
        {TRAVEL_SNOW, "rsc/travel/snow.png"},
        {TRAVEL_JUNGLE, "rsc/travel/jungle.png"},
        {TEXTURE_TILE_MAP, "rsc/tile_map.png"},
        {TEXTURE_BACK, "rsc/back.png"},
        {TEXTURE_TRAVEL_BACKGROUND, "rsc/travel/Background_travel.jpg"},
        {TEXTURE_TRAVEL_BACKGROUND2, "rsc/travel/Cadre_travel.png"},
        {TEXTURE_INV_ICON, "rsc/inventory_icon.png"},
        {TEXTURE_BARE_CHARACTER, "rsc/character_rpg.png"},
        {TEXTURE_ARMOR1_CHARACTER, "rsc/character_rpg_armor1.png"},
        {TEXTURE_PLAYER_INVENTORY, "rsc/Player_Inventory.png"},
        {TEXTURE_UI_BAR, "rsc/UI_bar.png"},
        {TEXTURE_ACTIVE_BAR, "rsc/active_bar.png"},
        {TEXTURE_WATER, "rsc/water.png"},
        {TEXTURE_MOB_LILODON, "rsc/lilodon.png"},
        {TEXTURE_MHP_BAR, "rsc/Monster_hp_bar.png"},
        {TEXTURE_SWORD, "rsc/sword.png"},
        {TEXTURE_PICKAXE, "rsc/Pickaxe.png"},
        {TEXTURE_BACK_MAIN, "rsc/main.png"},
        {TEXTURE_BACK_PAUSE, "rsc/pause.jpg"},
        {TEXTURE_BACK_DESERT, "rsc/desert.png"},
        {TEXTURE_BACK_CAVE, "rsc/cave.jpg"},
        {TEXTURE_BACK_SNOW, "rsc/snow.png"},
        {TEXTURE_LOADING, "rsc/loading.png"},
        {TEXTURE_SHOP_SCREEN, "rsc/shop_screen.png"},
        {TEXTURE_END, NULL}
};

sfTexture **initialize_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * TEXTURE_END);

    if (textures == NULL)
        return (print_error("Error: Can't create texture list\n"), NULL);
    for (int ctr = 0; ctr < TEXTURE_END; ctr += 1) {
        textures[ctr] = \
        sfTexture_createFromFile(texture_prefab[ctr].path, NULL);
        if (textures[ctr] == NULL)
            my_printf("%sinitialize_texture: can't load %s%s%s texture.%s\n"
            , LRED, PURPLE, texture_prefab[ctr].path, LRED, RESET);
    }
    return (textures);
}