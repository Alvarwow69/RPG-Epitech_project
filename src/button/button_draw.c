/*
** EPITECH PROJECT, 2019
** button_event.c
** File description:
** drawn one button
*/

#include <engine/gameobject.h>
#include "rpg.h"

static void clickable_button(button_t *button)
{
    if (!button->is_clickable && button->hover)
        sfSprite_setTexture(button->sprite, button->hover, sfTrue);
}

void define_texture_button(global_data_t *data, sfView *interface,
button_t *button)
{
    sfVector2i mouse_pos;
    sfVector2f pixel_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, mouse_pos,
    interface);
    set_texture_button(button, button->stand, button->set_rect);
    hover_button(data, button, pixel_pos, sfClock_getElapsedTime(data->clock));
    click_button(button, sfClock_getElapsedTime(data->clock));
    clickable_button(button);
}

sfRenderStates get_button_state(global_data_t *gdata, game_object_t *gameobject,
sfTransformable *transformable)
{
    node_t *node = node_get(gdata, gameobject->node);
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfTransform node_transform =\
    sfTransformable_getTransform(node->transform);
    sfTransform gameobject_transform =\
    sfTransformable_getTransform(transformable);

    sfTransform_combine(&(states.transform), &gameobject_transform);
    sfTransform_combine(&(states.transform), &node_transform);
    return (states);
}

void draw_button(global_data_t *data, game_object_t *game, scene_t *scene)
{
    sfRenderStates button;
    sfRenderStates text;

    button = get_button_state(data, game, (game->object.button->pressed)
    ? game->object.button->p_transform : game->transform);
    sfRenderWindow_setView(data->window, scene->interface);
    define_texture_button(data, scene->interface, game->object.button);
    text = get_button_state(data, game, game->object.button->text_pos);
    sfRenderWindow_drawSprite(data->window, game->object.button->sprite,
    &button);
    if (game->object.button->text)
        sfRenderWindow_drawText(data->window, game->object.button->text, &text);
}