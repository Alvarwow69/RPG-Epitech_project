/*
** EPITECH PROJECT, 2020
** bloc.h
** File description:
** 
*/

#ifndef MUL_RPG_2019_BLOC
#define MUL_RPG_2019_BLOC

#include "move.h"
#include "rpg.h"

struct bloc_s
{
    sfSprite *sprite;
    game_object_t *gameobject;
    int move_in;
    collide_shape_t *collide_shape;
    int plate;
    int id;
    int gravity;
    int water_level;
    float percent;
    int broken;
    float time_break;
    unsigned destruction_level;
    move_t *move;
    int action;
};

bloc_t *init_bloc_struct(void);
void bloc_set_texture_rect(global_data_t *data, char *name, sfIntRect rect);
void bloc_set_scale(global_data_t *data, char *name, sfVector2f scale);
void bloc_set_texture(global_data_t *data, char *name, sfTexture *texture);
void bloc_create(global_data_t *data, char *name, char *node_name, int id);
bloc_t *bloc_get(global_data_t *data, char *name);
void destroy_block(global_data_t *data, sfVector2f pos);
void give_block(global_data_t *data, game_object_t *game);
void update_block(global_data_t *data, scene_t *scene);
void bloc_draw(global_data_t *data, game_object_t *gameobject, scene_t *scene);
char *get_first_node_map(scene_t *scene);
void bloc_destroy(global_data_t *data, bloc_t *bloc);
sfVector2i get_real_pos(global_data_t *data, sfVector2f position,
char *node_name);
void set_layer_tile(global_data_t *data, char *name, int ore, int id);
void bloc_add_map(global_data_t *data, sfVector2f pos);
void load_bloc(map_save_t *map, char **bloc_content, sfVector2i pos);

#endif //MUL_RPG_2019_BLOC
