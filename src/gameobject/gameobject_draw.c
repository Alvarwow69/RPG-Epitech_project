/*
** EPITECH PROJECT, 2019
** gameobject_draw.c
** File description:
** 
*/

#include <engine/gameobject.h>
#include "rpg.h"

sfRenderStates get_render_states(global_data_t *gdata,
game_object_t *gameobject)
{
    node_t *node = node_get(gdata, gameobject->node);
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfTransform node_transform =\
    sfTransformable_getTransform(node->transform);
    sfTransform gameobject_transform =\
    sfTransformable_getTransform(gameobject->transform);

    sfTransform_combine(&(states.transform), &gameobject_transform);
    sfTransform_combine(&(states.transform), &node_transform);
    return (states);
}

void drawn_other_type(global_data_t *data, game_object_t *gameobject,
scene_t *scene, sfRenderStates states)
{
    switch (gameobject->type) {
    case TYPE_BACKGROUND:
        sfRenderWindow_setView(data->window, scene->interface);
        sfRenderWindow_drawSprite(data->window, gameobject->object.sprite,
        &states);
        break;
    case TYPE_TEXT:
        draw_text(data, gameobject, states);
        break;
    case TYPE_BLOC:
        bloc_draw(data, gameobject, scene);
        break;
    case TYPE_PNJ:
        pnj_draw(data->window, gameobject->object.pnj, states);
        break;
    default:
        my_printf("%sCan't draw %s%s%s.%s\n"
        , LRED, PURPLE, gameobject->name, LRED, RESET);
    }
}

void gameobject_draw_image(global_data_t *data, game_object_t *gameobject\
, node_t *node)
{
    sfRenderStates states = get_render_states(data, gameobject);
    scene_t *scene = scene_get(data, node->scene);

    sfRenderWindow_setView(data->window, scene->game);
    sfRenderWindow_drawSprite(data->window,
    gameobject->object.sprite, &states);
}

void gameobject_draw_player(global_data_t *data, game_object_t *gameobject\
, node_t *node)
{
    sfRenderStates states = get_render_states(data, gameobject);
    scene_t *scene = scene_get(data, node->scene);

    sfRenderWindow_setView(data->window, scene->game);
    player_draw(data->window, gameobject->object.player, states);
}

void gameobject_draw(global_data_t *data, game_object_t *gameobject
, node_t *node)
{
    sfRenderStates states = get_render_states(data, gameobject);
    scene_t *scene = scene_get(data, node->scene);

    if (!gameobject->is_draw || !gameobject->is_active)
        return;
    switch (gameobject->type) {
    case TYPE_IMAGE:
        gameobject_draw_image(data, gameobject, node);
        break;
    case TYPE_BUTTON:
        draw_button(data, gameobject, scene);
        break;
    case TYPE_PLAYER:
        gameobject_draw_player(data, gameobject, node);
        break;
    case TYPE_MONSTER:
        monster_draw(data->window, gameobject->object.monster, states);
        break;
    default:
        drawn_other_type(data, gameobject, scene, states);
    }
}