/*
** EPITECH PROJECT, 2019
** Test
** File description:
** text.c
*/

#include "rpg.h"

const font_prefab_t fonts_prefab[] = {
        {FONT_MAIN, "rsc/font.ttf"},
        {STARFONT, "rsc/StarFont.ttf"},
        {FONT_END, NULL}
};

sfFont **initialize_fonts(void)
{
    sfFont **fonts = malloc(sizeof(sfFont *) * (FONT_END));

    if (fonts == NULL)
        return (print_error("Error: Can't create font list\n"), NULL);
    for (int ctr = 0; ctr < FONT_END; ctr += 1)
        fonts[ctr] = sfFont_createFromFile(fonts_prefab[ctr].path);
    return (fonts);
}