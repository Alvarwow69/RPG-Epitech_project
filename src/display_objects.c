/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** display_objects.c
*/

#include "rpg.h"

void display_objects(global_data_t *gdata)
{
    my_printf("\n%sDisplay all objects :%s\n", YELLOW, RESET);
    my_printf("scene:\n");
    for (scene_t *scene = gdata->objects->scene; \
scene != NULL; scene = scene->next)
        my_printf("\t%s\n", scene->name);
    my_printf("node:\n");
    for (node_t *node = gdata->objects->node; \
node != NULL; node = node->next)
        my_printf("\t%s\n", node->name);
    my_printf("gameobject:\n");
    for (game_object_t *go = gdata->objects->game_object; \
go != NULL; go = go->next)
        my_printf("\t%s\n", go->name);
    my_printf("%s--------------------%s\n\n", YELLOW, RESET);
}