/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** init_ui.c
*/

#include "rpg.h"

void create_ui_item(global_data_t *gdata, ui_rsc_id id, char *name, item_t *item)
{
    char *wear_name = concat_fstring("%s_wear", name);
    char *text_name = concat_fstring("%s_count", name);

    gameobject_create(gdata, wear_name, "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_position(gdata, wear_name, add_vectorf(ui_rsc[id].pos, (sfVector2f){630, 0}));
    gameobject_set_texture(gdata, wear_name, gdata->ressources->textures[TEXTURE_ACTIVE_BAR]);
    gameobject_set_texture_rect(gdata, wear_name, ui_rsc[id].normal);
    gameobject_set_layer(gdata, wear_name, 4);

    gameobject_create(gdata, name, "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_position(gdata, name, add_vectorf(ui_rsc[id].pos, (sfVector2f){638, 8}));
    item->go_act = gameobject_get(gdata, name);
    sfSprite_destroy(item->go_act->object.sprite);
    item->go_act->object.sprite = item->go_inv->object.sprite;
    gameobject_set_layer(gdata, name, 3);

    text_create(gdata, text_name, "p_ui_node");
    text_set_font(gdata, text_name, gdata->ressources->fonts[STARFONT]);
    set_item_count(gdata, item);
    text_set_color(gdata, text_name, sfYellow);
    text_set_size(gdata, text_name, 42);
    gameobject_set_position(gdata, text_name, add_vectorf(ui_rsc[id].pos, (sfVector2f){650, 20}));
    gameobject_set_layer(gdata, text_name, 4);
    free(text_name);
}

void init_ui(global_data_t *gdata, char *scene)
{
    player_t *player = gameobject_get(gdata, "player_go")->object.player;

    node_create(gdata, "p_ui_node", scene);
    node_set_position(gdata, "p_ui_node", (sfVector2f){20, 20});
    node_set_layer(gdata, "p_ui_node", 9);

    gameobject_create(gdata, "p_ui_bar_background", "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_ui_bar_background", gdata->ressources->textures[TEXTURE_UI_BAR]);
    gameobject_set_texture_rect(gdata, "p_ui_bar_background", (sfIntRect){0, 0, 330, 162});
    gameobject_set_scale(gdata, "p_ui_bar_background", UI_SCALE);

    gameobject_create(gdata, "p_ui_hp_bar", "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_ui_hp_bar", gdata->ressources->textures[TEXTURE_UI_BAR]);
    gameobject_set_texture_rect(gdata, "p_ui_hp_bar", (sfIntRect){0, 163, 266, 8});
    gameobject_set_position(gdata, "p_ui_hp_bar", scale_vector((sfVector2f){52, 14}, UI_SCALE));
    gameobject_set_scale(gdata, "p_ui_hp_bar", UI_SCALE);
    gameobject_set_layer(gdata, "p_ui_hp_bar", 2);

    gameobject_create(gdata, "p_ui_xp_bar", "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_ui_xp_bar", gdata->ressources->textures[TEXTURE_UI_BAR]);
    gameobject_set_texture_rect(gdata, "p_ui_xp_bar", (sfIntRect){0, 172, 236, 8});
    gameobject_set_position(gdata, "p_ui_xp_bar", scale_vector((sfVector2f){52, 56}, UI_SCALE));
    gameobject_set_scale(gdata, "p_ui_xp_bar", UI_SCALE);
    gameobject_set_layer(gdata, "p_ui_xp_bar", 2);

    gameobject_create(gdata, "p_ui_st_bar", "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_ui_st_bar", gdata->ressources->textures[TEXTURE_UI_BAR]);
    gameobject_set_texture_rect(gdata, "p_ui_st_bar", (sfIntRect){0, 181, 206, 8});
    gameobject_set_position(gdata, "p_ui_st_bar", scale_vector((sfVector2f){52, 98}, UI_SCALE));
    gameobject_set_scale(gdata, "p_ui_st_bar", UI_SCALE);
    gameobject_set_layer(gdata, "p_ui_st_bar", 2);

    text_create(gdata, "p_ui_money_text", "p_ui_node");
    text_set_font(gdata, "p_ui_money_text", gdata->ressources->fonts[STARFONT]);
    text_set_message(gdata, "p_ui_money_text", get_integer_nbr(player->prop->money));
    text_set_color(gdata, "p_ui_money_text", sfWhite);
    text_set_size(gdata, "p_ui_money_text", 34);
    gameobject_set_position(gdata, "p_ui_money_text", scale_vector((sfVector2f){65, 118}, UI_SCALE));
    gameobject_set_layer(gdata, "p_ui_money_text", 3);

    gameobject_create(gdata, "p_ui_active_bar", "p_ui_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "p_ui_active_bar", gdata->ressources->textures[TEXTURE_ACTIVE_BAR]);
    gameobject_set_texture_rect(gdata, "p_ui_active_bar", (sfIntRect){0, 0, 600, 104});
    gameobject_set_position(gdata, "p_ui_active_bar", (sfVector2f){630, 0});
    gameobject_set_scale(gdata, "p_ui_active_bar", UI_SCALE);
    gameobject_set_layer(gdata, "p_ui_active_bar", 2);

    create_ui_item(gdata, UIRSC_ACTIVE_SLOT1, "p_ui_active_slot1_inv", player->inventory->items[SLOT_ACTIVE[0]]);
    gameobject_set_texture_rect(gdata, concat_fstring("%s_wear", player->inventory->wear->go_act->name), ui_rsc[UIRSC_SLOT].select);
    create_ui_item(gdata, UIRSC_ACTIVE_SLOT2, "p_ui_active_slot2_inv", player->inventory->items[SLOT_ACTIVE[1]]);
    create_ui_item(gdata, UIRSC_ACTIVE_SLOT3, "p_ui_active_slot3_inv", player->inventory->items[SLOT_ACTIVE[2]]);
    create_ui_item(gdata, UIRSC_ACTIVE_SLOT4, "p_ui_active_slot4_inv", player->inventory->items[SLOT_ACTIVE[3]]);
    create_ui_item(gdata, UIRSC_ACTIVE_SLOT5, "p_ui_active_slot5_inv", player->inventory->items[SLOT_ACTIVE[4]]);
}