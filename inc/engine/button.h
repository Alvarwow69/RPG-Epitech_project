/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** all struct for the button
*/

#ifndef ENGINE_BUTTON
#define ENGINE_BUTTON

typedef struct button_s button_t;

#include "rpg.h"

struct button_s
{
    sfText *text;
    sfText *help_text;
    sfFloatRect rect;
    sfIntRect set_rect;
    sfIntRect hover_rect;
    sfIntRect click_rect;
    sfSprite *sprite;
    sfTexture *stand;
    sfTexture *hover;
    sfTexture *press;
    sfSprite *help_sprite;
    sfTransformable *h_transform;
    sfTransformable *p_transform;
    sfTransformable *text_pos;
    game_object_t *gameobject;
    float time;
    float help_time;
    int help;
    int is_clickable;
    int clicked;
    int pressed;
    void (*action)(global_data_t *, button_t *button);
    struct button_s *next;
};

/*Lib function*/

/*Get any button from specified name*/
button_t *button_get(global_data_t *data, char *name);

/*Create a new button with unique name*/
int button_create(global_data_t *data, char *name, char *node, sfTexture *texture);

/*Define a default texture from specified button*/
void button_set_texture(global_data_t *data, char *name, sfTexture *texture);

/*Define a position from specified button*/
void button_set_position(global_data_t *data, char *name, sfVector2f position);

/*Define a scale from specified button*/
void button_set_scale(global_data_t *data, char *name, sfVector2f scale);

/*Define a hover and press texture from specified button*/
void button_set_other_texture(global_data_t *data, char *name, sfTexture *hover, sfTexture *press);

/*Define pressed position from specified button*/
void button_set_press_position(global_data_t *data, char *name, sfVector2f pos);

/*Define a action from specified button*/
void button_set_action(global_data_t *data, char *name, void (*action)(global_data_t *, button_t *button));

/*Define a texture for help box from specified button*/
void button_set_help_texture(global_data_t *data, char *name, sfTexture *help);

/*Define if button is clickable from specified button*/
void button_set_clickable(global_data_t *data, char *name, int clickable);

/*Define all texture's button with specified tag*/
void define_texture_button(global_data_t *data, sfView *interface, button_t *button);

/* Define where help box appear for example (no other combination):
 *  1       1: x:0, y:1         4: x:0, y:-1
 * 2B3      2: x:1, y:0         B: button
 *  4       3: x:-1, y:0
 */
void button_set_help_position(global_data_t *data, char *name, sfVector2f pos);

void button_set_layer(global_data_t *data, char *name, int layer);

void button_set_text(global_data_t *data, char *name, char *str, sfFont *font);

void button_set_text_pos(global_data_t *data, char *name, sfVector2f pos);

void button_set_text_scale(global_data_t *data, char *name, int size);

void button_set_text_color(global_data_t *data, char *name, sfColor color);

void button_set_tex_rect(global_data_t *data, char *name, sfIntRect rect);

void button_set_click_rect(global_data_t *data, char *name, sfIntRect rect);

void button_set_hover_rect(global_data_t *data, char *name, sfIntRect rect);
void button_destroy(button_t *button);

int click_action(global_data_t *data, game_object_t *game);

/*DO NOT USE*/
button_t *init_button_struct(void);

void set_texture_button(button_t *button, sfTexture *texture, sfIntRect rect);
void click_button(button_t *button, sfTime time);

int check_button(global_data_t *data, sfVector2i position, sfView *interface, node_t *node);
void draw_help_button(global_data_t *data, button_t *button);
void draw_button(global_data_t *data, game_object_t *game, scene_t *scene);
void hover_button(global_data_t *data, button_t *button, sfVector2f pixel_pos, sfTime time);

#endif //ENGINE_BUTTON
