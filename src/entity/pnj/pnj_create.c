/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** pnj_create.c
*/

#include "rpg.h"

void pnj_create(global_data_t *gdata, char *name, char *scene_name, pnj_id id)
{
    node_t *node = NULL;
    game_object_t *go = NULL;

    node_create(gdata, name, scene_name);
    node_set_layer(gdata, name, 2);
    node = node_get(gdata, name);
    sfTransformable_setOrigin(node->transform, (sfVector2f){64.5, 0});
    node_set_position(gdata, name, pnj_list[id].pos);
    gameobject_create(gdata, concat_fstring("%s_go", name), name, TYPE_PNJ);
    go = gameobject_get(gdata, concat_fstring("%s_go", name));
    go->object.pnj = pnj_init(gdata, name, id);
}