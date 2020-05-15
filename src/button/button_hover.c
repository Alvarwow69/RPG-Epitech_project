/*
** EPITECH PROJECT, 2020
** button_hover.c
** File description:
** check hover
*/

#include "rpg.h"

void set_texture_button(button_t *button, sfTexture *texture, sfIntRect rect)
{
    if (!texture)
        return;
    sfSprite_setTexture(button->sprite, texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, rect);
    button->rect = sfSprite_getGlobalBounds(button->sprite);
}

static int test_hover_pos(sfVector2f pixel_pos, sfVector2f p_game,
button_t *button)
{
    return (pixel_pos.x < p_game.x + button->rect.width &&
    pixel_pos.x > p_game.x &&
    pixel_pos.y < p_game.y + button->rect.height &&
    pixel_pos.y > p_game.y);
}

void hover_button(global_data_t *data, button_t *button, sfVector2f pixel_pos,
sfTime time)
{
    node_t *node = node_get(data, button->gameobject->node);
    sfVector2f p_game = sfTransformable_getPosition
    (button->gameobject->transform);
    sfVector2f p_node = sfTransformable_getPosition(node->transform);

    p_game.x += p_node.x;
    p_game.y += p_node.y;
    if (test_hover_pos(pixel_pos, p_game, button)) {
        if (button->help_time == -1 && !button->help) {
            button->help_time = time.microseconds;
        }
        set_texture_button(button, button->hover, button->hover_rect);
        if ((time.microseconds - button->help_time) / 1000000 > 0.5f) {
            button->help = 1;
            button->help_time = -1;
            draw_help_button(data, button);
        }
    } else {
        button->help_time = -1;
        button->help = 0;
    }
}