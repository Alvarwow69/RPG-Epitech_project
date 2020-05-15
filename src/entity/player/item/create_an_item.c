/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** create_an_item.c
*/

#include "rpg.h"

consumable_t *create_consumable(global_data_t *gdata, cons_id id)
{
    consumable_t *new = malloc(sizeof(consumable_t));

    (void)gdata;
    new->id = id;
    new->type = consumable[id].type;
    new->vitality_regen = consumable[id].vitality_regen;
    new->satiety_regen = consumable[id].satiety_regen;
    return (new);
}

weapon_t *create_weapon(global_data_t *gdata, weapon_id id)
{
    weapon_t *new = malloc(sizeof(weapon_t));
    sfTexture **textures = gdata->ressources->textures;
    anim_ref_t ref = weapon[id].anim_ref; 

    new->id = id;
    new->type = weapon[id].type;
    new->txt = texture_create(textures[weapon[id].txt_id], false
    , (sfVector2f){1, 1}, weapon[id].tile_rect);
    new->anim = animation_create(new->txt, ref.anim_time
    , ref.loop_time, (sfVector2i){ref.rect_pos, ref.rect_max});
    new->spr = sfSprite_create();
    sfSprite_setTexture(new->spr, textures[weapon[id].txt_id], sfTrue);
    sfSprite_setTextureRect(new->spr, weapon[id].tile_rect);

    if (id == WEAPON_SWORD) {
        new->cshape = collide_shape_create(gdata, "Sword", "player_go", CTYPE_M_FIGHT);
        collide_shape_add_point(new->cshape, (sfVector2f){100, 20});
        collide_shape_add_point(new->cshape, (sfVector2f){200, 20});
        collide_shape_add_point(new->cshape, (sfVector2f){200, 120});
        collide_shape_add_point(new->cshape, (sfVector2f){100, 120});
        collide_shape_add_point(new->cshape, (sfVector2f){100, 20});
        new->cshape->is_active = false;
    }
    else if (id == WEAPON_PICKAXE) {
        new->cshape = collide_shape_create(gdata, "Pickaxe", "player_go", CTYPE_INTERACT);
        collide_shape_add_point(new->cshape, (sfVector2f){-50, -50});
        collide_shape_add_point(new->cshape, (sfVector2f){179, -50});
        collide_shape_add_point(new->cshape, (sfVector2f){179, 179});
        collide_shape_add_point(new->cshape, (sfVector2f){-50, 179});
        collide_shape_add_point(new->cshape, (sfVector2f){-50, -50});
        //new->cshape->is_active = false;
    }
    return (new);
}

item_t *create_item(global_data_t *gdata, item_id id)
{
    item_t *item = malloc(sizeof(item_t));

    item->name = string_dup(item_list[id].name);
    item->id = id;
    item->type = item_list[id].type;
    item->number = 0;
    if (id != IID_NO_ITEM && id != IID_NO_CHEST
    && id != IID_NO_PANTS && id != IID_NO_HELM
    && id != IID_NO_RING)
        item->number = 1;
    item->go_inv = NULL;
    item->go_act = NULL;
    item->stats = init_stats();
    item->wearable = NULL;
    item->consumable = NULL;
    if (item->type == IT_WEARABLE)
        item->wearable = create_weapon(gdata, item_list[id].wear_id);
    else if (item->type == IT_CONSUMABLE)
        item->consumable = create_consumable(gdata, item_list[id].cons_id);
    return (item);
}