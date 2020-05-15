/*
** EPITECH PROJECT, 2019
** scene.h
** File description:
** 
*/

#ifndef ENGINE_SCENE
#define ENGINE_SCENE

typedef struct scene_s scene_t;

#include "rpg.h"

struct scene_s
{
    char *name;
    void (*load)(void *);
    void (*unload)(global_data_t *);
    void (*event)(global_data_t *);
    sfVector2u size_game;
    sfVector2u size_interface;
    sfVector2f init_pos;
    sfVector2f default_pos;
    sfView *game;
    sfView *interface;
    node_t *node;
    int is_load;
    int is_active;
    int map_height;
    int map_width;
    float max_width;
    float max_height;
    bool pause;
    struct scene_s *prev;
    struct scene_s *next;
};

/*Get any created scene with her name*/
scene_t *scene_get(global_data_t *data, char *name);

/*create one scene withe unique name*/
void scene_create(global_data_t *data, char *name);

/*Define loading.png funtion*/
void scene_set_load(global_data_t *data, char *name, void (*load)(global_data_t *));

/*Define unload function*/
void scene_set_unload(global_data_t *data, char *name, void (*unload)(global_data_t *));

/*Display one scene*/
void scene_draw(global_data_t *data, char *name, bool unload, bool screen);

/*Load one scene*/
void scene_load(global_data_t *data, char *name, bool screen);

/*Unload one scene*/
void scene_unload(global_data_t *data, scene_t *scene);

/*Add gameObject to a scene*/
void scene_add_node(global_data_t *data, char *s_name, char *node_name);

/*Destroy all existing scene*/
void destroy_all_scene(global_data_t *data);

/* Use to debug */
void scene_display(global_data_t *gdata, char *name);

/* Destroy the given scene */
void scene_destroy(global_data_t *gdata, char *name);

/* Set the event function of the given scene */
void scene_set_event(global_data_t *data, char *name, void (*event)(global_data_t *));


#endif //ENGINE_SCENE
