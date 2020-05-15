/*
** EPITECH PROJECT, 2020
** option_create_button.c
** File description:
** 
*/

#include "rpg.h"

static void create_button_music_less(global_data_t *data)
{
    button_create(data, "button_music_less", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "button_music_less",
    data->ressources->textures[BUTTON_HOVER]
    , data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "button_music_less", "-",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "button_music_less", (sfVector2f){600, 300});
    button_set_text_pos(data, "button_music_less", (sfVector2f){14, 5});
    button_set_text_color(data, "button_music_less", sfBlack);
    button_set_action(data, "button_music_less", &button_less_music);
}

void create_button_music(global_data_t *data)
{
    button_create(data, "button_music_plus", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "button_music_plus",
    data->ressources->textures[BUTTON_HOVER]
    , data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "button_music_plus", "+",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "button_music_plus", (sfVector2f){300, 300});
    button_set_text_pos(data, "button_music_plus", (sfVector2f){14, 5});
    button_set_text_color(data, "button_music_plus", sfBlack);
    button_set_action(data, "button_music_plus", &button_plus_music);
    button_set_press_position(data, " button_music_plus", (sfVector2f){0, 10});
    create_button_music_less(data);
}

static void create_button_sounds_les(global_data_t *data)
{
    button_create(data, "button_sound_less", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "button_sound_less",
    data->ressources->textures[BUTTON_HOVER]
    , data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "button_sound_less", "-",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "button_sound_less", (sfVector2f){1600, 300});
    button_set_text_pos(data, "button_sound_less", (sfVector2f){14, 5});
    button_set_text_color(data, "button_sound_less", sfBlack);
    button_set_action(data, "button_sound_less", &button_less_sound);
}

void create_button_sounds(global_data_t *data)
{
    button_create(data, "button_sound_plus", "setting",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "button_sound_plus",
    data->ressources->textures[BUTTON_HOVER]
    , data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "button_sound_plus", "+",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "button_sound_plus", (sfVector2f){1300, 300});
    button_set_text_pos(data, "button_sound_plus", (sfVector2f){14, 5});
    button_set_text_color(data, "button_sound_plus", sfBlack);
    button_set_action(data, "button_sound_plus", &button_plus_sound);
    create_button_sounds_les(data);
}