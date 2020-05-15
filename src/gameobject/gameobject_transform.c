/*
** EPITECH PROJECT, 2020
** gameobject_transform.c
** File description:
** 
*/

#include <engine/gameobject.h>
#include "rpg.h"

void gameobject_move(global_data_t *data, char *name, sfVector2f move)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (!gameobject)
        return;
    sfTransformable_move(gameobject->transform, move);
}

void gameobject_rotate(global_data_t *data, char *name, float rotate)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (!gameobject)
        return;
    sfTransformable_rotate(gameobject->transform, rotate);
}

void gameobject_scale(global_data_t *data, char *name, sfVector2f scale)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (!gameobject)
        return;
    if (gameobject->type == TYPE_BACKGROUND || gameobject->type == TYPE_IMAGE \
|| gameobject->type == TYPE_BLOC)
        sfSprite_scale(gameobject->object.sprite, scale);
    else
        sfTransformable_scale(gameobject->transform, scale);
}

void gameobject_set_scale(global_data_t *data, char *name, sfVector2f scale)
{
    game_object_t *gameobject = gameobject_get(data, name);

    if (!gameobject)
        return;
    if (gameobject->type == TYPE_BACKGROUND || gameobject->type == TYPE_IMAGE \
|| gameobject->type == TYPE_BLOC)
        sfSprite_setScale(gameobject->object.sprite, scale);
    else
        sfTransformable_setScale(gameobject->transform, scale);
}