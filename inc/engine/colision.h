/*
** EPITECH PROJECT, 2019
** Test
** File description:
** colision.h
*/

#ifndef COLISION_H
#define COLISION_H

typedef struct collide_shape_s collide_shape_t;
typedef struct collide_object_s collide_object_t;

typedef enum collision_type_e {
    CTYPE_TARGET,
    CTYPE_INTERACT,
    CTYPE_M_FIGHT,
    CTYPE_R_FIGHT,
    CTYPE_BODY,
    CTYPE_BLOCK
} collision_type;

#include <math.h>
#include "gameobject.h"
#include "rpg.h"

struct collide_object_s {
    collide_shape_t *cshape;
    bool left;
    sfVector2f left_offset;
    bool right;
    sfVector2f right_offset;
    bool top;
    sfVector2f top_offset;
    bool bottom;
    sfVector2f bottom_offset;
    collide_object_t *next;
};

struct collide_shape_s {
    char *name;
    collision_type type;
    game_object_t *go;
    int count_point;
    sfVector2f *points;
    bool is_draw;
    bool is_active;
    sfVertexArray *array;
    sfIntRect max;
    collide_object_t *collision_list;
    collide_shape_t *next;
    collide_shape_t *prev;
};

/* Create a new collide shape */
collide_shape_t *collide_shape_create(global_data_t *gdata, char *name, char *go_name, collision_type type);

/* Destroy the given collide shape */
void collide_shape_destroy(global_data_t *gdata, char *name);

/* Return the collide shape find with the given name */
collide_shape_t *collide_shape_get(global_data_t *gdata, char *name);

/* Add a new point in the given collide shape*/
void collide_shape_add_point(collide_shape_t *shape, sfVector2f pos);

/* Return true if the two given collide shape are collide, else it return false */
bool collide_shape_is_collide(collide_shape_t *shape1, sfVector2f pos1
                             , collide_shape_t *shape2, sfVector2f pos2);
sfVector2f get_point(collide_shape_t *shape1, collide_shape_t *shape2
                    , sfVector2f d, sfVector2f pos1, sfVector2f pos2);
sfVector2f support_function(collide_shape_t *shape, sfVector2f d, sfVector2f pos);

/* Set if the given collide shape must be draw or not, respectively 'true' or 'false'*/
void collide_shape_set_draw(collide_shape_t *cshape, bool is_draw);

/* Check all collide shape and create collision list in each collide shape collided */
void collide_shape_check_all(global_data_t *gdata);

/* Draw the given collide shape if is_draw == true */
void collide_shape_draw(sfRenderWindow *rwindow, collide_shape_t *cshape
                       , sfRenderStates states);

void create_collide_objects(collide_shape_t *cshape1, sfVector2f pos1
                             , collide_shape_t *cshape2, sfVector2f pos2);

void collide_bloc_check_all(global_data_t *gdata);

sfVector2f gameobject_get_g_origin(global_data_t *gdata, game_object_t *game);

void collide_b_b_check_all(global_data_t *gdata);

game_object_t *get_chunk(global_data_t *data, collide_shape_t *shape);

#endif