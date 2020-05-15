/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** collide_shape_check.c
*/

#include "rpg.h"

void destroy_collide_objects(collide_shape_t *shape)
{
    for (collide_shape_t *tmp = shape; tmp != NULL; tmp = tmp->next)
        for (collide_object_t *obj = tmp->collision_list
        ; obj != NULL; obj = tmp->collision_list) {
            tmp->collision_list = obj->next;
            free(obj);
        }
}

void collide_shape_check_all(global_data_t *gdata)
{
    sfVector2f cshape_pos;
    sfVector2f cshape_origin;
    sfVector2f check_pos;
    sfVector2f check_origin;
    collide_shape_t *first = gdata->objects->cshape_other;

    destroy_collide_objects(first);
    for (collide_shape_t *cshape = first; cshape != NULL; cshape = cshape->next) {
        if (cshape->go->is_active == false || cshape->is_active == false)
            continue;
        cshape_pos = gameobject_get_g_position(gdata, cshape->go);
        cshape_origin = gameobject_get_g_origin(gdata, cshape->go);
        cshape_pos = (sfVector2f){cshape_pos.x - cshape_origin.x, cshape_pos.y - cshape_origin.y};
        for (collide_shape_t *cshape_check = cshape->next; cshape_check != NULL; cshape_check = cshape_check->next) {
            if (cshape_check->go->is_active == false || cshape_check->is_active == false
            || cmp_string(cshape->go->node, cshape_check->go->node) == 0)
                continue;
            check_pos = gameobject_get_g_position(gdata, cshape_check->go);
            check_origin = gameobject_get_g_origin(gdata, cshape_check->go);
            check_pos = (sfVector2f){check_pos.x - check_origin.x, check_pos.y - check_origin.y};
            if (collide_shape_is_collide(cshape, cshape_pos, cshape_check, check_pos))
                create_collide_objects(cshape, cshape_pos, cshape_check, check_pos);
        }
    }
}

node_t *search_update_chunk(node_t *start)
{
    node_t *node = start;

    while (node && !cmp_string(node->scene, start->scene)) {
        if (node->update)
            return (node);
        node = node->next;
    }
    return (NULL);
}

void collide_b_b_check_all(global_data_t *gdata)
{
    sfVector2f cshape_pos;
    sfVector2f cshape_origin;
    sfVector2f check_pos;
    sfVector2f check_origin;
    node_t *first = search_update_chunk(gdata->active_scene->node);
    game_object_t *check = NULL;

    if (!first)
        return;
    for (game_object_t *game = first->gameobjects; game != NULL; game = game->next) {
        if (game->is_active == false || game->type != TYPE_BLOC
            || game->object.bloc->collide_shape->is_active == false || !game->object.bloc->broken)
            continue;
        cshape_pos = gameobject_get_g_position(gdata, game);
        cshape_origin = gameobject_get_g_origin(gdata, game);
        cshape_pos = (sfVector2f){cshape_pos.x - cshape_origin.x, cshape_pos.y - cshape_origin.y};
        check = first->gameobjects;
        for (game_object_t *go_check = check; go_check && !cmp_string(go_check->node, check->node); go_check = go_check->next) {
            if (go_check->is_active == false || go_check->object.bloc->collide_shape->is_active == false
            || go_check->object.bloc->broken)
                continue;
            check_pos = gameobject_get_g_position(gdata, go_check);
            check_origin = gameobject_get_g_origin(gdata, check);
            check_pos = (sfVector2f){check_pos.x - check_origin.x, check_pos.y - check_origin.y};
            if (collide_shape_is_collide(game->object.bloc->collide_shape, cshape_pos, go_check->object.bloc->collide_shape, check_pos))
                create_collide_objects(game->object.bloc->collide_shape, cshape_pos, go_check->object.bloc->collide_shape, check_pos);
        }
    }
}

game_object_t *get_chunk(global_data_t *data, collide_shape_t *shape)
{
    sfVector2f entity_pos = gameobject_get_global_position(data, shape->go->name);
    sfVector2f chunk;
    node_t *node = data->active_scene->node;

    while(node && !cmp_string(node->scene, data->active_scene->name)) {
        if (search_n_occurence(node->name, "map_level", 1) == -1) {
            node = node->next;
            continue;
        }
        chunk = node_get_position(data, node->name);
        if (shape->max.left + entity_pos.x > chunk.x)
            return (node->gameobjects);
        node = node->next;
    }
    return (NULL);
}

void collide_bloc_check_all(global_data_t *gdata)
{
    sfVector2f cshape_pos;
    sfVector2f cshape_origin;
    sfVector2f check_pos;
    sfVector2f check_origin;
    collide_shape_t *first = gdata->objects->cshape_other;
    game_object_t *check = NULL;

    for (collide_shape_t *cshape = first; cshape != NULL; cshape = cshape->next) {
        if (cshape->go->is_active == false || cshape->is_active == false
        || cshape->type != CTYPE_BODY)
            continue;
        cshape_pos = gameobject_get_g_position(gdata, cshape->go);
        cshape_origin = gameobject_get_g_origin(gdata, cshape->go);
        cshape_pos = (sfVector2f){cshape_pos.x - cshape_origin.x, cshape_pos.y - cshape_origin.y};
        check = get_chunk(gdata, cshape);
        for (game_object_t *go_check = check; go_check && !cmp_string(go_check->node, check->node); go_check = go_check->next) {
            if (go_check->is_active == false || go_check->object.bloc->collide_shape->is_active == false)
                continue;
            check_pos = gameobject_get_g_position(gdata, go_check);
            check_origin = gameobject_get_g_origin(gdata, check);
            check_pos = (sfVector2f){check_pos.x - check_origin.x, check_pos.y - check_origin.y};
            if (collide_shape_is_collide(cshape, cshape_pos, go_check->object.bloc->collide_shape, check_pos))
                create_collide_objects(cshape, cshape_pos, go_check->object.bloc->collide_shape, check_pos);
        }
    }
}