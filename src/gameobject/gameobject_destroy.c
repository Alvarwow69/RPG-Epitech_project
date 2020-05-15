/*
** EPITECH PROJECT, 2019
** gameobject_destroy.c
** File description:
** 
*/

#include <engine/gameobject.h>
#include "rpg.h"

void unload_object(global_data_t *data, game_object_t *game)
{
    switch (game->type) {
    case TYPE_IMAGE:
        if (game->object.sprite != NULL)
            sfSprite_destroy(game->object.sprite);
        break;
    case TYPE_BACKGROUND:
        break;
    case TYPE_BUTTON:
        button_destroy(game->object.button);
        break;
    case TYPE_BLOC:
        bloc_destroy(data, game->object.bloc);
        break;
    case TYPE_MONSTER:
        monster_destroy(data, game->object.monster);
        break;
    case TYPE_TEXT:
        text_destroy(game->object.text);
        break;
    default:
        my_printf("%sgameobject_destroy: can't destroy %s%s%s.%s\n"
        , LRED, PURPLE, game->name, LRED, RESET);
    }
}

void gameobject_destroy(global_data_t *data, char *name)
{
    game_object_t *game = gameobject_get(data, name);
    node_t *node = NULL;

    if (game == NULL) {
        my_printf("%sgameobject_destroy: can't destroy %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    my_printf("%sgameobject_destroy: destroying %s%s%s.%s\n", YELLOW, PURPLE,
    name, YELLOW, RESET);
    node = node_get(data, game->node);
    unload_object(data, game);
    gameobject_remove_from_list(data, node, game);
    free(game->name);
    free(game->node);
    free(game);

}