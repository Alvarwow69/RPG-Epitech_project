/*
** EPITECH PROJECT, 2020
** gameobject_get.c
** File description:
** 
*/

#include "rpg.h"

game_object_t *gameobject_get(global_data_t *data, char *name)
{
    game_object_t *gameobject = data->objects->game_object;

    while (gameobject) {
        if (cmp_string(name, gameobject->name) == 0)
            return (gameobject);
        gameobject = gameobject->next;
    }
    my_printf("%sgameobject_get: %s%s%s gameObject not found !%s\n"
    , LRED, PURPLE, name, LRED, RESET);
    return (NULL);
}

game_object_t **gameobject_get_tag(global_data_t *gdata, tag search)
{
    static game_object_t **adress = NULL;
    game_object_t **go_tab = NULL;
    int go_ctr = 0;

    adress != NULL ? (free(adress), 0) : 0;
    for (game_object_t *go = gdata->objects->game_object; go; go = go->next)
        for (int ctr = 0; go->tags[ctr] != TAG_END; ctr += 1)
            go->tags[ctr] == search ? go_ctr += 1 : 0;
    go_tab = malloc(sizeof(game_object_t *) * (go_ctr + 1));
    go_tab[go_ctr] = NULL;
    go_ctr = 0;
    for (game_object_t *go = gdata->objects->game_object; go; go = go->next)
        for (int ctr = 0; go->tags[ctr] != TAG_END; ctr += 1)
            go->tags[ctr] == search ? (go_tab[go_ctr] = go, go_ctr += 1) : 0;
    return (adress = go_tab, go_tab);
}

game_object_t **gameobject_get_type(global_data_t *gdata,
gameobject_type type_search)
{
    static game_object_t **adress = NULL;
    game_object_t **go_tab = NULL;
    int go_ctr = 0;

    adress != NULL ? (free(adress), 0) : 0;
    for (game_object_t *go = gdata->objects->game_object; go; go = go->next)
        go->type == type_search ? go_ctr += 1 : 0;
    go_tab = malloc(sizeof(game_object_t *) * (go_ctr + 1));
    go_tab[go_ctr] = NULL;
    go_ctr = 0;
    for (game_object_t *go = gdata->objects->game_object; go; go = go->next)
        go->type == type_search ? (go_tab[go_ctr] = go, go_ctr += 1) : 0;
    return (adress = go_tab, go_tab);
}