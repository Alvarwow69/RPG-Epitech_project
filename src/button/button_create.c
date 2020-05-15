/*
** EPITECH PROJECT, 2019
** create_button.c
** File description:
** all function to create button
*/

#include <engine/gameobject.h>
#include "rpg.h"

static void set_default_value(button_t *new_button)
{
    new_button->text = NULL;
    new_button->stand = NULL;
    new_button->press = NULL;
    new_button->hover = NULL;
    new_button->help_sprite = NULL;
    new_button->help_text = NULL;
    new_button->action = NULL;
    new_button->next = NULL;
}

button_t *init_button_struct(void)
{
    button_t *new_button = malloc(sizeof(button_t));

    if (!new_button)
        return (NULL);
    set_default_value(new_button);
    new_button->time = 0;
    new_button->h_transform = sfTransformable_create();
    new_button->text_pos = sfTransformable_create();
    new_button->sprite = sfSprite_create();
    new_button->rect = sfSprite_getGlobalBounds(new_button->sprite);
    new_button->pressed = 1;
    new_button->clicked = 1;
    new_button->is_clickable = 1;
    new_button->help_time = 0;
    new_button->help = 0;
    return (new_button);
}

int button_create(global_data_t *data, char *name, char *node,
sfTexture *texture)
{
    game_object_t *button = NULL;

    gameobject_create(data, name, node, TYPE_BUTTON);
    button = gameobject_get(data, name);
    button->object.button->stand = texture;
    button->object.button->gameobject = button;
    sfSprite_setTexture(button->object.button->sprite, texture, sfTrue);
    button->object.button->set_rect =
    sfSprite_getTextureRect(button->object.button->sprite);
    button->object.button->hover_rect =
    sfSprite_getTextureRect(button->object.button->sprite);
    button->object.button->click_rect =
    sfSprite_getTextureRect(button->object.button->sprite);
    button->object.button->p_transform =
    sfTransformable_copy(button->transform);
    return (0);
}

button_t *button_get(global_data_t *data, char *name)
{
    game_object_t *wanted = data->objects->game_object;

    while (wanted) {
        if (!cmp_string(name, wanted->name) && wanted->type == TYPE_BUTTON)
            return (wanted->object.button);
        wanted = wanted->next;
    }
    my_printf("%s: button not found!\n", name);
    return (NULL);
}