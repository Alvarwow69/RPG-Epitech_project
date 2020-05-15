/*
** EPITECH PROJECT, 2019
** scene_load.c
** File description:
** 
*/

#include "rpg.h"

void display_loading_screen(global_data_t *data)
{
    sfRenderWindow_setView(data->window, data->default_view);
    sfRenderWindow_drawSprite(data->window, data->loading->sprite, NULL);
    sfRenderWindow_drawSprite(data->window, data->loading->lilodon, NULL);
    sfSprite_rotate(data->loading->lilodon, 7);
}

void scene_load(global_data_t *data, char *name, bool screen)
{
    scene_t *scene = scene_get(data, name);

    if (scene == NULL || scene->is_load == 1) {
        my_printf("%sscene_load: can't load %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    my_printf("%sscene_load: load %s%s%s scene.%s\n"
            , YELLOW, PURPLE, name, YELLOW, RESET);
    if (screen) {
        data->loading->loader = sfThread_create(scene->load, data);
        data->loading->loaded = false;
        sfThread_launch(data->loading->loader);
        while (!data->loading->loaded) {
            sfRenderWindow_clear(data->window, sfBlack);
            display_loading_screen(data);
            sfRenderWindow_display(data->window);
        }
        sfThread_terminate(data->loading->loader);
        sfThread_destroy(data->loading->loader);
    } else
        (*scene->load)(data);
    scene->is_load = 1;
}

void scene_unload(global_data_t *data, scene_t *scene)
{
    if (!scene->is_load || !scene->unload) {
        if (!scene->unload) {
            scene->is_load = 0;
        }
        my_printf("%sscene_unload: can't unload %s%s%s.%s\n",
        LRED, PURPLE, scene->name, LRED, RESET);
        return;
    }
    my_printf("%sscene_unload: unload %s%s%s scene.%s\n"
    , YELLOW, PURPLE, scene->name, YELLOW, RESET);
    (*scene->unload)(data);
    scene->is_load = 0;
}