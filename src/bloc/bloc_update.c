/*
** EPITECH PROJECT, 2020
** bloc_update.c
** File description:
** 
*/

#include "rpg.h"

void give_block(global_data_t *data, game_object_t *game)
{
    if (!game->object.bloc->action && game->object.bloc->destruction_level > 0)
        game->object.bloc->destruction_level = 0;
    game->object.bloc->action = 0;
    apply_gravity(game->object.bloc->move, data->clock);
    if (game->type != TYPE_BLOC || !game->object.bloc->gravity)
        return;
    gameobject_move(data, game->name, game->object.bloc->move->vec);
}

void apply_collision(collide_object_t *c_obj)
{
    if (c_obj->cshape->go->type == TYPE_BLOC) {
        if (c_obj->left || c_obj->right)
            c_obj->cshape->go->object.bloc->move->vec.x = 0;
        c_obj->cshape->go->object.bloc->move->total_time = 0;
        c_obj->cshape->go->object.bloc->move->force < 0 ? \
c_obj->cshape->go->object.bloc->move->force += 1 : 0;
        if (c_obj->cshape->go->object.bloc->move->force == 0) {
            c_obj->cshape->go->object.bloc->gravity = 0;
        }
    }
}

void check_collider(bloc_t *bloc)
{
    collide_object_t *c_obj = bloc->collide_shape->collision_list;

    if (bloc->broken) {
        if (!c_obj)
            bloc->gravity = 1;
        return;
    }
    while (c_obj) {
        if (c_obj->cshape->type == CTYPE_BLOCK) {
            apply_collision(c_obj);
        }
        c_obj = c_obj->next;
    }
}

void update_block(global_data_t *data, scene_t *scene)
{
    char *node_name = get_first_node_map(scene);
    node_t *node = node_get(data, node_name);
    game_object_t *bloc = node->gameobjects;

    while (bloc && search_n_occurence(bloc->node, "map_", 1) != -1) {
        give_block(data, bloc);
        check_collider(bloc->object.bloc);
        bloc = bloc->next;
    }
}