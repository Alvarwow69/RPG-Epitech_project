/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_destroy.c
*/

#include "rpg.h"

void monster_destroy(global_data_t *gdata, monster_t *monster)
{
    collide_shape_destroy(gdata, monster->body_collision->name);
    collide_shape_destroy(gdata, monster->melee_collision->name);
    collide_shape_destroy(gdata, monster->target_collision->name);
    animation_destroy(monster->anim->attack);
    animation_destroy(monster->anim->die);
    animation_destroy(monster->anim->hit);
    animation_destroy(monster->anim->walk);
    sfSprite_destroy(monster->anim->spr);
    free(monster->anim->txt);
    free(monster->anim);
    free(monster->move->time);
    free(monster->move);
    free(monster->time);
    free(monster);
}