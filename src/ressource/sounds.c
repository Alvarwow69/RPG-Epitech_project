/*
** EPITECH PROJECT, 2019
** GameJAM_Mars_2019
** File description:
** initialize_sounds.c
*/

#include "rpg.h"

const sound_prefab_t sounds_prefab[] = {
    {SOUND_BUTTON_HOVER, "SOUND_BUTTON_HOVER", "rsc/sounds/button_hover.ogg"},
    {SOUND_CLIC, "SOUND_CLIC", "rsc/sounds/clic.ogg"},
    {SOUND_CLOSE_INV, "SOUND_CLOSE_INV", "rsc/sounds/close_inv.ogg"},
    {SOUND_OPEN_INV, "SOUND_OPEN_INV", "rsc/sounds/open_inv.ogg"},
    {SOUND_DESTROY_BLOC, "SOUND_DESTROY_BLOC", "rsc/sounds/bloc_destroy.ogg"},
    {SOUND_OPEN_QUEST, "SOUND_OPEN_QUEST", "rsc/sounds/close_quest.ogg"},
    {SOUND_CLOSE_QUEST, "SOUND_CLOSE_QUEST", "rsc/sounds/open_quest.ogg"},
    {SOUND_UP_STAT, "SOUND_UP_STAT", "rsc/sounds/up_stat.ogg"},
    {SOUND_ATTACK_SWORD, "SOUND_ATTACK_SWORD", "rsc/sounds/attack_sword.ogg"},
    {SOUND_OCEAN, "SOUND_OCEAN", "rsc/sounds/ocean.ogg"},
    {SOUND_MONSTER_ATTACK, "SOUND_MONSTER_ATTACK",
     "rsc/sounds/monster_attack.ogg"},
    {SOUND_MONSTER_DISP, "SOUND_MONSTER_DISP", "rsc/sounds/monster_disp.ogg"},
    {SOUND_END, NULL, NULL}
};

sfSoundBuffer **initialize_buffers(void)
{
    sfSoundBuffer **buffers = malloc(sizeof(sfSoundBuffer *) * SOUND_END);

    if (buffers == NULL)
        return (print_error("Error: Can't create sound buffer list\n"), NULL);
    for (int ctr = 0; sounds_prefab[ctr].id != SOUND_END; ctr += 1)
        buffers[ctr] = sfSoundBuffer_createFromFile(sounds_prefab[ctr].path);
    return (buffers);
}

sfSound **initialize_sounds(sfSoundBuffer **buffers)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * SOUND_END);

    if (sounds == NULL)
        return (print_error("Error: Can't create sound list\n"), NULL);
    for (int ctr = 0; ctr < SOUND_END; ctr += 1) {
        sounds[ctr] = sfSound_create();
        sfSound_setBuffer(sounds[ctr], buffers[ctr]);
    }
    return (sounds);
}