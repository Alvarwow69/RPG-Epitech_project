/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_player_struct
*/

#include "rpg.h"

stats_t *init_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    if (stats == NULL)
        return (my_printf("%s%sCan't create the player stats.%s\n"
        , LRED, BLINK, RESET), NULL);
    stats->vit = 0;
    stats->mstr = 0;
    stats->rstr = 0;
    stats->mdef = 0;
    stats->rdef = 0;
    stats->acc = 0;
    stats->luck = 0;
    stats->dext = 0;
    stats->cel = 0;
    return (stats);
}

inventory_t *init_inventory_struct(global_data_t *gdata)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL)
        return (my_printf("%s%sCan't create the player inventory.%s\n"
        , LRED, BLINK, RESET), NULL);
    inventory->items = malloc(sizeof(item_t *) * SLOT_COUNT);
    inventory->items[SLOT_HELM] = create_item(gdata, IID_ARMOR1_HELM);
    inventory->items[SLOT_CHEST] = create_item(gdata, IID_ARMOR1_CHEST);
    inventory->items[SLOT_PANTS] = create_item(gdata, IID_ARMOR1_PANTS);
    inventory->items[SLOT_RING1] = create_item(gdata, IID_NO_RING);
    inventory->items[SLOT_RING2] = create_item(gdata, IID_NO_RING);
    inventory->items[SLOT_ACTIVE[0]] = create_item(gdata, IID_SWORD);
    inventory->items[SLOT_ACTIVE[1]] = create_item(gdata, IID_PICKAXE);
    for (int ctr = SLOT_ACTIVE[2]; ctr < SLOT_COUNT; ctr += 1)
        inventory->items[ctr] = create_item(gdata, IID_NO_ITEM);
    inventory->pick = create_item(gdata, IID_NO_ITEM);
    inventory->wear = inventory->items[SLOT_ACTIVE[0]];
    return (inventory);
}

player_animation_t *init_player_animation(global_data_t *gdata, ressources_t *ressources)
{
    player_animation_t *animation = malloc(sizeof(player_animation_t));

    if (animation == NULL)
        return (my_printf("%s%sCan't create the player animations.%s\n"
        , LRED, BLINK, RESET), NULL);
    animation->txt = texture_create(
        ressources->textures[TEXTURE_BARE_CHARACTER], false, (sfVector2f){1, 1}
        , (sfIntRect){0, 0, 129, 129});
    animation->txt_attack = texture_create(
        ressources->textures[TEXTURE_BARE_CHARACTER], false, (sfVector2f){1, 1}
        , (sfIntRect){0, 0, 129, 129});
    animation->head_spr = armor_create(gdata->ressources->textures, AT_HELM, (armor_id){HELM_BARE1});
    animation->body_spr = armor_create(gdata->ressources->textures, AT_CHEST, (armor_id){CHEST_BARE});
    animation->arms_spr = armor_create(gdata->ressources->textures, AT_ARMS, (armor_id){ARMS_BARE});
    animation->legs_spr = armor_create(gdata->ressources->textures, AT_PANTS, (armor_id){PANTS_BARE});
    animation->arms_walk = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->arms_run = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->arms_jump = animation_create(animation->txt, 0.1, -1, (sfVector2i){129, 1290});
    animation->arms_swip = animation_create(animation->txt_attack, 0.07, -1, (sfVector2i){0, 774});
    animation->arms_pickaxe = animation_create(animation->txt_attack, 0.2, -1, (sfVector2i){0, 387});
    animation->body_walk = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->body_run = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->body_jump = animation_create(animation->txt, 0.1, -1, (sfVector2i){129, 1290});
    animation->legs_walk = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->legs_run = animation_create(animation->txt, 0.1, 0, (sfVector2i){129, 903});
    animation->legs_jump = animation_create(animation->txt, 0.1, -1, (sfVector2i){129, 1290});
    return (animation);
}

collide_shape_t *create_talk_collision(global_data_t *gdata)
{
    collide_shape_t *cshape = collide_shape_create(gdata, "p_talk_collision", "player_go", CTYPE_INTERACT);

    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    collide_shape_add_point(cshape, (sfVector2f){129, 0});
    collide_shape_add_point(cshape, (sfVector2f){129, 129});
    collide_shape_add_point(cshape, (sfVector2f){0, 129});
    collide_shape_add_point(cshape, (sfVector2f){0, 0});
    return (cshape);
}

collide_shape_t *create_body_collision(global_data_t *gdata)
{
    collide_shape_t *cshape = collide_shape_create(gdata, "p_body_collision", "player_go", CTYPE_BODY);

    collide_shape_add_point(cshape, (sfVector2f){50, 40});
    collide_shape_add_point(cshape, (sfVector2f){80, 40});
    collide_shape_add_point(cshape, (sfVector2f){80, 125});
    collide_shape_add_point(cshape, (sfVector2f){50, 125});
    collide_shape_add_point(cshape, (sfVector2f){50, 40});
    return (cshape);
}

properties_t *init_player_properties(void)
{
    properties_t *prop = malloc(sizeof(properties_t));

    prop->hp = (value_t){500, 500};
    prop->xp = (value_t){0, 100};
    prop->satiety = (value_t){80, 120};
    prop->money = 150;

    prop->strenght = 10;
    prop->defense = 10;
    prop->accuracy = 0;
    prop->luck = 0;
    prop->dexterity = 1;
    prop->celerity = 1;
    prop->time = game_time_create();
    prop->avl_point = 1;
    return (prop);
}

player_t *init_player(global_data_t *gdata)
{
    player_t *player = malloc(sizeof(player_t));

    player->action_status = PA_NONE;
    player->move_status = M_STAND;

    player->stats = init_stats();
    player->prop = init_player_properties();
    player->inventory = init_inventory_struct(gdata);
    player->animation = init_player_animation(gdata, gdata->ressources);
    player->move = move_create();
    player->talk_collision = create_talk_collision(gdata);
    player->body_collision = create_body_collision(gdata);
    player->save = malloc(sizeof(save_t));
    player->save->tab_id_item = malloc(sizeof(item_id) * (31));
    player->save->nbr_item = malloc(sizeof(int) & (31));
    player->save->value = malloc(sizeof(value_t) * (3));
    player->save->properties = malloc(sizeof(int) * (8));

    return (player);
}