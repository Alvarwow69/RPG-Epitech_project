/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** music_sounds_function
*/

#include "rpg.h"

void destroy_all_sounds(global_data_t *data)
{
    for (int ctr = 0; sounds_prefab[ctr].id != SOUND_END; ctr += 1)
        sfSound_destroy(data->ressources->sounds[ctr]);
}

void stop_all_sounds(global_data_t *data)
{
    for (int ctr = 0; sounds_prefab[ctr].id != SOUND_END; ctr += 1)
        sfSound_stop(data->ressources->sounds[ctr]);
}

void play_sound_reset(global_data_t *data, sound_id_e id)
{
    if (sfSound_getStatus(data->ressources->sounds[id]) == sfPlaying) {
        sfSound_stop(data->ressources->sounds[id]);
        sfSound_stop(data->ressources->sounds[id]);
    }
    if (sfSound_getStatus(data->ressources->sounds[id]) != sfPlaying) {
        sfSound_setLoop(data->ressources->sounds[id], 0);
        sfSound_play(data->ressources->sounds[id]);
    }
}

void play_sound_wait(global_data_t *data, sound_id_e id)
{
    if (sfSound_getStatus(data->ressources->sounds[id]) == sfPlaying)
        return;
    sfSound_play(data->ressources->sounds[id]);
}
