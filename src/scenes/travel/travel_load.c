/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** travel_load
*/

#include "rpg.h"

void travel_load_background2(global_data_t *data)
{
    node_create(data, "background_node2", "travel");
    gameobject_create(data, "background_travel2", \
"background_node2", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_travel2", \
data->ressources->textures[TEXTURE_TRAVEL_BACKGROUND2]);
    gameobject_set_position(data, "background_travel2", (sfVector2f){0, 0});
    gameobject_set_scale(data, "background_travel2", \
(sfVector2f) {(float) data->save_render_window_size.x/1920, (float) \
data->save_render_window_size.y/1080});
    node_set_layer(data, "background_node2", 100);
}

void travel_load_create_ship_background(global_data_t *data)
{
    travel_load_background2(data);
    gameobject_create(data, "background_travel", \
"background_node", TYPE_BACKGROUND);
    gameobject_set_texture(data, "background_travel", \
data->ressources->textures[TEXTURE_TRAVEL_BACKGROUND]);
    gameobject_set_position(data, "background_travel", (sfVector2f){0, 0});
    gameobject_set_scale(data, "background_travel", \
(sfVector2f) {(float) data->save_render_window_size.x/1920, (float) \
data->save_render_window_size.y/1080});
    gameobject_create(data, "ship", "water_node", TYPE_IMAGE);
    if (data->travel->scale_ship == 0) {
        gameobject_scale(data, "ship", (sfVector2f) {0.4, 0.4});
        data->travel->scale_ship = 1;
    }
}

void travel_load_create_map_node(global_data_t *data)
{
    data->travel->map = malloc(sizeof(char *) * (11));
    for (int i = 0; i != 10; i ++)
        data->travel->map[i] = malloc(sizeof(char) * (8));
    create_map_travel(data);
    node_create(data, "background_node", "travel");
    node_create(data, "water_node", "travel");
    node_create(data, "water1_node", "travel");
    node_create(data, "ship_node", "travel");
    node_set_layer(data, "background_node", 2);
    node_set_layer(data, "water_node", 3);
    node_set_layer(data, "water1_node", 1);
    node_set_layer(data, "ship_node", 4);
}

void travel_load_create_isle(global_data_t *data)
{
    gameobject_create(data, "cave", "water_node", TYPE_IMAGE);
    gameobject_set_texture(data, "cave", \
data->ressources->textures[TRAVEL_CAVE]);
    gameobject_set_position(data, "cave", (sfVector2f){720, 385});
    gameobject_create(data, "snow", "water_node", TYPE_IMAGE);
    gameobject_set_texture(data, "snow", \
data->ressources->textures[TRAVEL_SNOW]);
    gameobject_set_position(data, "snow", (sfVector2f){-510, 290});
    gameobject_create(data, "sand", "water_node", TYPE_IMAGE);
    gameobject_set_texture(data, "sand", \
data->ressources->textures[TRAVEL_SAND]);
    gameobject_set_position(data, "sand", (sfVector2f){0, 150});
    gameobject_create(data, "jungle", "water_node", TYPE_IMAGE);
    gameobject_set_texture(data, "jungle", \
data->ressources->textures[TRAVEL_JUNGLE]);
    gameobject_set_position(data, "jungle", (sfVector2f){130, 530});
}

void travel_load(global_data_t *data)
{
    if (data->travel->start_travel == 0) {
        travel_load_create_map_node(data);
        travel_load_create_ship_background(data);
        create_water(data);
        travel_load_create_isle(data);
        set_layer(data);
    }
    data->loading->loaded = true;
}
