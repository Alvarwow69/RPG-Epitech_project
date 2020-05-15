/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** download_ressources.h
*/

#ifndef DOWNLOAD_RESSOURCES_H
#define DOWNLOAD_RESSOURCES_H

typedef struct download_rsc_prefab_s download_rsc_prefab_t;

typedef enum {
    DL_RSC_1,
    DL_RSC_2,
    DL_RSC_END
} download_rsc_e;

#include "csfml.h"

struct download_rsc_prefab_s {
    download_rsc_e id;
    char const *name;
    char const *path; // In project
};

extern const sfIpAddress dl_ip;
extern const unsigned short dl_port;
extern const download_rsc_prefab_t download_rsc_prefab[];

#endif