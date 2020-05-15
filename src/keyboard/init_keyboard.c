/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_keyboard
*/

#include "rpg.h"

void init_keyboard(global_data_t *data)
{
    keyboard_t *new = malloc(sizeof(keyboard_t));

    init_keyboard_a_t(new);
    init_keyboard_u_lalt(new);
    init_keyboard_lsys_back(new);
    init_keyboard_tab_pad4(new);
    new->pause = 0;
    new->count = 0;
    new->left_click = 0;
    new->right_click = 0;
    new->left_click = 0;
    new->scroll_up = 0;
    new->scroll_down = 0;
    data->key = new;
}