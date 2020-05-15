/*
** EPITECH PROJECT, 2020
** sound_option.h
** File description:
** 
*/

#ifndef MUL_RPG_2019_OPTION
#define MUL_RPG_2019_OPTION

#include "rpg.h"

void music_change_all_volume(global_data_t *data);
void sound_change_all_volume(global_data_t *data);
void setting_load(global_data_t *data);
void button_plus_sound(global_data_t *data, button_t *button);
void button_less_sound(global_data_t *data, button_t *button);
void button_less_music(global_data_t *data, button_t *button);
void button_plus_music(global_data_t *data, button_t *button);
void option_event(global_data_t *data);
void create_button_music(global_data_t *data);
void create_button_sounds(global_data_t *data);
void setting_main_menu(global_data_t *data);

#endif //MUL_RPG_2019_SOUND_OPTION
