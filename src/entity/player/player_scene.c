/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** create_player_scene.c
*/

#include "rpg.h"

void player_scene_load(global_data_t *gdata)
{
// Player ---->
    node_create(gdata, "player_node", "player_scene");
    gameobject_create(gdata, "player_go", "player_node", TYPE_PLAYER);
    gameobject_set_tag(gdata, "player_go", (tag[]){TAG_ENTITY, TAG_PLAYER, TAG_END});
    node_set_position(gdata, "player_node", (sfVector2f){900, 500});
    gdata->player_node = node_get(gdata, "player_node");
    sfTransformable_setOrigin(gdata->player_node->transform, (sfVector2f){64.5, 0});
// ----------->

// Inventory ->
    create_inventory_screen(gdata, "player_scene");
// ----------->

// UI -------->
    init_ui(gdata, "player_scene");
// ----------->

// PNJ ------->
    pnj_create(gdata, "A Random", "player_scene", PNJID_NONE);
    pnj_create(gdata, "A Villager", "player_scene", PNJID_VILLAGER_1);
// ----------->

// Monster --->
    monster_create(gdata, "Lilodon", "player_scene", MSTID_LILODON);
// ----------->
}

void player_scene_unload(global_data_t *gdata)
{
    node_destroy(gdata, "player_node");
    gdata->player_node = NULL;
    node_destroy(gdata, "player_inv_node");
}

void player_scene_create(global_data_t *gdata)
{
    scene_create(gdata, "player_scene");
    scene_set_load(gdata, "player_scene", &player_scene_load);
    scene_set_unload(gdata, "player_scene", &player_scene_unload);
    scene_set_event(gdata, "player_scene", &player_scene_event);
}