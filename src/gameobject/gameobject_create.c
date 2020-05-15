/*
** EPITECH PROJECT, 2019
** gameobject_create.c
** File description:
** 
*/

#include <engine/gameobject.h>
#include "rpg.h"

void add_gameobject_node(global_data_t *data, node_t *node, game_object_t *game)
{
    if (node->gameobjects == NULL) {
        game->prev = NULL;
        game->next = data->objects->game_object;
        if (data->objects->game_object != NULL)
            data->objects->game_object->prev = game;
        data->objects->game_object = game;
        node->gameobjects = game;
    } else {
        if (cmp_string(node->gameobjects->name \
, data->objects->game_object->name) == 0)
            data->objects->game_object = game;
        game->prev = node->gameobjects->prev;
        game->next = node->gameobjects;
        if (node->gameobjects->prev != NULL)
            node->gameobjects->prev->next = game;
        node->gameobjects->prev = game;
        node->gameobjects = game;
    }
}

game_object_t *check_gameobject_not_exist(global_data_t *gdata, char *name)
{
    game_object_t *check = gdata->objects->game_object;

    while (check) {
        if (cmp_string(check->name, name) == 0) {
            my_printf("%sgameobject_create: %s%s%s gameObject already exist!\n",
            LRED, PURPLE, name, LRED, RESET);
            return (check);
        }
        check = check->next;
    }
    return (NULL);
}

static void define_gameobject_value(global_data_t *data,
game_object_t *game_obj, char *name)
{
    game_obj->name = string_dup(name);
    game_obj->is_draw = true;
    game_obj->is_active = true;
    game_obj->layer = 1;
    game_obj->tags = (tag[]) {TAG_END};
    game_obj->transform = sfTransformable_create();
    define_type(data, game_obj);
}

void gameobject_create(global_data_t *data, char *name, char *name_node,
gameobject_type type)
{
    node_t *node = node_get(data, name_node);
    game_object_t *check = check_gameobject_not_exist(data, name);
    game_object_t *game_obj = NULL;

    if (node == NULL || check != NULL) {
        my_printf("%sgameobject_create: can't create %s%s%s.%s\n", LRED, PURPLE,
        name, LRED, RESET);
        return;
    }
    game_obj = malloc(sizeof(game_object_t));
    if (game_obj == NULL) {
        my_printf("%sgameobject_create: can't create %s%s%s.%s\n", LRED, PURPLE,
        name, LRED, RESET);
        return;
    }
    my_printf("%sgameobject_create: create %s%s%s gameobject.%s\n", YELLOW,
    PURPLE, name, YELLOW, RESET);
    game_obj->node = string_dup(name_node);
    game_obj->type = type;
    add_gameobject_node(data, node, game_obj);
    define_gameobject_value(data, game_obj, name);
}