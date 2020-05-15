/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** text_destroy.c
*/

#include "rpg.h"

void text_destroy(text_t *text)
{
    sfText_destroy(text->text);
    free(text);
}