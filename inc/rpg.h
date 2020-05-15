/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

typedef struct objects_s objects_t;
typedef struct global_data_s global_data_t;

#define SIGN(nbr) (nbr < 0 ? (-1) : (1))
#define ABS(nbr) (nbr < 0 ? ((nbr) * -1) : (nbr))
#define CHUNK 20

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "utils.h"
#include "printf.h"
#include "color.h"

#include "global_struct.h"
#include "ressource.h"
#include "speach.h"

#include "colision.h"
#include "entity.h"
#include "gameobject.h"
#include "button.h"
#include "option.h"
#include "text.h"
#include "node.h"
#include "scene.h"
#include "keyboard.h"
#include "travel.h"

#include "map_editor.h"
#include "controls.h"
#include "ressource.h"
#include "speach.h"
#include "map_save.h"
#include "pause.h"
#include "quest.h"
#include "water.h"
#include "bloc.h"
#include "camera.h"
#include "desert.h"
#include "cave.h"
#include "snow.h"

struct objects_s {
    game_object_t *game_object;
    node_t *node;
    scene_t *scene;
    collide_shape_t *cshape_other;
    collide_shape_t *cshape_block;
};

typedef struct loading_s{
    sfThread *loader;
    bool loaded;
    sfSprite *sprite;
    sfTexture *lilo_tex;
    sfSprite *lilodon;
    sfMutex *lock;
} loading_t;

struct global_data_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfView *default_view;
    ressources_t *ressources;
    travel_t *travel;
    objects_t *objects;
    keyboard_t *key;
    node_t *player_node;
    controls_t *controls;
    int controls_need_reload;
    scene_t *active_scene;
    scene_t *prev_scene;
    scene_t *prev_game;
    quest_t *quest;
    sfVector2u save_render_window_size;
    int music_volume;
    int sound_volume;
    int selected_block;
    int remove_tile;
    int background;
    sfEvent event;
    loading_t *loading;
};


void event_handler(global_data_t *data, scene_t *scene);
void main_load(global_data_t *data);
void main_unload(global_data_t *data);
void main_event(global_data_t *data);
void map_load(global_data_t *data);
void map_event(global_data_t *data);
void create_map(global_data_t *data, char *path, char *scene);
void init_keyboard(global_data_t *data);
void map_save(global_data_t *data, char *node_name);
void preprare_lists(map_save_t *map, scene_t *scene);
void create_scene(global_data_t *data);
void main_button_edit(global_data_t *data, button_t *button);
void main_button_close(global_data_t *data, button_t *button);
void main_button_play(global_data_t *data, button_t *button);
void main_button_setting(global_data_t *data, button_t *button);
int my_get_nbr(char const *str);
void create_player(global_data_t *data, sfVector2f start, char *scene);
void map_key(global_data_t *data, scene_t *scene);
void map_unload(global_data_t *data);
void display_objects(global_data_t *gdata);
global_data_t *init_gdata(void);
void init_default_value(global_data_t *gdata);
loading_t *init_loader(global_data_t *data);
objects_t *init_objects(void);
void create_button_option(global_data_t *data);
void create_button_edit(global_data_t *data);
void create_button_quit(global_data_t *data);
void create_main_button(global_data_t *data);
void node_set_position(global_data_t *gdata, char *name, sfVector2f pos);
void player_to_save(global_data_t *data);
void save_to_player(global_data_t *data);


sfVector2f scale_vector(sfVector2f vector, sfVector2f scale);
sfVector2f add_vectorf(sfVector2f vector1, sfVector2f vector2);
sfVector2i add_vectori(sfVector2i vector1, sfVector2i vector2);
sfIntRect add_recti(sfIntRect rect1, sfIntRect rect2);
sfIntRect add_recti_vectori(sfIntRect rect, sfVector2i vector);
sfRenderStates get_render_states(global_data_t *gdata,
game_object_t *gameobject);

#endif //RPG_H