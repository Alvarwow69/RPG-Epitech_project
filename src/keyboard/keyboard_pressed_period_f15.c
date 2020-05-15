/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_pressed_period_f15
*/

#include "rpg.h"

void key_pressed_period_back(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyPeriod)
        data->key->period = 1;
    if (event.key.code == sfKeyQuote)
        data->key->quote = 1;
    if (event.key.code == sfKeySlash)
        data->key->slash = 1;
    if (event.key.code == sfKeyBackSlash)
        data->key->bslash = 1;
    if (event.key.code == sfKeyTilde)
        data->key->tilde = 1;
    if (event.key.code == sfKeyEqual)
        data->key->equal = 1;
    if (event.key.code == sfKeyDash)
        data->key->dash = 1;
    if (event.key.code == sfKeySpace)
        data->key->space = 1;
    if (event.key.code == sfKeyReturn)
        data->key->kreturn = 1;
    if (event.key.code == sfKeyBack)
        data->key->back = 1;
}

void key_pressed_tab_mult(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyTab)
        data->key->tab = 1;
    if (event.key.code == sfKeyPageUp)
        data->key->pageup = 1;
    if (event.key.code == sfKeyPageDown)
        data->key->pagedown = 1;
    if (event.key.code == sfKeyEnd)
        data->key->end = 1;
    if (event.key.code == sfKeyHome)
        data->key->home = 1;
    if (event.key.code == sfKeyInsert)
        data->key->insert = 1;
    if (event.key.code == sfKeyDelete)
        data->key->del = 1;
    if (event.key.code == sfKeyAdd)
        data->key->add = 1;
    if (event.key.code == sfKeySubtract)
        data->key->sub = 1;
    if (event.key.code == sfKeyMultiply)
        data->key->mult = 1;
}

void key_pressed_div_pad4(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyDivide)
        data->key->div = 1;
    if (event.key.code == sfKeyLeft)
        data->key->left = 1;
    if (event.key.code == sfKeyRight)
        data->key->right = 1;
    if (event.key.code == sfKeyUp)
        data->key->up = 1;
    if (event.key.code == sfKeyDown)
        data->key->down = 1;
    if (event.key.code == sfKeyNumpad0)
        data->key->pad_0 = 1;
    if (event.key.code == sfKeyNumpad1)
        data->key->pad_1 = 1;
    if (event.key.code == sfKeyNumpad2)
        data->key->pad_2 = 1;
    if (event.key.code == sfKeyNumpad3)
        data->key->pad_3 = 1;
    if (event.key.code == sfKeyNumpad4)
        data->key->pad_4 = 1;
}

void key_pressed_pad5_f5(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyNumpad5)
        data->key->pad_5 = 1;
    if (event.key.code == sfKeyNumpad6)
        data->key->pad_6 = 1;
    if (event.key.code == sfKeyNumpad7)
        data->key->pad_7 = 1;
    if (event.key.code == sfKeyNumpad8)
        data->key->pad_8 = 1;
    if (event.key.code == sfKeyNumpad9)
        data->key->pad_9 = 1;
    if (event.key.code == sfKeyF1)
        data->key->f1 = 1;
    if (event.key.code == sfKeyF2)
        data->key->f2 = 1;
    if (event.key.code == sfKeyF3)
        data->key->f3 = 1;
    if (event.key.code == sfKeyF4)
        data->key->f4 = 1;
    if (event.key.code == sfKeyF5)
        data->key->f5 = 1;
}

void key_pressed_f6_f15(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyF6)
        data->key->f6 = 1;
    if (event.key.code == sfKeyF7)
        data->key->f7 = 1;
    if (event.key.code == sfKeyF8)
        data->key->f8 = 1;
    if (event.key.code == sfKeyF9)
        data->key->f9 = 1;
    if (event.key.code == sfKeyF10)
        data->key->f10 = 1;
    if (event.key.code == sfKeyF11)
        data->key->f11 = 1;
    if (event.key.code == sfKeyF12)
        data->key->f12 = 1;
    if (event.key.code == sfKeyF13)
        data->key->f13 = 1;
    if (event.key.code == sfKeyF14)
        data->key->f14 = 1;
    if (event.key.code == sfKeyF15)
        data->key->f15 = 1;
}
