/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** init_shop.c
*/

#include "rpg.h"

void create_shop_button(global_data_t *gdata, inventory_rsc_id id, char *name)
{
    button_create(gdata, name, "shop_node", gdata->ressources->textures[TEXTURE_SHOP_SCREEN]);
    button_set_scale(gdata, name, INV_SCALE);
    button_set_other_texture(gdata, name, gdata->ressources->textures[TEXTURE_SHOP_SCREEN], gdata->ressources->textures[TEXTURE_SHOP_SCREEN]);
    button_set_tex_rect(gdata, name, shop_rsc[id].normal);
    button_set_hover_rect(gdata, name, shop_rsc[id].hover);
    button_set_click_rect(gdata, name, shop_rsc[id].click);
    button_set_action(gdata, name, shop_rsc[id].action);
    button_set_position(gdata, name, scale_vector(shop_rsc[id].pos, INV_SCALE));
}

void init_shop_button(global_data_t *gdata)
{
    create_shop_button(gdata, SRSC_BUY_POTATO, "shop_buy_potato");
    create_shop_button(gdata, SRSC_BUY_APPLE, "shop_buy_apple");
    create_shop_button(gdata, SRSC_BUY_RICE, "shop_buy_rice");
    create_shop_button(gdata, SRSC_BUY_SOUP, "shop_buy_soup");
    create_shop_button(gdata, SRSC_BUY_BANDAGE, "shop_buy_bandage");
}

void init_shop(global_data_t *gdata, char *scene)
{
    node_t *node = NULL;

    node_create(gdata, "shop_node", scene);
    node_set_position(gdata, "shop_node", (sfVector2f){500, 50});
    node = node_get(gdata, "shop_node");
    node->is_draw = false;
    node->is_active = false;
    node_set_layer(gdata, "shop_node", 10);

    gameobject_create(gdata, "shop_back", "shop_node", TYPE_BACKGROUND);
    gameobject_set_texture(gdata, "shop_back", gdata->ressources->textures[TEXTURE_SHOP_SCREEN]);
    gameobject_set_texture_rect(gdata, "shop_back", (sfIntRect){0, 0, 185, 224});
    gameobject_scale(gdata, "shop_back", INV_SCALE);

    init_shop_button(gdata);
}