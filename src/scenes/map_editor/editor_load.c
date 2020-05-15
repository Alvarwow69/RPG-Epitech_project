/*
** EPITECH PROJECT, 2020
** editor_load.c
** File description:
**
*/

#include <rpg.h>

void create_button_remove(global_data_t *data)
{
    button_create(data, "editor_remove", "selection_editor",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "editor_remove",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "editor_remove", "Remove\ntile",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "editor_remove", (sfVector2f){570, 10});
    button_set_text_pos(data, "editor_remove", (sfVector2f){5, 20});
    button_set_text_scale(data, "editor_remove", 15);
    button_set_action(data, "editor_remove", &editor_remove);
    button_set_scale(data, "editor_remove", (sfVector2f){1.5f, 1.5f});
    button_set_press_position(data, "editor_remove", (sfVector2f){0, 10});
}

void create_button_add_tile(global_data_t *data)
{
    button_create(data, "editor_change", "selection_editor",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "editor_change",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "editor_change", "Change\ntile",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "editor_change", (sfVector2f){500, 10});
    button_set_text_pos(data, "editor_change", (sfVector2f){5, 20});
    button_set_text_scale(data, "editor_change", 15);
    button_set_action(data, "editor_change", &editor_change);
    button_set_scale(data, "editor_change", (sfVector2f){1.5f, 1.5f});
    button_set_press_position(data, "editor_change", (sfVector2f){0, 10});
}

void create_button_background(global_data_t *data)
{
    button_create(data, "editor_b_background", "selection_editor",
    data->ressources->textures[BUTTON_L]);
    button_set_other_texture(data, "editor_b_background",
    data->ressources->textures[BUTTON_L_HOVER],
    data->ressources->textures[BUTTON_L_PRESS]);
    button_set_text(data, "editor_b_background", "Change to background",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "editor_b_background", (sfVector2f){640, 10});
    button_set_text_pos(data, "editor_b_background", (sfVector2f){40, 25});
    button_set_text_scale(data, "editor_b_background", 15);
    button_set_action(data, "editor_b_background", &editor_b_background);
    button_set_scale(data, "editor_b_background", (sfVector2f){1.5f, 1.5f});
    button_set_press_position(data, "editor_b_background", (sfVector2f){0, 10});
}

void editor_create_background(global_data_t *data)
{
    gameobject_create(data, "editor_background",
    "background_editor", TYPE_BACKGROUND);
    gameobject_set_texture(data, "editor_background",
    data->ressources->textures[BACK]);
    gameobject_set_scale(data, "editor_background", (sfVector2f){5, 5});
}

void editor_load(global_data_t *data)
{
    scene_t *scene = scene_get(data, "map_editor");

    scene->map_width = 100;
    scene->map_height = 34;
    node_create(data, "interface_editor", "map_editor");
    node_create(data, "background_editor", "map_editor");
    node_create(data, "node_map_editor", "map_editor");
    node_create(data, "selection_editor", "map_editor");
    node_set_layer(data, "interface_editor", 3);
    node_set_layer(data, "selection_editor", 3);
    node_set_layer(data, "node_map_editor", 2);
    create_button_menu(data);
    create_button_selection(data);
    create_button_remove(data);
    create_button_add_tile(data);
    create_button_background(data);
    editor_create_background(data);
    scene->init_pos = sfView_getCenter(scene->game);
    data->loading->loaded = true;
}