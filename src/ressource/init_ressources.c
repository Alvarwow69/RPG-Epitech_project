/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** init_ressources.c
*/

#include "rpg.h"

ressources_t *init_ressources(void)
{
    ressources_t *ressources = malloc(sizeof(ressources_t));

    ressources->fonts = initialize_fonts();
    ressources->musics = initialize_musics();
    ressources->soundbuffers = initialize_buffers();
    ressources->sounds = initialize_sounds(ressources->soundbuffers);
    ressources->textures = initialize_textures();
    return (ressources);
}