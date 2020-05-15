/*
** EPITECH PROJECT, 2019
** scene_draw.c
** File description:
** 
*/

#include "rpg.h"

void scene_draw(global_data_t *data, char *name, bool unload, bool screen)
{
    scene_t *scene = scene_get(data, name);
    node_t *node = NULL;

    if (scene == NULL) {
        my_printf("%sscene_draw: can't draw %s%s%s.%s\n", LRED, PURPLE, name,
        LRED, RESET);
        return;
    }
    node = scene->node;
    if (data->active_scene && cmp_string(data->active_scene->name, scene->name)) {
        if (!unload)
            data->prev_scene = data->active_scene;
        if (unload)
            scene_unload(data, data->active_scene);
    }
    data->active_scene = scene;
    if (!scene->is_load)
        scene_load(data, name, screen);
    while (node && cmp_string(scene->name, node->scene) == 0) {
        node_draw(data, node);
        node = node->next;
    }
}