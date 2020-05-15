/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** music_function
*/

#include "rpg.h"

void destroy_all_music(global_data_t *data)
{
    for (int ctr = 0; musics_prefab[ctr].id != MUSIC_END; ctr += 1)
        sfMusic_destroy(data->ressources->musics[ctr]);
}

void stop_all_music(global_data_t *data)
{
    for (int ctr = 0; musics_prefab[ctr].id != MUSIC_END; ctr += 1)
        sfMusic_stop(data->ressources->musics[ctr]);
}

void play_music_reset(global_data_t *data, music_id_e id)
{
    if (sfMusic_getStatus(data->ressources->musics[id]) == sfPlaying) {
        sfMusic_stop(data->ressources->musics[id]);
        sfMusic_stop(data->ressources->musics[id]);
    }
    if (sfMusic_getStatus(data->ressources->musics[id]) != sfPlaying) {
        sfMusic_setLoop(data->ressources->musics[id], 1);
        sfMusic_play(data->ressources->musics[id]);
    }
}

void play_music_wait(global_data_t *data, music_id_e id)
{
    if (sfMusic_getStatus(data->ressources->musics[id]) == sfPlaying)
        return;
    sfMusic_play(data->ressources->musics[id]);
}