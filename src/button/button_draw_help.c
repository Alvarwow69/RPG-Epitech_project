/*
** EPITECH PROJECT, 2019
** button_draw_help.c
** File description:
** display help
*/

#include "rpg.h"

static void set_up_help_pos(button_t *button, sfFloatRect sprite, float y)
{
    sfVector2f pos;
    sfVector2f b_position = sfTransformable_getPosition
    (button->gameobject->transform);

    if (y == 1.0f) {
        pos.x = b_position.x;
        pos.y = b_position.y - sprite.height - 10;
        sfSprite_setPosition(button->help_sprite, pos);
    } else if (y == -1.0f) {
        pos.x = b_position.x;
        pos.y = b_position.y + sprite.height + 10;
        sfSprite_setPosition(button->help_sprite, pos);
    }
}

static void set_right_help_pos(button_t *button, sfFloatRect sprite, float x)
{
    sfVector2f pos;
    sfVector2f b_position = sfTransformable_getPosition
    (button->gameobject->transform);

    if (x == 1.0f) {
        pos.x = b_position.x - sprite.width - 10;
        pos.y = b_position.y;
        sfSprite_setPosition(button->help_sprite, pos);
    } else if (x == -1.0f) {
        pos.x = b_position.x + (float) button->rect.width * 2 + 10;
        pos.y = b_position.y;
        sfSprite_setPosition(button->help_sprite, pos);
    }
}

void draw_help_button(global_data_t *data, button_t *button)
{
    sfVector2f h_position = sfTransformable_getPosition(button->h_transform);

    set_up_help_pos(button, button->rect, h_position.y);
    set_right_help_pos(button, button->rect, h_position.x);
    if (button->help_sprite)
        sfRenderWindow_drawSprite(data->window, button->help_sprite, NULL);
}