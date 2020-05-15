/*
** EPITECH PROJECT, 2020
** bloc_draw.c
** File description:
** 
*/

#include "rpg.h"

void bloc_draw(global_data_t *data, game_object_t *gameobject, scene_t *scene)
{
    float percent = percent = 100 -
    (((float)gameobject->object.bloc->destruction_level / 20) * 100);
    char **list_name = str_to_tab(gameobject->name, "-");
    sfIntRect rect = tile_map[get_number(list_name[3])].rect;
    sfRenderStates states;

    sfRenderWindow_setView(data->window, scene->game);
    if (!gameobject->object.bloc->broken)
        texture_rect_percent(gameobject->object.bloc->sprite
        , rect, percent, "top");
    states = get_render_states(data, gameobject);
    sfRenderWindow_drawSprite(data->window,
    gameobject->object.bloc->sprite, &states);
    free_tab(list_name);
}