/*
** EPITECH PROJECT, 2020
** screate_main.c
** File description:
** 
*/

#include "rpg.h"

static void create_scene_second_part(global_data_t *data)
{
    scene_create(data, "setting");
    scene_set_load(data, "setting", &setting_load);
    scene_set_event(data, "setting", &option_event);
    scene_create(data, "controls");
    scene_set_load(data, "controls", &controls_load);
    scene_set_event(data, "controls", &controls_event);
    scene_create(data, "pause");
    scene_set_load(data, "pause", &pause_load);
    scene_set_event(data, "pause", &pause_event);
}

void create_scene_game(global_data_t *data)
{
    scene_create(data, "map");
    scene_set_load(data, "map", &map_load);
    scene_set_event(data, "map", &map_event);
    scene_set_unload(data, "map", &map_unload);
    scene_create(data, "desert");
    scene_set_load(data, "desert", &desert_load);
    scene_set_event(data, "desert", &desert_event);
    scene_set_unload(data, "desert", &desert_unload);
    scene_create(data, "cave");
    scene_set_load(data, "cave", &cave_load);
    scene_set_event(data, "cave", &cave_event);
    scene_set_unload(data, "cave", &cave_unload);
    scene_create(data, "snow");
    scene_set_load(data, "snow", &snow_load);
    scene_set_event(data, "snow", &snow_event);
    scene_set_unload(data, "snow", &snow_unload);
}

void create_scene(global_data_t *data)
{
    scene_create(data, "main");
    scene_set_load(data, "main", &main_load);
    scene_set_unload(data, "main", &main_unload);
    scene_set_event(data, "main", &main_event);
    scene_create(data, "map_editor");
    scene_set_load(data, "map_editor", &editor_load);
    scene_set_event(data, "map_editor", &editor_event);
    scene_set_unload(data, "map_editor", &editor_unload);
    create_scene_second_part(data);
    player_scene_create(data);
    create_scene_game(data);
    scene_draw(data, "main", false, false);
}