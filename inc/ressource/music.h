/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** music.h
*/

#ifndef MUSIC_H
#define MUSIC_H

typedef struct music_prefab_s music_prefab_t;

#include "rpg.h"

typedef enum {
    MUSIC_TRAVEL,
    MUSIC_START,
    MUSIC_SAND,
    MUSIC_SNOW,
    MUSIC_CAVE,
    MUSIC_END
} music_id_e;

#include "csfml.h"

struct music_prefab_s {
    music_id_e id;
    char *name;
    char const *path;
};

extern const music_prefab_t musics_prefab[];


sfMusic **initialize_musics(void);
void play_music_reset(global_data_t *data, music_id_e id);
void play_music_wait(global_data_t *data, music_id_e id);
void stop_all_music(global_data_t *data);
void destroy_all_music(global_data_t *data);

#endif