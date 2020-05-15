/*
** EPITECH PROJECT, 2019
** anim
** File description:
** global_data.h
*/

#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include "csfml.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

// Gestion du temps
typedef struct time_s {
    float actual;
    float last;
    float dif;
} game_time_t;

// Gestion de la texture d'un object
typedef struct texture_s {
    sfIntRect tile_rect;
    sfVector2u tile_size;
    sfVector2u txt_size;
    sfVector2f scale;
    sfBool repeat;
} texture_t;

// Gestion de l'animation de la texture
typedef struct object_animation {
    bool is_loop;
    bool is_anim;
    float loop_time;
    float anim_time;
    int rect_pos;
    int rect_move;
    int rect_max;
    game_time_t *time;
} anim_t;

typedef struct animation_ref_s {
    float anim_time;
    float loop_time;
    int rect_pos;
    int rect_max;
} anim_ref_t;

typedef struct {
    sfVector2f pos;
    float loop_time;
    game_time_t *time;
} target_t;

/* Create a game_time_t structure */
game_time_t *game_time_create(void);

/* Create a anim_t structure */
anim_t *animation_create(texture_t *txt, float anim_time
                        , float loop_time, sfVector2i pos_and_max);
void animation_destroy(anim_t *anim);

/* Create a texture_t structure */
texture_t *texture_create(sfTexture *txt, bool repeat
                         , sfVector2f scale, sfIntRect tile_rect);

/* Reset is_anim of the given animation as true */
void animation_reset(anim_t *anim);

/* Function to animate a sprite */
void texture_time_gestion(anim_t *anim, sfClock *clock, texture_t *txt);

/* Function to move a object or node to a target */
sfVector2f move_transform_to_target
(sfTransformable *transform, target_t *target, sfClock *clock, float cel);

/* Set a texture rect to the given spr corresponding to the given pourcent

rect is the initial sfIntRect of the sprite compared to the sprite texture

direction can take four value :
-   "top"     to change rect.top
-   "left"   to change rect.left
-   "bottom" to change rect.height
-   "right"  to change rect.width */
void texture_rect_percent(sfSprite *spr, sfIntRect rect
                         , float percent, char *direction);

#endif