/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** init_inventory.c
*/

#include "rpg.h"

void create_inventory_item(global_data_t *gdata, inventory_rsc_id id, char *name, int nbr, item_t *item)
{
    char *text_name = concat_fstring("%s_count", name);

    gameobject_create(gdata, name, "p_inv_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, name, gdata->ressources->textures[TEXTURE_INV_ICON]);
    gameobject_set_texture_rect(gdata, name, item_list[item->id].rect);
    gameobject_scale(gdata, name, INV_SCALE);
    gameobject_set_position(gdata, name, scale_vector(add_vectorf(inv_rsc[id].pos[nbr], (sfVector2f){4, 4}), INV_SCALE));
    item->go_inv = gameobject_get(gdata, name);

    if (id != IRSC_HELM_SLOT && id != IRSC_RING_SLOT
    && id != IRSC_CHEST_SLOT&& id != IRSC_PANTS_SLOT) {
        text_create(gdata, text_name, "p_inv_node");
        text_set_font(gdata, text_name, gdata->ressources->fonts[STARFONT]);
        set_item_count(gdata, item);
        text_set_color(gdata, text_name, sfYellow);
        text_set_size(gdata, text_name, 42);
        gameobject_set_position(gdata, text_name, scale_vector(add_vectorf(inv_rsc[id].pos[nbr], (sfVector2f){10, 10}), INV_SCALE));
        gameobject_set_layer(gdata, text_name, 3);
    }
    free(text_name);
}

void create_inventory_button(global_data_t *gdata, inventory_rsc_id id, char *name, int nbr)
{
    button_create(gdata, name, "p_inv_node"
    , gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]);
    button_set_scale(gdata, name, INV_SCALE);
    button_set_other_texture(gdata, name
    , gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]
    , gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]);
    button_set_tex_rect(gdata, name, inv_rsc[id].normal);
    button_set_hover_rect(gdata, name, inv_rsc[id].hover);
    button_set_click_rect(gdata, name, inv_rsc[id].click);
    button_set_action(gdata, name, inv_rsc[id].action);
    button_set_position(gdata, name, scale_vector(inv_rsc[id].pos[nbr], INV_SCALE));
}

void init_inventory_button(global_data_t *gdata, player_t *player)
{

    create_inventory_button(gdata, IRSC_RING_SLOT, "p_inv_ring_slot0", 0);
    create_inventory_item(gdata, IRSC_RING_SLOT, "p_inv_ring_slot0_item", 0, player->inventory->items[SLOT_RING1]);
    create_inventory_button(gdata, IRSC_RING_SLOT, "p_inv_ring_slot1", 1);
    create_inventory_item(gdata, IRSC_RING_SLOT, "p_inv_ring_slot1_item", 1, player->inventory->items[SLOT_RING2]);
    create_inventory_button(gdata, IRSC_HELM_SLOT, "p_inv_helm_slot", 0);
    create_inventory_item(gdata, IRSC_HELM_SLOT, "p_inv_helm_slot_item", 0, player->inventory->items[SLOT_HELM]);
    create_inventory_button(gdata, IRSC_CHEST_SLOT, "p_inv_chest_slot", 0);
    create_inventory_item(gdata, IRSC_CHEST_SLOT, "p_inv_chest_slot_item", 0, player->inventory->items[SLOT_CHEST]);
    create_inventory_button(gdata, IRSC_PANTS_SLOT, "p_inv_pants_slot", 0);
    create_inventory_item(gdata, IRSC_PANTS_SLOT, "p_inv_pants_slot_item", 0, player->inventory->items[SLOT_PANTS]);
    for (int ctr = 0; ctr < ACTIVE_COUNT; ctr += 1) {
        create_inventory_button(gdata, IRSC_ACTIVE_SLOT
        , concat_fstring("p_inv_active_slot%i", ctr), ctr);
        create_inventory_item(gdata, IRSC_ACTIVE_SLOT
        , concat_fstring("p_inv_active_slot%i_item", ctr), ctr, player->inventory->items[ctr + SLOT_ACTIVE[0]]);
    }
    for (int ctr = 0; ctr < INV_COUNT; ctr += 1) {
        create_inventory_button(gdata, IRSC_INV_SLOT
        , concat_fstring("p_inv_inv_slot%i", ctr), ctr);
        create_inventory_item(gdata, IRSC_INV_SLOT
        , concat_fstring("p_inv_inv_slot%i_item", ctr), ctr, player->inventory->items[ctr + SLOT_INV[0]]);
    }
    create_inventory_button(gdata, IRSC_TRASH, "p_inv_trash", 0);
    for (int ctr = 0; inv_rsc[IRSC_PSTAT_ADD].pos[ctr].x != -1; ctr += 1)
        create_inventory_button(gdata, IRSC_PSTAT_ADD, concat_fstring("p_inv_pstat_add%i", ctr), ctr);
    create_inventory_button(gdata, IRSC_CLOSE_CROSS, "p_inv_close_cross", 0);
    create_inventory_item(gdata, IRSC_INV_SLOT, "p_inv_pick", 0, player->inventory->pick);
    gameobject_set_layer(gdata, "p_inv_pick", 2);
    player->inventory->pick->go_inv->is_draw = false;
}

