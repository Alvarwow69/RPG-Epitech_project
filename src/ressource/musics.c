/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** musics.c
*/

#include "rpg.h"

const music_prefab_t musics_prefab[] = {
    {MUSIC_TRAVEL, "MUSIC_TRAVEL", "rsc/musics/travel.ogg"},
    {MUSIC_START, "MUSIC_START", "rsc/musics/start.ogg"},
    {MUSIC_SAND, "MUSIC_SAND", "rsc/musics/desert.ogg"},
    {MUSIC_SNOW, "MUSIC_SNOW", "rsc/musics/snow.ogg"},
    {MUSIC_CAVE, "MUSIC_CAVE", "rsc/musics/cave.ogg"},
    {MUSIC_END, NULL, NULL}
};

sfMusic **initialize_musics(void)
{
    sfMusic **musics = malloc(sizeof(sfMusic *) * MUSIC_END);

    if (musics == NULL)
        return (print_error("Error: Can't create music list\n"), NULL);
    for (int ctr = 0; musics_prefab[ctr].id != MUSIC_END; ctr += 1)
        musics[ctr] = sfMusic_createFromFile(musics_prefab[ctr].path);
    return (musics);
}