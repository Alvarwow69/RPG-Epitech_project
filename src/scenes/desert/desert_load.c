/*
** EPITECH PROJECT, 2020
** desert_load.c
** File description:
** 
*/

#include "rpg.h"

void desert_create_background(global_data_t *data)
{
    node_create(data, "background_desert", "desert");
    gameobject_create(data, "desert_background",
    "background_desert", TYPE_BACKGROUND);
    gameobject_set_texture(data, "desert_background",
    data->ressources->textures[TEXTURE_BACK_DESERT]);
    gameobject_set_scale(data, "desert_background", (sfVector2f){4, 4});
}

void create_pnj_desert(global_data_t *data)
{
    pnj_create(data, "Desert_1", "desert", PNJID_SAND_1);
    pnj_create(data, "Desert_2", "desert", PNJID_SAND_2);
}

void desert_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "desert");
    sfVector2f start = {500, 500};

    create_map(data, "save/map_desert", scene->name);
    create_player(data, start, "desert");
    create_inventory_screen(data, "desert");
    init_ui(data, "desert");
    create_pnj_desert(data);
    desert_create_background(data);
    scene->default_pos = (scene->default_pos.x == 0) ? sfView_getCenter(scene->game) : scene->default_pos;
    scene->init_pos = sfView_getCenter(scene->game);
    sfView_setCenter(scene->game, (sfVector2f){start.x + 500, start.y});
    scene->max_width = 6650;
    scene->max_height = 250;
    sfClock_restart(data->clock);
    load_save(data);
    save_to_player(data);
    init_shop(data, "desert");
    data->loading->loaded = true;
}