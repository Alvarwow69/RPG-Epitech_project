/*
** EPITECH PROJECT, 2020
** map_event.c
** File description:
** 
*/

#include "rpg.h"

void map_key(global_data_t *data, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    node_t *inv = node_get(data, "p_inv_node");
    node_t *shop = node_get(data, "shop_node");
    sfVector2f pixel_pos;

    if (get_controls_event(data, "Attaque")) {
        pixel_pos = sfRenderWindow_mapPixelToCoords\
(data->window, mouse_pos, scene->game);
        bloc_add_map(data, pixel_pos);
        if (inv->is_active == true)
            check_button(data, sfMouse_get\
PositionRenderWindow(data->window), scene->interface, inv);
        if (shop->is_active == true)
            check_button(data, sfMouse_get\
PositionRenderWindow(data->window), scene->interface, shop);
        destroy_block(data, pixel_pos);
    }
    if (get_controls_event(data, "Pause")) {
        scene_draw(data, "pause", false, false);
        data->prev_game = scene;
    }
}

void update_pnj_quest(global_data_t *data, char *name, id_quest_e id_quest)
{
    pnj_t *pnj = gameobject_get(data, \
concat_fstring("%s_go", name))->object.pnj;

    for (collide_object_t *cobj = pnj->talk_collision\
->collision_list; cobj != NULL; cobj = cobj->next) {
        if (cobj->cshape->type != CTYPE_INTERACT \
|| cobj->cshape->go->type != TYPE_PLAYER)
            continue;
        if (get_controls_event(data, "Interact") == 1) {
            create_quest(data, quest_setting[id_quest]);
        }
    }
}

void map_event(global_data_t *data)
{
    scene_t *scene = scene_get(data, "map");

    sfMusic_setLoop(data->ressources->musics[MUSIC_START], sfTrue);
    play_music_wait(data, MUSIC_START);
    map_key(data, scene);
    collide_shape_check_all(data);
    collide_bloc_check_all(data);
    collide_b_b_check_all(data);
    ui_update(data);
    update_block(data, scene);
    pnj_update_all(data);
    update_pnj_quest(data, "Villager_1", HUNT1_IDQ);
    update_pnj_quest(data, "Villager_2", FIND1_IDQ);
    update_pnj_quest(data, "Villager_3", FIND2_IDQ);
    water_update(data, scene);
    update_camera(data);
    monster_update_all(data);
    player_update(data);
}