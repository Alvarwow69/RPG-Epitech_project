/*
** EPITECH PROJECT, 2019
** gameobject.h
** File description:
** 
*/

#ifndef ENGINE_GAMEOBJECT
#define ENGINE_GAMEOBJECT

typedef struct game_object_s game_object_t;
typedef struct button_s button_t;
typedef struct text_s text_t;
typedef struct bloc_s bloc_t;

typedef enum gameobject_type_e
{
    TYPE_IMAGE,
    TYPE_BUTTON,
    TYPE_BACKGROUND,
    TYPE_TEXT,
    TYPE_BLOC,
    TYPE_PLAYER,
    TYPE_PNJ,
    TYPE_MONSTER,
    TYPE_END
} gameobject_type;

typedef enum tag_e {
    TAG_ENTITY,
    TAG_MOB,
    TAG_PLAYER,
    TAG_PNJ,
    TAG_INVENTORY,
    TAG_END
} tag;

#include "node.h"
#include "monster.h"
#include "pnj.h"
#include "player.h"
#include "entity.h"
#include "rpg.h"

struct game_object_s
{
    char *name;
    char *node;
    tag *tags;
    gameobject_type type;
    bool is_draw;
    bool is_active;
    int layer;

    union {
        sfSprite *sprite;
        button_t *button;
        player_t *player;
        text_t *text;
        pnj_t *pnj;
        bloc_t *bloc;
        monster_t *monster;
    } object;

    sfTransformable *transform;
    struct game_object_s *prev;
    struct game_object_s *next;
};

/*Gat any gameobject with his name*/
game_object_t *gameobject_get(global_data_t *data, char *name);

/* Return a table of game_objects of the same tag requested */
game_object_t **gameobject_get_tag(global_data_t *gdata, tag tag_search);

/* Return a table of game_objects of the same type requested */
game_object_t **gameobject_get_type(global_data_t *gdata, gameobject_type type_search);

/* Return the position of the given gameobject in its scene */
sfVector2f gameobject_get_global_position(global_data_t *gdata, char *name);

/* Return the position of the given gameobject in its node */
sfVector2f gameobject_get_local_position(global_data_t *gdata, char *name);

/* Return the origin of the given gameobject in its scene */
sfVector2f gameobject_get_global_origin(global_data_t *gdata, char *name);

/*Define a texture for the sprite of the gameobject*/
void gameobject_set_sprite(global_data_t *data, char *name, sfTexture *texture);

void gameobject_draw(global_data_t *data, game_object_t *gameobject, node_t *node);

/*Create one gameobject with unique name*/
void gameobject_create(global_data_t *data, char *name, char *name_node, gameobject_type type);

/*Define position for a specified gameobject*/
void gameobject_set_position(global_data_t *data, char *name, sfVector2f pos);

/* Define origin of the given gameobject */
void gameobject_set_origin(global_data_t *gdata, char *name, sfVector2f origin);

/*Destroy all gameobject from scene*/
void gameobject_destroy(global_data_t *data, char *name);

/*Define a tag for a specified gameobject*/
void gameobject_set_tag(global_data_t *data, char *name, tag *tags);

/*Get all gameobject from scene with specified tag*/
game_object_t **gameobject_get_by_tag(global_data_t *data, char *s_name, tag *tags);

/*Define texture for specified gameobject*/
void gameobject_set_texture(global_data_t *data, char *name, sfTexture *texture);

/*Define intRect for a specified gameobject*/
void gameobject_set_texture_rect(global_data_t *data, char *name, sfIntRect rect);

/*Define a layer to specified gamObject*/
void gameobject_set_layer(global_data_t *data, char *name, int layer);

/*Move gameobject*/
void gameobject_move(global_data_t *data, char *name, sfVector2f move);

void gameobject_rotate(global_data_t *data, char *name, float rotate);

void gameobject_scale(global_data_t *data, char *name, sfVector2f scale);

/* Do not use ! */
void gameobject_remove_from_list(global_data_t *gdata, node_t *node, game_object_t *go);

int gameobject_get_layer(global_data_t *data, char *name);

void gameobject_set_scale(global_data_t *data, char *name, sfVector2f scale);

void define_type(global_data_t *gdata, game_object_t *gameobject);

sfRenderStates get_render_states(global_data_t *gdata, game_object_t *gameobject);

sfVector2f gameobject_get_g_position(global_data_t *gdata, game_object_t *game);

#endif //ENGINE_GAMEOBJECT
