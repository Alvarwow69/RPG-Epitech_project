/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** gameobject_set_origin.c
*/

#include "rpg.h"

void gameobject_set_origin(global_data_t *gdata, char *name, sfVector2f origin)
{
    game_object_t *go = gameobject_get(gdata, name);

    if (go == NULL)
        return;
    sfTransformable_setOrigin(go->transform, origin);
}