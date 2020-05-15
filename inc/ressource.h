/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** ressource.h
*/

#ifndef RESSOURCE_H
#define RESSOURCE_H

typedef struct ressources_s ressources_t;

#include "font.h"
#include "music.h"
#include "sound.h"
#include "texture.h"
#include "download_ressources.h"
#include "tile_map.h"

struct ressources_s {
    sfFont **fonts;
    sfSoundBuffer **soundbuffers;
    sfSound **sounds;
    sfTexture **textures;
    sfMusic **musics;
};

ressources_t *init_ressources(void);

#endif