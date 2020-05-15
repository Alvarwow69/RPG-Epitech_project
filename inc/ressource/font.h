/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** font.h
*/

#ifndef FONT_H
#define FONT_H

typedef struct font_prefab_s font_prefab_t;

typedef enum {
    FONT_MAIN,
    STARFONT,
    FONT_END
} font_id_e;

#include "csfml.h"

struct font_prefab_s {
    font_id_e id;
    char const *path;
};

extern const font_prefab_t fonts_prefab[];

sfFont **initialize_fonts(void);

#endif