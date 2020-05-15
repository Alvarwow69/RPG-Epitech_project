/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** sound.h
*/

#ifndef SOUND_H
#define SOUND_H

typedef struct sound_prefab_s sound_prefab_t;

typedef enum {
    SOUND_BUTTON_HOVER,
    SOUND_CLIC,
    SOUND_OPEN_INV,
    SOUND_CLOSE_INV,
    SOUND_DESTROY_BLOC,
    SOUND_OPEN_QUEST,
    SOUND_CLOSE_QUEST,
    SOUND_UP_STAT,
    SOUND_ATTACK_SWORD,
    SOUND_OCEAN,
    SOUND_MONSTER_ATTACK,
    SOUND_MONSTER_DISP,
    SOUND_END
} sound_id_e;

#include "csfml.h"

struct sound_prefab_s {
    sound_id_e id;
    char *name;
    char const *path;
};

extern const sound_prefab_t sounds_prefab[];

sfSoundBuffer **initialize_buffers(void);

sfSound **initialize_sounds(sfSoundBuffer **soundbuffers);
void play_sound_reset(global_data_t *data, sound_id_e id);
void play_sound_wait(global_data_t *data, sound_id_e id);
void stop_all_sounds(global_data_t *data);
void destroy_all_sounds(global_data_t *data);

#endif