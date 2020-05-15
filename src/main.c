/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main program
*/

#include "rpg.h"


void unload_struct(global_data_t *data)
{
    sfRenderWindow_destroy(data->window);
    for (scene_t *scene = data->objects->scene;\
scene != NULL; scene = data->objects->scene)
        scene_destroy(data, scene->name);
    free(data);
}

int main(void)
{
    global_data_t *data = init_gdata();

    srand(time(NULL));
    scene_load(data, "controls", false);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    sfRenderWindow_setSize(data->window, sfRenderWindow_getSize(data->window));
    while (sfRenderWindow_isOpen(data->window)) {
        event_handler(data, data->active_scene);
        sfRenderWindow_clear(data->window, sfBlue);
        scene_draw(data, data->active_scene->name, false, false);
        sfRenderWindow_display(data->window);
        travel_act(data);
    }
    unload_struct(data);
    return (0);
}