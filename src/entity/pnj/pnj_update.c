/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** pnj_update.c
*/

#include "pnj.h"

move pnj_choose_move(void)
{
    int random = rand() % 5;

    switch (random) {
        case 0:
            return (M_STAND);
        case 1:
        case 2:
        case 3:
            return (M_WALK);
        case 4:
            return (M_RUN);
    }
    return (M_STAND);
}

int pnj_choose_direction(void)
{
    int random = rand() % 2;

    if (random == 0)
        return (1);
    return (-1);
}

void change_pnj_move(global_data_t *gdata, pnj_t *pnj, char *name)
{
    pnj->direction = pnj_choose_direction();
    pnj->time->dif = (rand() % 3) - 1;
    pnj->anim->txt->tile_rect.left = 0;
    if (pnj->is_pause == true) {
        pnj->move_status = M_STAND;
        pnj->is_pause = false;
    } else {
        pnj->move_status = pnj_choose_move();
        node_set_scale(gdata, name, (sfVector2f){pnj->direction, 1});
        pnj->is_pause = true;
    }
}

void pnj_move(global_data_t *gdata, pnj_t *pnj, char *name)
{
    sfVector2f pos = gameobject_get_global_position(gdata, concat_fstring("%s_go", name));

    pnj_animation_update(gdata, pnj);
    if (pos.x + pnj->direction > pnj->max_right || pos.x + pnj->direction < pnj->max_left) {
        pnj->direction *= -1;
        node_set_scale(gdata, name, (sfVector2f){pnj->direction, 1});
    }
    if (pnj->move_status == M_WALK)
        pnj->move->vec.x = 1;
    else if (pnj->move_status == M_RUN)
        pnj->move->vec.x = 2.5;
}

void pnj_check_body(global_data_t *gdata, char *name, pnj_t *pnj)
{
    for (collide_object_t *cobj = pnj->body_collision->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_BLOCK)
            continue;
        if (cobj->top == true) {
            node_move(gdata, name, cobj->top_offset);
            pnj->move->force = 0;
        }
        if (cobj->bottom == true) {
            node_move(gdata, name, cobj->bottom_offset);
            pnj->move->vec.y = (pnj->move->vec.y > 0 ? 0 : pnj->move->vec.y);
            pnj->move->total_time = 0;
            pnj->move->force = 0;
            if (pnj->move_status == M_JUMP)
                pnj->move_status = M_STAND;
        }
        if (cobj->left == true) {
            node_move(gdata, name, cobj->left_offset);
            pnj->move->force = -4.5;
        }
        if (cobj->right == true) {
            node_move(gdata, name, cobj->right_offset);
            pnj->move->force = -4.5;
        }
    }
}

void pnj_update(global_data_t *gdata, char *name)
{
    pnj_t *pnj = gameobject_get(gdata, concat_fstring("%s_go", name))->object.pnj;

    pnj->time->last = pnj->time->actual;
    pnj->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(gdata->clock));
    pnj->time->dif += pnj->time->actual - pnj->time->last;

    apply_gravity(pnj->move, gdata->clock);
    switch (pnj->action_status) {
        case PNJA_NONE:
            if (pnj->time->dif >= pnj->move_loop)
                change_pnj_move(gdata, pnj, name);
            else
                pnj_move(gdata, pnj, name);
            break;
        case PNJA_TALK:
            break;
    }
    pnj->move->vec.x *= pnj->direction;
    pnj_check_body(gdata, name, pnj);
    node_move(gdata, name, pnj->move->vec);
    pnj->move->vec = (sfVector2f){0, 0};
}