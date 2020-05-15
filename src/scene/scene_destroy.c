/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** scene_destroy.c
*/

#include "rpg.h"

void scene_remove_from_list(global_data_t *gdata, scene_t *scene)
{
    scene_t *tmp = scene->next;
    scene_t *tmp_prev = scene->prev;

    if (cmp_string(gdata->objects->scene->name, scene->name) == 0) {
        if (gdata->objects->scene->next != NULL)
            gdata->objects->scene = gdata->objects->scene->next;
        else
            gdata->objects->scene = NULL;
    }
    if (scene->prev != NULL)
        scene->prev->next = tmp;
    if (scene->next != NULL)
        scene->next->prev = tmp_prev;
}

void scene_destroy(global_data_t *gdata, char *name)
{
    scene_t *scene = scene_get(gdata, name);

    if (scene == NULL) {
        my_printf("%sscene_destroy: can't destroy %s%s%s.%s\n"
        , LRED, PURPLE, name, LRED, RESET);
        return;
    }
    my_printf("%sscene_destroy: destroy %s%s%s.%s\n"
    , YELLOW, PURPLE, name, YELLOW, RESET);
    for (node_t *node = scene->node;
    node != NULL && cmp_string(node->scene, scene->name) == 0;
    node = scene->node)
        node_destroy(gdata, node->name);
    scene_remove_from_list(gdata, scene);
    free(scene->name);
    sfView_destroy(scene->game);
    sfView_destroy(scene->interface);
    free(scene);
}