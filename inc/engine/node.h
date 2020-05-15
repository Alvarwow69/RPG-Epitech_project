/*
** EPITECH PROJECT, 2019
** Test
** File description:
** canvas.h
*/

#ifndef NODE_H
#define NODE_H

typedef struct node_s node_t;

#include "scene.h"
#include "rpg.h"

struct node_s {
    char *name;
    char *scene;
    bool is_draw;
    bool is_active;
    bool update;
    int layer;

    sfTransformable *transform;

    game_object_t *gameobjects;

    struct node_s *prev;
    struct node_s *next;
};

/* Return the node find with the given name */
node_t *node_get(global_data_t *gdata, char *name);

/* Return the position of the given node in its scene */
sfVector2f node_get_position(global_data_t *gdata, char *name);

/* Draw all gameobject from specified scene (you don't need to use this function) */
void node_draw(global_data_t *data, node_t *node);

/* Create a node with the given name and place it in the given scene */
void node_create(global_data_t *gdata, char *name, char *scene_name);

/* Set if the given node must be draw or not, respectively 'true' or 'false'
 WARNING : if 'is_active' == false so node mustn't be draw either */
void node_set_draw(global_data_t *gdata, char *name, bool draw);

/* Set if the given node must be update or not, respectively 'true' or 'false'
 WARNING : if 'is_active' == false so node mustn't be draw either */
void node_set_active(global_data_t *gdata, char *name, bool active);

/* Set the position of the given node */
void node_set_position(global_data_t *gdata, char *name, sfVector2f pos);

/* Move the given node */
void node_move(global_data_t *gdata, char *name, sfVector2f offset);

/* Set the scale of the given node */
void node_set_scale(global_data_t *gdata, char *name, sfVector2f scale);

/* Scale the given node */
void node_scale(global_data_t *gdata, char *name, sfVector2f scale);

/* Set the rotation of the given node */
void node_set_rotation(global_data_t *gdata, char *name, float angle);

/* Rotate the given node */
void node_rotate(global_data_t *gdata, char *name, float angle);

/* Set the layer of the given node */
void node_set_layer(global_data_t *gdata, char *name, int layer);

/* Add the given node in the given scene */
void node_add_scene(global_data_t *gdata, char *node_name, char *scene_name);

/* Destroy the given node */
void node_destroy(global_data_t *gdata, char *name);

/* Function only use to debug node */
void node_display(node_t *node);

/* Remove the given node from global chained list
Warning : Do not use that ! */
void node_remove_from_list(global_data_t *gdata, scene_t *scene, node_t *node);

#endif