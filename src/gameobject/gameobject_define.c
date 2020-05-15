/*
** EPITECH PROJECT, 2019
** gameobject_define.c
** File description:
** 
*/

#include "rpg.h"

void gameobject_set_sprite(global_data_t *data, char *name, sfTexture *texture)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (gameobject == NULL) {
        my_printf("%sgameobject_set_sprite: can't set %s%s%s sprite.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfSprite_setTexture(gameobject->object.sprite, texture, sfTrue);
}

void gameobject_set_position(global_data_t *data, char *name, sfVector2f pos)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (gameobject == NULL) {
        my_printf("%sgameobject_set_position: can't set %s%s%s position.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfTransformable_setPosition(gameobject->transform, pos);
}

void gameobject_set_tag(global_data_t *data, char *name, tag *tag)
{
    game_object_t *gameobject = gameobject_get(data, name);
    int len = 0;

    if (gameobject == NULL) {
        my_printf("%sgameobject_set_tag: can't set %s%s%s tags.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    for (int ctr = 0; tag[ctr] != TAG_END; ctr += 1)
        len += 1;
    gameobject->tags = malloc(sizeof(tag) * (len + 1));
    for (int ctr = 0; tag[ctr] != TAG_END; ctr += 1)
        gameobject->tags[ctr] = tag[ctr];
    gameobject->tags[len] = TAG_END;
}

void gameobject_set_texture(global_data_t *data, char *name, sfTexture *texture)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (gameobject == NULL) {
        my_printf("%sgameobject_set_texture: can't set %s%s%s texture.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfSprite_setTexture(gameobject->object.sprite, texture, sfTrue);
}

void gameobject_set_texture_rect(global_data_t *data, char *name,
sfIntRect rect)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (gameobject == NULL) {
        my_printf("%sgameobject_set_texture_rect: can't set %s%s%s"
        " texture rect.%s\n", LRED, PURPLE, name, LRED, RESET);
        return;
    }
    sfSprite_setTextureRect(gameobject->object.sprite, rect);
}