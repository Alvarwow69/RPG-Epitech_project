/*
** EPITECH PROJECT, 2020
** map_editor.h
** File description:
** 
*/

#ifndef MUL_RPG_2019_MAP_EDITOR
#define MUL_RPG_2019_MAP_EDITOR

#include "rpg.h"

void editor_main_action(global_data_t *data, button_t *button);
void editor_load(global_data_t *data);
void editor_event(global_data_t *data);
void add_tile(global_data_t *data, sfVector2i position, sfView *interface);
void editor_selector_action(global_data_t *data, button_t *button);
void editor_change_bloc(global_data_t *data, button_t *button);
void create_button_selection(global_data_t *data);
void editor_change(global_data_t *data, button_t *button);
void editor_remove(global_data_t *data, button_t *button);
void editor_b_background(global_data_t *data, button_t *button);
void editor_unload(global_data_t *data);
void add_ore(global_data_t *data, char *name, game_object_t *game);
void add_block(global_data_t *data, char *name);
void change_tile(global_data_t *data, game_object_t *game);
void check_size(global_data_t *data, sfVector2i pos);
void create_button_menu(global_data_t *data);
void create_button_selection(global_data_t *data);
void editor_hide(global_data_t *data, button_t *button);
void create_new_tile(global_data_t *data, char *name, sfVector2i tile_pos, int layer);
#endif //MUL_RPG_2019_MAP_EDITOR
