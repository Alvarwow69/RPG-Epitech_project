/*
** EPITECH PROJECT, 2019
** button_define.c
** File description:
** define some properties
*/

#include "rpg.h"

void button_set_position(global_data_t *data, char *name, sfVector2f position)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    sfTransformable_setPosition(button->gameobject->transform, position);
    button->p_transform = sfTransformable_copy(button->gameobject->transform);
}

void button_set_scale(global_data_t *data, char *name, sfVector2f scale)
{
    button_t *button = button_get(data, name);

    if (!button)
        return;
    sfSprite_setScale(button->sprite, scale);
}

void button_set_action(global_data_t *data, char *name,
void (*action)(global_data_t *, button_t *button))
{
    button_t *button = button_get(data, name);

    (void)button;
    if (!button)
        return;
    button->action = action;
}

void button_set_press_position(global_data_t *data, char *name, sfVector2f pos)
{
    button_t *button = button_get(data, name);
    sfVector2f new_pos;

    if (!button)
        return;
    new_pos = sfTransformable_getPosition(button->gameobject->transform);
    new_pos.x += pos.x;
    new_pos.y += pos.y;
    sfTransformable_setPosition(button->p_transform, new_pos);
}