/*
** EPITECH PROJECT, 2019
** scene_create.c
** File description:
** 
*/

#include "rpg.h"

scene_t *scene_get(global_data_t *data, char *name)
{
    scene_t *scene = data->objects->scene;

    while (scene) {
        if (cmp_string(scene->name, name) == 0)
            return (scene);
        scene = scene->next;
    }
    my_printf("%s: scene not found!\n", name);
    return (NULL);
}

void define_default_value_scene(global_data_t *data, scene_t *scene,
scene_t *last)
{
    scene->load = NULL;
    scene->unload = NULL;
    scene->event = NULL;
    scene->node = NULL;
    scene->pause = false;
    scene->next = NULL;
    scene->default_pos = (sfVector2f){0, 0};
    scene->is_load = 0;
    if (last)
        last->next = scene;
    else
        data->objects->scene = scene;
}

void scene_create(global_data_t *data, char *name)
{
    scene_t *scene = malloc(sizeof(scene_t));
    scene_t *last = data->objects->scene;

    while (last && last->next) {
        if (cmp_string(last->name, name) == 0) {
            write(2, "Scene already exist!\n", 21);
            return;
        }
        last = last->next;
    }
    my_printf("%sscene_create: create %s%s%s scene.%s\n",
    YELLOW, PURPLE, name, YELLOW, RESET);
    scene->name = string_dup(name);
    scene->prev = last;
    scene->interface = sfView_copy(sfRenderWindow_getDefaultView(data->window));
    scene->game = sfView_copy(sfRenderWindow_getDefaultView(data->window));
    define_default_value_scene(data, scene, last);
}

void destroy_all_scene(global_data_t *data)
{
    scene_t *scene = data->objects->scene;
    scene_t *delete = NULL;

    while (scene) {
        delete = scene;
        scene = scene->next;
        free(delete);
    }
}