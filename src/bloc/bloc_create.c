/*
** EPITECH PROJECT, 2020
** bloc_create.c
** File description:
** 
*/

#include "rpg.h"

bloc_t *bloc_get(global_data_t *data, char *name)
{
    game_object_t *game = data->objects->game_object;

    while (game) {
        if (cmp_string(game->name, name) == 0)
            return (game->object.bloc);
        game = game->next;
    }
    my_printf("%s: bloc not found!\n", name);
    return (NULL);
}

collide_shape_t *create_bloc_collision(global_data_t *data, char *name, int id)
{
    collide_shape_t *cshape = NULL;

    if (id == TM_SING)
        cshape = collide_shape_create(data
        , concat_fstring("%s_bloc_collision", name)
        , name, CTYPE_INTERACT);
    else
        cshape = collide_shape_create(data
        , concat_fstring("%s_bloc_collision", name)
        , name, CTYPE_BLOCK);
    collide_shape_add_point(cshape, (sfVector2f){1, 1});
    collide_shape_add_point(cshape, (sfVector2f){47, 1});
    collide_shape_add_point(cshape, (sfVector2f){47, 47});
    collide_shape_add_point(cshape, (sfVector2f){1, 47});
    return (cshape);
}

bloc_t *init_bloc_struct(void)
{
    bloc_t *new_bloc = malloc(sizeof(bloc_t));

    new_bloc->sprite = sfSprite_create();
    new_bloc->collide_shape = NULL;
    new_bloc->move_in = 0;
    new_bloc->gravity = 0;
    new_bloc->time_break = 0;
    new_bloc->id = -1;
    new_bloc->plate = 0;
    new_bloc->water_level = 0;
    new_bloc->broken = 0;
    new_bloc->action = 0;
    new_bloc->destruction_level = 0;
    new_bloc->percent = 100;
    new_bloc->move = move_create();
    return (new_bloc);
}

void bloc_create(global_data_t *data, char *name, char *node_name, int id)
{
    bloc_t *bloc = NULL;

    gameobject_create(data, name, node_name, TYPE_BLOC);
    bloc = bloc_get(data, name);
    bloc->gameobject = gameobject_get(data, name);
    bloc->id = id;
    bloc->collide_shape = create_bloc_collision\
(data, bloc->gameobject->name, id);
}