/*
** EPITECH PROJECT, 2019
** event_handler.c
** File description:
** event
*/

#include "rpg.h"

void event_resized(global_data_t *data, sfEvent event)
{
    scene_t *scene = data->active_scene;

    if (!scene)
        return;
    if (event.type == sfEvtResized) {
        scene->size_game.x = event.size.width;
        scene->size_game.y = event.size.height;
        sfView_setSize(scene->game,
        (sfVector2f) {(float)scene->size_game.x, (float)scene->size_game.y});
    }
}

void event_handler(global_data_t *data, scene_t *scene)
{
    data->key->mouse_wheel = 0;
    while (sfRenderWindow_pollEvent(data->window, &data->event)) {
        event_keyboard(data->event, data);
        event_resized(data, data->event);
        if (data->event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        quest_event(data);
        controls_event(data);
    }
    if (scene && scene->event)
        (*scene->event)(data);
}