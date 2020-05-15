/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** scene_display.c
*/

#include "rpg.h"

void display_scene_info(scene_t *scene)
{
    for (node_t *node = scene->node;
    node != NULL && cmp_string(node->scene, scene->name) == 0;
    node = node->next) {
        my_printf("\tnode => %s :\n", node->name);
        my_printf("\t\tscene : %s\n", node->scene);
        my_printf("\t\tlayer : %i\n", node->layer);
        for (game_object_t *go = node->gameobjects;
        go != NULL && cmp_string(go->node, node->name) == 0;
        go = go->next) {
            my_printf("\t\tgo => %s :\n", go->name);
            my_printf("\t\t\tnode : %s\n", go->node);
        }
    }
}

void scene_display(global_data_t *gdata, char *name)
{
    scene_t *scene = scene_get(gdata, name);

    if (scene == NULL) {
        my_printf("%sscene_display: can't display %s%s%s.%s\n"
        , LRED, PURPLE, name, PURPLE);
        return;
    }
    my_printf("\n%sscene_display: display %s%s%s.%s\n"
    , YELLOW, PURPLE, name, YELLOW, RESET);
    my_printf("scene => %s :\n", scene->name);
    display_scene_info(scene);
    my_printf("%s--------------------%s\n\n", YELLOW, RESET);
}