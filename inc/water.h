/*
** EPITECH PROJECT, 2020
** water.h
** File description:
** 
*/

#ifndef MUL_RPG_2019_WATER
#define MUL_RPG_2019_WATER

void water_update(global_data_t *data, scene_t *scene);
void create_water_tile(global_data_t *data, scene_t *scene, sfVector2i pos);
void move_cam(global_data_t *data, scene_t *scene);
void free_name(char **str);
int get_solid_tile(global_data_t *data, sfVector2i pos, node_t *node);
game_object_t *create_new_water(global_data_t *data, node_t *node, sfVector2i pos);
void update_water_size(global_data_t *data, node_t *node);

#endif //MUL_RPG_2019_WATER
