/*
** EPITECH PROJECT, 2019
** button_click.c
** File description:
** click
*/

#include <engine/gameobject.h>
#include "rpg.h"

void click_button(button_t *button, sfTime time)
{
    float seconds = 0;

    if (button->pressed) {
        button->time = time.microseconds;
        if (button->press)
            set_texture_button(button, button->press, button->click_rect);
        button->pressed = 0;
    }
    if (button->clicked) {
        seconds = (time.microseconds - button->time) / 1000000;
        button->clicked = (seconds > 0.5) ? 0 : 1;
        button->time = (seconds > 0.5) ? 0 : button->time;
    }
}

static int test_position(sfVector2f pixel_pos, sfVector2f p_game,
game_object_t *game)
{
    return (pixel_pos.x < p_game.x + game->object.button->rect.width &&
    pixel_pos.x > p_game.x &&
    pixel_pos.y < p_game.y + game->object.button->rect.height &&
    pixel_pos.y > p_game.y);
}

int click_action(global_data_t *data, game_object_t *game)
{
    game->object.button->pressed = 1;
    if (game->object.button->action && !game->object.button->clicked) {
        game->object.button->clicked = 1;
        play_sound_reset(data, SOUND_CLIC);
        (*game->object.button->action)(data, game->object.button);
    }
    return (1);
}

static sfVector2f get_pose_game(node_t *node, game_object_t *game)
{
    sfVector2f p_node;
    sfVector2f p_game;

    p_node = sfTransformable_getPosition(node->transform);
    p_game = sfTransformable_getPosition(game->transform);
    p_game.x += p_node.x;
    p_game.y += p_node.y;
    return (p_game);
}

int check_button(global_data_t *data, sfVector2i position, sfView *interface,
node_t *node)
{
    game_object_t *game = NULL;
    sfVector2f pixel_pos;
    sfVector2f p_game;

    if (!node)
        return (0);
    game = node->gameobjects;
    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, position,
    interface);
    while (game && !cmp_string(node->name, game->node)) {
        p_game = get_pose_game(node, game);
        if (game->type != TYPE_BUTTON || !game->object.button->is_clickable) {
            game = game->next;
            continue;
        }
        if (test_position(pixel_pos, p_game, game) && click_action(data, game))
            return (1);
        game = game->next;
    }
    return (0);
}