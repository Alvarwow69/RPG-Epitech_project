/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

typedef enum {
    START
} isle_e;

typedef enum {
    BASE,
    UP,
    DOWN,
    LEFT,
    RIGHT
} move_e;

typedef struct {
    char **map;
    sfVector2i center_map;
    sfVector2i t_map;
    sfVector2i t_diff_map;
    sfVector2f move_center_map;
    sfVector2f pos_ship;
    int x_map;
    int y_map;
    int tmp;
    int move;
    int move_tmp;
    int start_travel;
    int choice_map;
    int scale_ship;
    int scale_background;
    int leave_travel;
    game_time_t *time;
}travel_t;

void choice_travel(global_data_t *data);
void create_travel_scene(global_data_t *data);
void travel_act(global_data_t *data);
void start_travel(global_data_t *data, isle_e isle);
void set_layer_ship(global_data_t *data);

//init_travel.c
void init_travel(global_data_t *data);
void set_water(global_data_t *data, char *node, char *name, sfVector2i coord);


//travel_load.c
void travel_load(global_data_t *data);

//map.c
void create_map_travel(global_data_t *data);

//travel_layer.c
void set_layer(global_data_t *data);

//create_water.c
void create_water(global_data_t *data);

//move_ship.c
void move_ship(global_data_t *data);

//move_ship_map
void move_ship_up(global_data_t *data);
void move_ship_down(global_data_t *data);
void move_ship_left(global_data_t *data);
void move_ship_right(global_data_t *data);

//set_layer_ship.c
void set_layer_ship(global_data_t *data);
void set_layer_ship2(global_data_t *data);
void travel_act_keybind(global_data_t *data);


void travel_act_keybing_2(global_data_t *data);
void move_ship_map(global_data_t *data);

#endif
