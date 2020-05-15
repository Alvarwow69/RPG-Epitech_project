/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_update.c
*/

#include "rpg.h"

move monster_choose_move(void)
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

int monster_choose_direction(void)
{
    int random = rand() % 2;

    if (random == 0)
        return (1);
    return (-1);
}

void monster_change_move(global_data_t *gdata, char *name, monster_t *monster)
{
    monster->direction = monster_choose_direction();
    monster->time->dif = (rand() % 3) - 1;
    monster->anim->txt->tile_rect.left = 0;
    if (monster->is_pause == true) {
        monster->move_status = M_STAND;
        monster->is_pause = false;
    } else {
        monster->move_status = monster_choose_move();
        node_set_scale(gdata, name, (sfVector2f){-monster->direction, 1});
        monster->is_pause = true;
    }
}

void monster_move(global_data_t *gdata, monster_t *monster)
{
    switch (monster->move_status) {
        case M_WALK:
            monster->move->vec.x = 1;
            texture_time_gestion(monster->anim->walk, gdata->clock, monster->anim->txt);
            break;
        case M_RUN:
            monster->move->vec.x = 2.5;
            texture_time_gestion(monster->anim->walk, gdata->clock, monster->anim->txt);
            break;
        default:
            break;
    }
    sfSprite_setTextureRect(monster->anim->spr, monster->anim->txt->tile_rect);
}

void monster_check_melee(global_data_t *gdata, char *name, monster_t *monster)
{
    if (monster->action_status != MSTA_FOLLOW)
        return;
    for (collide_object_t *cobj = monster->melee_collision->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_BODY || cobj->cshape->go->type != TYPE_PLAYER)
            continue;
        if (cobj->left == true) {
            monster->direction = -1;
            if (cobj->left_offset.x > 0)
                monster->move->vec.x = 0.5;
        } else if (cobj->right == true) {
            monster->direction = 1;
            if (cobj->right_offset.x > 0)
                monster->move->vec.x = 0.5;
        }
        if (monster->anim->attack->is_anim == true)
            play_sound_wait(gdata, SOUND_MONSTER_ATTACK);
        node_set_scale(gdata, name, (sfVector2f){-monster->direction, 1});
        monster->move_status = M_STAND;
        monster->anim->txt->tile_rect.left = 0;
        monster->action_status = MSTA_ATTACK;
    }
}

void monster_check_target(global_data_t *gdata, char *name, monster_t *monster)
{
    if (monster->action_status == MSTA_FOLLOW) {
        monster->action_status = MSTA_NONE;
        monster->time->dif = monster->move_loop;
        monster->is_pause = true;
    }
    for (collide_object_t *cobj = monster->target_collision->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_BODY || cobj->cshape->go->type != TYPE_PLAYER)
            continue;
        if (cobj->left == true)
            monster->direction = -1;
        else if (cobj->right == true)
            monster->direction = 1;
        node_set_scale(gdata, name, (sfVector2f){-monster->direction, 1});
        monster->anim->txt->tile_rect.left = 0;
        monster->move_status = M_RUN;
        monster->action_status = MSTA_FOLLOW;
    }
}

void monster_check_body(global_data_t *gdata, char *name, monster_t *monster)
{
    for (collide_object_t *cobj = monster->body_collision->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_BLOCK)
            continue;
        if (cobj->top == true) {
            node_move(gdata, name, cobj->top_offset);
            monster->move->force = 0;
        }
        if (cobj->bottom == true) {
            node_move(gdata, name, cobj->bottom_offset);
            monster->move->vec.y = (monster->move->vec.y > 0 ? 0 : monster->move->vec.y);
            monster->move->total_time = 0;
            monster->move->force = 0;
            if (monster->move_status == M_JUMP)
                monster->move_status = M_STAND;
        }
        if (cobj->left == true) {
            node_move(gdata, name, cobj->left_offset);
            monster->move->force = -4.5;
        }
        if (cobj->right == true) {
            node_move(gdata, name, cobj->right_offset);
            monster->move->force = -4.5;
        }
    }
}

void monster_update(global_data_t *gdata, char *name)
{
    monster_t *monster = gameobject_get(gdata, concat_fstring("%s_go", name))->object.monster;

    monster->time->last = monster->time->actual;
    monster->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(gdata->clock));
    monster->time->dif += monster->time->actual - monster->time->last;
    apply_gravity(monster->move, gdata->clock);
    monster_check_melee(gdata, name, monster);

    switch (monster->action_status) {
        case MSTA_NONE:
            if (monster->time->dif >= monster->move_loop)
                monster_change_move(gdata, name, monster);
            else
                monster_move(gdata, monster);
            monster_check_target(gdata, name, monster);
            break;
        case MSTA_FOLLOW:
            monster_move(gdata, monster);
            monster_check_target(gdata, name, monster);
            break;
        case MSTA_ATTACK:
            texture_time_gestion(monster->anim->attack, gdata->clock, monster->anim->txt);
            sfIntRect tmp = add_recti_vectori(monster->anim->txt->tile_rect, monster_list[monster->id].attack_offset);
            sfSprite_setTextureRect(monster->anim->spr, tmp);
            monster_check_target(gdata, name, monster);
            break;
        case MSTA_DIE:
            texture_time_gestion(monster->anim->die, gdata->clock, monster->anim->txt);
            sfIntRect tmp2 = add_recti_vectori(monster->anim->txt->tile_rect, monster_list[monster->id].die_offset);
            sfSprite_setTextureRect(monster->anim->spr, tmp2);
            if (monster->anim->die->is_anim == false) {
                node_destroy(gdata, name);
                return;
            }
            break;
        case MSTA_HIT:
            texture_time_gestion(monster->anim->hit, gdata->clock, monster->anim->txt);
            sfIntRect tmp3 = add_recti_vectori(monster->anim->txt->tile_rect, monster_list[monster->id].hit_offset);
            sfSprite_setTextureRect(monster->anim->spr, tmp3);
            if (monster->anim->hit->is_anim == false) {
                animation_reset(monster->anim->hit);
                monster->action_status = MSTA_NONE;
            }
            break;
        default:
            break;
    }
    monster->move->vec.x *= monster->direction;
    monster_check_body(gdata, name, monster);
    node_move(gdata, name, monster->move->vec);
    monster->move->vec = (sfVector2f){0, 0};

    if (monster->hp <= 0) {
        play_sound_wait(gdata, SOUND_MONSTER_DISP);
        monster->action_status = MSTA_DIE;
    }
}