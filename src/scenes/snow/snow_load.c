/*
** EPITECH PROJECT, 2020
** snow_load.c
** File description:
** 
*/

#include "rpg.h"

void snow_create_background(global_data_t *data)
{
    node_create(data, "background_snow", "snow");
    gameobject_create(data, "snow_background",
    "background_snow", TYPE_BACKGROUND);
    gameobject_set_texture(data, "snow_background",
    data->ressources->textures[TEXTURE_BACK_SNOW]);
}

void create_pnj_snow(global_data_t *data)
{
    pnj_create(data, "Snow_1", "snow", PNJID_SNOW_1);
    pnj_create(data, "Snow_2", "snow", PNJID_SNOW_2);
    monster_create(data, "Lilodon", "snow", MSTID_LILODON);
}

void snow_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "snow");
    sfVector2f start = {500, 450};

    create_map(data, "save/map_snow", scene->name);
    create_player(data, start, "snow");
    create_inventory_screen(data, "snow");
    init_ui(data, "snow");
    snow_create_background(data);
    create_pnj_snow(data);
    scene->init_pos = sfView_getCenter(scene->game);
    scene->max_width = 6650;
    scene->max_height = 250;
    sfClock_restart(data->clock);
    load_save(data);
    save_to_player(data);
    init_shop(data, "snow");
    sfView_setCenter(scene->game, (sfVector2f){start.x + 500, start.y});
    data->loading->loaded = true;
}