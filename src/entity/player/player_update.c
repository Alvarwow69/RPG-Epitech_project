/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** player_update.c
*/

#include "rpg.h"

void check_interact(global_data_t *data, player_t *player)
{
    for (collide_object_t *cobj = player->talk_collision->collision_list;
         cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_INTERACT)
            continue;
        if (cobj->cshape->go->type == TYPE_BLOC &&
        cobj->cshape->go->object.bloc->id == TM_SING
        && get_controls_event(data, "Interact"))
            scene_draw(data, "travel", true, false);
    }
}

void update_weapon_sword(global_data_t *gdata, player_t *player, weapon_t *weapon)
{
    static bool have_attack = false;

    if (get_controls_event(gdata, "Attaque")) {
        animation_reset(player->animation->arms_swip);
        animation_reset(player->inventory->wear->wearable->anim);
        player->inventory->wear->wearable->cshape->is_active = true;
        play_sound_reset(gdata, SOUND_ATTACK_SWORD);
    }
    if (weapon->anim->is_anim == false) {
        weapon->cshape->is_active = false;
        have_attack = false;
    }
    else if (have_attack == false) {
        for (collide_object_t *cobj = weapon->cshape->collision_list; cobj != NULL; cobj = cobj->next) {
            if (cobj->cshape->type != CTYPE_BODY)
                continue;
            if (cobj->cshape->go->type == TYPE_MONSTER && cobj->cshape->go->object.monster->hp > 0) {
                cobj->cshape->go->object.monster->hp -= 10;
                if (cobj->cshape->go->object.monster->hp == 0)
                    verif_quest(gdata, cobj);
                have_attack = true;
                cobj->cshape->go->object.monster->action_status = MSTA_HIT;
            }
        }
    }
}

void update_weapon_pickaxe(global_data_t *gdata, player_t *player, weapon_t *weapon)
{
    if (get_controls_event(gdata, "Attaque")) {
        animation_reset(player->animation->arms_pickaxe);
        animation_reset(weapon->anim);
        weapon->cshape->is_active = true;
    }
}

void update_consumable(global_data_t *gdata, player_t *player, item_t *wear)
{
    if (get_controls_event(gdata, "Attaque")) {
        modify_satiety(gdata, player->prop, consumable[wear->consumable->id].satiety_regen);
        modify_vitality(gdata, player->prop, consumable[wear->consumable->id].vitality_regen);
        delete_wear_item(gdata, player);
    }
    if (consumable->type == CONST_FOOD);
    else if (consumable->type == CONST_MEDICINE);
}

void update_wearable_item(global_data_t *gdata, player_t *player, item_t *wear)
{
    if (wear == NULL || player->action_status != PA_NONE)
        return;
    if (wear->wearable != NULL) {
        if (wear->wearable->type == WT_SWORD)
            update_weapon_sword(gdata, player, wear->wearable);
        else if (wear->wearable->type == WT_PICKAXE)
            update_weapon_pickaxe(gdata, player, wear->wearable);
    }
    else if (wear->consumable != NULL) {
        update_consumable(gdata, player, wear);
    }
}

void player_update(global_data_t *gdata)
{
    game_object_t *player_go = gameobject_get(gdata, "player_go");
    player_t *player = player_go->object.player;

    if (gdata->player_node->is_active == false)
        return;

    player_move_update(gdata, player);
    player_animation_update(gdata, player);
    if (gdata->key->i == true && player->action_status == PA_NONE)
        open_inventory(gdata);

    inventory_update(gdata);
    if (gdata->key->i == true && player->action_status == PA_INVENTORY)
        close_inventory(gdata, NULL);

    if (gameobject_get_g_position(gdata, player_go).y > 2000) {
        node_set_position(gdata, player_go->node,
        (sfVector2f){100, 100});
        player_go->object.player->move->total_time = 0;
        player_go->object.player->move->vec.y = 0;
    }

    check_interact(gdata, player);
    update_wearable_item(gdata, player, player->inventory->wear);

    if (gdata->key->num9 == true) {
        give_an_item(gdata, player, IID_POTATO);
        gdata->key->num9 = false;
    }
    if (gdata->key->u == true && player->action_status == PA_NONE) {
        node_t *shop = node_get(gdata, "shop_node");
        shop->is_draw = true;
        shop->is_active = true;
        player->action_status = PA_SHOP;
        gdata->key->u = false;
    }
    else if (gdata->key->u == true && player->action_status == PA_SHOP) {
        node_t *shop = node_get(gdata, "shop_node");
        shop->is_draw = false;
        shop->is_active = false;
        player->action_status = PA_NONE;
        gdata->key->u = false;
    }
}