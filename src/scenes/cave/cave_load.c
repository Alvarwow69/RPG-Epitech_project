/*
** EPITECH PROJECT, 2020
** cave_load.c
** File description:
** 
*/

#include "rpg.h"

void cave_create_background(global_data_t *data)
{
    node_create(data, "background_cave", "cave");
    gameobject_create(data, "cave_background",
    "background_cave", TYPE_BACKGROUND);
    gameobject_set_texture(data, "cave_background",
    data->ressources->textures[TEXTURE_BACK_CAVE]);
    gameobject_set_scale(data, "cave_background", (sfVector2f){2, 2});
}

void cave_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "cave");
    sfVector2f start = {500, 700};

    create_map(data, "save/map_cave", scene->name);
    cave_create_background(data);
    create_player(data, start, "cave");
    create_inventory_screen(data, "cave");
    init_ui(data, "cave");
    scene->init_pos = sfView_getCenter(scene->game);
    scene->max_width = 6650;
    scene->max_height = 2000;
    sfView_setCenter(scene->game, (sfVector2f){start.x + 500, start.y});
    sfClock_restart(data->clock);
    load_save(data);
    save_to_player(data);
    init_shop(data, "cave");
    data->loading->loaded = true;
}