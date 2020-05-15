/*
** EPITECH PROJECT, 2020
** map_load.c
** File description:
** 
*/

#include "rpg.h"

void map_create_background(global_data_t *data)
{
    node_create(data, "background_map", "map");
    gameobject_create(data, "map_background",
    "background_map", TYPE_BACKGROUND);
    gameobject_set_texture(data, "map_background",
    data->ressources->textures[BACK]);
    gameobject_set_scale(data, "map_background", (sfVector2f){5, 5});
}

void create_pnj(global_data_t *data)
{
    pnj_create(data, "Villager_1", "map", PNJID_VILLAGER_1);
    pnj_create(data, "Villager_2", "map", PNJID_VILLAGER_2);
    pnj_create(data, "Villager_3", "map", PNJID_VILLAGER_3);
    pnj_create(data, "Villager_4", "map", PNJID_VILLAGER_4);
    monster_create(data, "Lilodon", "map", MSTID_LILODON);
}

void create_player(global_data_t *data, sfVector2f start, char *scene)
{
    node_create(data, "player_node", scene);
    node_set_layer(data, "player_node", 2);
    gameobject_create(data, "player_go", "player_node", TYPE_PLAYER);
    gameobject_set_tag(data, "player_go", \
(tag[]){TAG_ENTITY, TAG_PLAYER, TAG_END});
    node_set_position(data, "player_node", start);
    gameobject_get(data, "player_go")->object.player->move->total_time = 0;
    gameobject_get(data, "player_go")->object.player->move->vec.y = 0;
    data->player_node = node_get(data, "player_node");
    sfTransformable_setOrigin\
(data->player_node->transform, (sfVector2f){64.5, 0});
}

void map_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "map");
    sfVector2f start = {500, 500};

    create_map(data, "save/map_village", "map");
    create_player(data, start, "map");
    create_inventory_screen(data, "map");
    create_pnj(data);
    init_ui(data, "map");
    map_create_background(data);
    scene->init_pos = sfView_getCenter(scene->game);
    scene->max_width = 6600;
    scene->max_height = 850;
    sfView_setCenter(scene->game, (sfVector2f){start.x + 500, start.y});
    sfClock_restart(data->clock);
    load_save(data);
    save_to_player(data);
    init_shop(data, "map");
    data->loading->loaded = true;
}