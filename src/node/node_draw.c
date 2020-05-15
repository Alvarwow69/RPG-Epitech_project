/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** node_draw.c
*/

#include "rpg.h"

void node_draw(global_data_t *data, node_t *node)
{
    sfVector2f node_pos = node_get_position(data, node->name);
    sfVector2f cam_pos = sfView_getCenter(scene_get(data, node->scene)->game);

    if (node->is_draw == false || node->is_active == false \
|| (node_pos.x < cam_pos.x - 1000 && node_pos.x > cam_pos.x + 1000 \
&& search_n_occurence(node->name, "map_", 1) != -1))
        return;
    for (game_object_t *tmp = node->gameobjects; \
tmp != NULL && cmp_string(tmp->node, node->name) == 0; \
tmp = tmp->next)
        gameobject_draw(data, tmp, node);
}