/*
** EPITECH PROJECT, 2020
** option_action.c
** File description:
** 
*/

#include "rpg.h"

void button_plus_music(global_data_t *data, button_t *button)
{
    char *value = NULL;

    (void)button;
    data->music_volume += (data->music_volume < 100) ? 5 : 0;
    value = get_integer_nbr(data->music_volume);
    text_set_message(data, "setting_music_value", value);
    text_set_font(data, "setting_music_value"
    , data->ressources->fonts[FONT_MAIN]);
    music_change_all_volume(data);
}

void button_less_music(global_data_t *data, button_t *button)
{
    char *value = NULL;

    (void)button;
    data->music_volume -= (data->music_volume > 0) ? 5 : 0;
    value = get_integer_nbr(data->music_volume);
    text_set_message(data, "setting_music_value", value);
    text_set_font(data, "setting_music_value"
    , data->ressources->fonts[FONT_MAIN]);
    music_change_all_volume(data);
}

void button_less_sound(global_data_t *data, button_t *button)
{
    char *value = NULL;

    (void)button;
    data->sound_volume -= (data->sound_volume > 0) ? 5 : 0;
    value = get_integer_nbr(data->sound_volume);
    text_set_message(data, "setting_sound_value", value);
    text_set_font(data, "setting_sound_value"
    , data->ressources->fonts[FONT_MAIN]);
    music_change_all_volume(data);
}

void button_plus_sound(global_data_t *data, button_t *button)
{
    char *value = NULL;

    (void)button;
    data->sound_volume += (data->sound_volume <= 100) ? 5 : 0;
    value = get_integer_nbr(data->sound_volume);
    text_set_message(data, "setting_sound_value", value);
    text_set_font(data, "setting_sound_value"
    , data->ressources->fonts[FONT_MAIN]);
    music_change_all_volume(data);
}