void create_inventory_text(global_data_t *gdata, char *name, sfVector2f pos, int value)
{
    char *text_name = concat_fstring("%s_text", name);
    static int ctr = 0;

    text_create(gdata, text_name, "p_inv_node");
    text_set_font(gdata, text_name, gdata->ressources->fonts[STARFONT]);
    text_set_message(gdata, text_name, get_integer_nbr(value));
    text_set_color(gdata, text_name, sfWhite);
    text_set_size(gdata, text_name, 42);
    gameobject_set_position(gdata, text_name, scale_vector(pos, INV_SCALE));
    gameobject_set_layer(gdata, text_name, 3);
    if (cmp_string(name, "p_inv_pstat_avl") != 0)
        create_inventory_button(gdata, IRSC_PSTAT_ADD, name, ctr);
    free(text_name);
    ctr += 1;
}

void init_inventory_text(global_data_t *gdata, int avl_point, stats_t *stat)
{
    create_inventory_text(gdata, "p_inv_pstat_vit", inv_rsc[IRSC_PSTAT_VIT].pos[0], stat->vit);
    create_inventory_text(gdata, "p_inv_pstat_mstr", inv_rsc[IRSC_PSTAT_MSTR].pos[0], stat->mstr);
    create_inventory_text(gdata, "p_inv_pstat_rstr", inv_rsc[IRSC_PSTAT_RSTR].pos[0], stat->rstr);
    create_inventory_text(gdata, "p_inv_pstat_mdef", inv_rsc[IRSC_PSTAT_MDEF].pos[0], stat->mdef);
    create_inventory_text(gdata, "p_inv_pstat_rdef", inv_rsc[IRSC_PSTAT_RDEF].pos[0], stat->rdef);
    create_inventory_text(gdata, "p_inv_pstat_acc", inv_rsc[IRSC_PSTAT_ACC].pos[0], stat->acc);
    create_inventory_text(gdata, "p_inv_pstat_luck", inv_rsc[IRSC_PSTAT_LUCK].pos[0], stat->luck);
    create_inventory_text(gdata, "p_inv_pstat_dext", inv_rsc[IRSC_PSTAT_DEXT].pos[0], stat->dext);
    create_inventory_text(gdata, "p_inv_pstat_cel", inv_rsc[IRSC_PSTAT_CEL].pos[0], stat->cel);
    create_inventory_text(gdata, "p_inv_pstat_avl", inv_rsc[IRSC_PSTAT_AVL].pos[0], avl_point);
}

void create_inventory_screen(global_data_t *gdata, char *scene)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;
    node_t *inventory = NULL;

    node_create(gdata, "p_inv_node", scene);
    node_set_position(gdata, "p_inv_node", (sfVector2f){500, 50});
    inventory = node_get(gdata, "p_inv_node");
    inventory->is_draw = false;
    inventory->is_active = false;
    node_set_layer(gdata, "p_inv_node", 10);

    init_inventory_button(gdata, player);
    init_inventory_text(gdata, player->prop->avl_point, player->stats);

    gameobject_create(gdata, "p_inv_hp_bar", "p_inv_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_inv_hp_bar", gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]);
    gameobject_set_texture_rect(gdata, "p_inv_hp_bar", inv_rsc[IRSC_HP_BAR].normal);
    gameobject_scale(gdata, "p_inv_hp_bar", INV_SCALE);
    gameobject_set_position(gdata, "p_inv_hp_bar", scale_vector(inv_rsc[IRSC_HP_BAR].pos[0], INV_SCALE));

    gameobject_create(gdata, "p_inv_xp_bar", "p_inv_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_inv_xp_bar", gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]);
    gameobject_set_texture_rect(gdata, "p_inv_xp_bar", inv_rsc[IRSC_XP_BAR].normal);
    gameobject_scale(gdata, "p_inv_xp_bar", INV_SCALE);
    gameobject_set_position(gdata, "p_inv_xp_bar", scale_vector(inv_rsc[IRSC_XP_BAR].pos[0], INV_SCALE));

    gameobject_create(gdata, "p_inv_go", "p_inv_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_inv_go", gdata->ressources->textures[TEXTURE_PLAYER_INVENTORY]);
    gameobject_set_texture_rect(gdata, "p_inv_go", (sfIntRect){0, 0, 509, 442});
    gameobject_scale(gdata, "p_inv_go", INV_SCALE);
}