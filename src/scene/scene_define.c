/*
** EPITECH PROJECT, 2019
** scene_define.c
** File description:
** 
*/

#include "rpg.h"

void scene_set_load(global_data_t *data, char *name,
void (*load)(global_data_t *))
{
    scene_t *scene = scene_get(data, name);

    if (!scene)
        return;
    scene->load = load;
}

void scene_set_unload(global_data_t *data, char *name,
void (*unload)(global_data_t *))
{
    scene_t *scene = scene_get(data, name);

    if (!scene)
        return;
    scene->unload = unload;
}

void scene_set_event(global_data_t *data, char *name,
void (*event)(global_data_t *))
{
    scene_t * scene = scene_get(data, name);

    if (!scene)
        return;
    scene->event = event;
}