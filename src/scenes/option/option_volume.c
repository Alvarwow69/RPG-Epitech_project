/*
** EPITECH PROJECT, 2020
** option_volume.c
** File description:
** 
*/

#include "rpg.h"

void music_change_all_volume(global_data_t *data)
{
    for (int i = 0; i < MUSIC_END; i++)
        sfMusic_setVolume(data->ressources->musics[i],
        (float)data->music_volume);
}

void sound_change_all_volume(global_data_t *data)
{
    for (int i = 0; i < SOUND_END; i++)
        sfSound_setVolume(data->ressources->sounds[i],
        (float)data->sound_volume);
}