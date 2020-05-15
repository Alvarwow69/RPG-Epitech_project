/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_move_update.c
*/

#include "rpg.h"

void change_player_move(player_t *player, move move)
{
    animation_reset(player->animation->body_jump);
    animation_reset(player->animation->arms_jump);
    animation_reset(player->animation->legs_jump);
    player->animation->txt->tile_rect.left = 0;
    player->move_status = move;
}

void move_player(global_data_t *gdata, player_t *player, float move)
{
    player->move->vec.x = move;
    node_set_scale(gdata, "player_node", (sfVector2f){SIGN(move), 1});
}

void other_move(global_data_t *gdata, player_t *player)
{
    player->move->vec = (sfVector2f){0, 0};
    if ((gdata->key->rctrl == true || gdata->key->lctrl)
    && (gdata->key->q == true || gdata->key->d == true)) {
        change_player_move(player, M_RUN);
        gdata->key->q == true ?
            move_player(gdata, player, -4) :
            move_player(gdata, player, 4);
    }
    else if ((gdata->key->q == true || gdata->key->d == true)) {
        change_player_move(player, M_WALK);
        gdata->key->q == true ?
            move_player(gdata, player, -1) :
            move_player(gdata, player, 1);
    }
    else if ((gdata->key->lmaj == true || gdata->key->rmaj == true))
        change_player_move(player, M_SNICK);
    else if ((gdata->key->lalt == true || gdata->key->ralt == true))
        change_player_move(player, M_SEET);
    else
        change_player_move(player, M_STAND);
}

void player_move_update(global_data_t *gdata, player_t *player)
{
    if (gdata->key->space == true && player->move_status != M_JUMP) {
        change_player_move(player, M_JUMP);
        player->move->total_time = 0;
        player->move->force = -7;
    } else if (player->move_status != M_JUMP)
        other_move(gdata, player);
    apply_gravity(player->move, gdata->clock);

    for (collide_object_t *cobj = player->body_collision->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_BLOCK)
            continue;
        if (cobj->cshape->go->object.bloc->broken) {
            give_an_item(gdata, player,
            get_number(str_to_tab(cobj->cshape->go->name, "-")[3]) + 14);
            gameobject_destroy(gdata, cobj->cshape->go->name);
        }
        if (cobj->top == true) {
            node_move(gdata, "player_node", cobj->top_offset);
            player->move->force = 0;
        }
        if (cobj->bottom == true) {
            node_move(gdata, "player_node", cobj->bottom_offset);
            player->move->vec.y = (player->move->vec.y > 0 ? 0 : player->move->vec.y);
            player->move->total_time = 0;
            player->move->force = 0;
            if (player->move_status == M_JUMP)
                change_player_move(player, M_STAND);
        }
        if (cobj->left == true)
            node_move(gdata, "player_node", cobj->left_offset);
        if (cobj->right == true)
            node_move(gdata, "player_node", cobj->right_offset);
    }
    node_move(gdata, "player_node", player->move->vec);
}