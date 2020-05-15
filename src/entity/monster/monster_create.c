/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_create.c
*/

#include "rpg.h"

void monster_create(global_data_t *gdata, char *name, char *scene_name, monster_id id)
{
    node_t *node = NULL;
    game_object_t *go = NULL;

    node_create(gdata, name, scene_name);
    node_set_layer(gdata, name, 2);
    node = node_get(gdata, name);
    node_set_position(gdata, name, monster_list[id].spawn);

    gameobject_create(gdata, concat_fstring("%s_go", name)
    , name, TYPE_MONSTER);
    go = gameobject_get(gdata, concat_fstring("%s_go", name));
    go->object.monster = monster_init(gdata, name, id);
    sfTransformable_setOrigin(node->transform
    , (sfVector2f){go->object.monster->anim->txt->tile_size.x / 2, 0});
}