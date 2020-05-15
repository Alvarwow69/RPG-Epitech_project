/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** monster_init.c
*/

#include "rpg.h"

collide_shape_t *monster_create_body_collision(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_create(gdata, concat_fstring("%s_body_collision", name), concat_fstring("%s_go", name), CTYPE_BODY);

    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    collide_shape_add_point(cshape, (sfVector2f){72, 0});
    collide_shape_add_point(cshape, (sfVector2f){72, 60});
    collide_shape_add_point(cshape, (sfVector2f){0, 60});
    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    return (cshape);
}

collide_shape_t *monster_create_target_collision(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_create(gdata, concat_fstring("%s_target_collision", name), concat_fstring("%s_go", name), CTYPE_TARGET);

    collide_shape_add_point(cshape, (sfVector2f){-100, -100});
    collide_shape_add_point(cshape, (sfVector2f){172, -100});
    collide_shape_add_point(cshape, (sfVector2f){172, 172});
    collide_shape_add_point(cshape, (sfVector2f){-100, 172});
    collide_shape_add_point(cshape, (sfVector2f){-100, -100});
    return (cshape);
}

collide_shape_t *monster_create_melee_collision(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_create(gdata, concat_fstring("%s_melee_collision", name), concat_fstring("%s_go", name), CTYPE_M_FIGHT);

    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    collide_shape_add_point(cshape, (sfVector2f){72, 0});
    collide_shape_add_point(cshape, (sfVector2f){72, 72});
    collide_shape_add_point(cshape, (sfVector2f){0, 72});
    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    return (cshape);
}

monster_animation_t *monster_init_animation(sfTexture **textures, monster_id id)
{
    monster_animation_t *anim = malloc(sizeof(monster_animation_t));
    monster_prefab_t ref = monster_list[id];

    anim->txt = texture_create(textures[ref.txt_id], false, (sfVector2f){1, 1}, ref.tile_rect);
    anim->spr = sfSprite_create();
    sfSprite_setTexture(anim->spr, textures[ref.txt_id], sfTrue);
    sfSprite_setTextureRect(anim->spr, anim->txt->tile_rect);
    anim->walk = animation_create(anim->txt, ref.walk.anim_time, ref.walk.loop_time, (sfVector2i){ref.walk.rect_pos, ref.walk.rect_max});
    anim->attack = animation_create(anim->txt, ref.attack.anim_time, ref.attack.loop_time, (sfVector2i){ref.attack.rect_pos, ref.attack.rect_max});
    anim->hit = animation_create(anim->txt, ref.hit.anim_time, ref.hit.loop_time, (sfVector2i){ref.hit.rect_pos, ref.hit.rect_max});
    anim->die = animation_create(anim->txt, ref.die.anim_time, ref.die.loop_time, (sfVector2i){ref.die.rect_pos, ref.die.rect_max});
    return (anim);
}

monster_t *monster_init(global_data_t *gdata, char *name, monster_id id)
{
    monster_t *monster = malloc(sizeof(monster_t));

    monster->id = id;
    monster->action_status = MSTA_NONE;
    monster->move_status = M_STAND;
    monster->anim = monster_init_animation(gdata->ressources->textures, id);
    monster->move = move_create();
    monster->target_collision = monster_create_target_collision(gdata, name);
    monster->melee_collision = monster_create_melee_collision(gdata, name);
    monster->body_collision = monster_create_body_collision(gdata, name);
    monster->time = game_time_create();
    monster->move_loop = monster_list[id].move_loop;
    monster->is_pause = true;
    monster->direction = 1;
    monster->hp = 50;
    return (monster);
}