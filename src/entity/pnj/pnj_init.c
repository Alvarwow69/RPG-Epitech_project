/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** init_pnj.c
*/

#include "rpg.h"

pnj_animation_t *init_pnj_animation(pnj_t *pnj, sfTexture **textures)
{
    pnj_animation_t *anim = malloc(sizeof(pnj_animation_t));

    if (anim == NULL)
        return (my_printf("%s%sCan't create the player animations.%s\n"
        , LRED, BLINK, RESET), NULL);
    anim->txt = texture_create(
        textures[TEXTURE_BARE_CHARACTER], false, (sfVector2f){1, 1}
        , (sfIntRect){0, 0, 129, 129});
    anim->head_spr = armor_create(textures, AT_HELM, (armor_id){pnj->helm_id});
    anim->body_spr = armor_create(textures, AT_CHEST, (armor_id){pnj->chest_id});
    anim->arms_spr = armor_create(textures, AT_ARMS, (armor_id){pnj->arms_id});
    anim->legs_spr = armor_create(textures, AT_PANTS, (armor_id){pnj->pants_id});
    anim->arms_walk = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    anim->arms_run = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    anim->body_walk = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    anim->body_run = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    anim->legs_walk = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    anim->legs_run = animation_create(anim->txt, 0.1, 0, (sfVector2i){129, 903});
    return (anim);
}

collide_shape_t *create_pnj_talk_collision(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_create(gdata, concat_fstring("%s_talk_collision", name), concat_fstring("%s_go", name), CTYPE_INTERACT);

    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    collide_shape_add_point(cshape, (sfVector2f){129, 0});
    collide_shape_add_point(cshape, (sfVector2f){129, 129});
    collide_shape_add_point(cshape, (sfVector2f){0, 129});
    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    return (cshape);
}

collide_shape_t *create_pnj_body_collision(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_create(gdata, concat_fstring("%s_body_collision", name), concat_fstring("%s_go", name), CTYPE_BODY);

    collide_shape_add_point(cshape, (sfVector2f){30, 40});
    collide_shape_add_point(cshape, (sfVector2f){100, 40});
    collide_shape_add_point(cshape, (sfVector2f){100, 125});
    collide_shape_add_point(cshape, (sfVector2f){30, 125});
    collide_shape_add_point(cshape, (sfVector2f){30, 40});
    return (cshape);
}

pnj_t *pnj_init(global_data_t *gdata, char *name, pnj_id id)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    pnj->id = id;
    pnj->helm_id = pnj_list[id].helm_id;
    pnj->chest_id = pnj_list[id].chest_id;
    pnj->arms_id = pnj_list[id].arms_id;
    pnj->pants_id = pnj_list[id].pants_id;
    pnj->action_status = PNJA_NONE;
    pnj->move_status = M_STAND;
    pnj->anim = init_pnj_animation(pnj, gdata->ressources->textures);
    pnj->time = game_time_create();
    pnj->talk_collision = create_pnj_talk_collision(gdata, name);
    pnj->body_collision = create_pnj_body_collision(gdata, name);
    pnj->move_loop = pnj_list[id].move_loop;
    pnj->max_left = pnj_list[id].max_left;
    pnj->max_right = pnj_list[id].max_right;
    pnj->is_pause = true;
    pnj->direction = 1;
    pnj->move = move_create();
    return (pnj);
}