/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_release_PERIOD_F15
*/

#include "rpg.h"

void key_released_period_back(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyPeriod)
        data->key->period = 0;
    if (event.key.code == sfKeyQuote)
        data->key->quote = 0;
    if (event.key.code == sfKeySlash)
        data->key->slash = 0;
    if (event.key.code == sfKeyBackSlash)
        data->key->bslash = 0;
    if (event.key.code == sfKeyTilde)
        data->key->tilde = 0;
    if (event.key.code == sfKeyEqual)
        data->key->equal = 0;
    if (event.key.code == sfKeyDash)
        data->key->dash = 0;
    if (event.key.code == sfKeySpace)
        data->key->space = 0;
    if (event.key.code == sfKeyReturn)
        data->key->kreturn = 0;
    if (event.key.code == sfKeyBack)
        data->key->back = 0;
}

void key_released_tab_mult(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyTab)
        data->key->tab = 0;
    if (event.key.code == sfKeyPageUp)
        data->key->pageup = 0;
    if (event.key.code == sfKeyPageDown)
        data->key->pagedown = 0;
    if (event.key.code == sfKeyEnd)
        data->key->end = 0;
    if (event.key.code == sfKeyHome)
        data->key->home = 0;
    if (event.key.code == sfKeyInsert)
        data->key->insert = 0;
    if (event.key.code == sfKeyDelete)
        data->key->del = 0;
    if (event.key.code == sfKeyAdd)
        data->key->add = 0;
    if (event.key.code == sfKeySubtract)
        data->key->sub = 0;
    if (event.key.code == sfKeyMultiply)
        data->key->mult = 0;
}

void key_released_div_pad4(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyDivide)
        data->key->div = 0;
    if (event.key.code == sfKeyLeft)
        data->key->left = 0;
    if (event.key.code == sfKeyRight)
        data->key->right = 0;
    if (event.key.code == sfKeyUp)
        data->key->up = 0;
    if (event.key.code == sfKeyDown)
        data->key->down = 0;
    if (event.key.code == sfKeyNumpad0)
        data->key->pad_0 = 0;
    if (event.key.code == sfKeyNumpad1)
        data->key->pad_1 = 0;
    if (event.key.code == sfKeyNumpad2)
        data->key->pad_2 = 0;
    if (event.key.code == sfKeyNumpad3)
        data->key->pad_3 = 0;
    if (event.key.code == sfKeyNumpad4)
        data->key->pad_4 = 0;
}

void key_released_pad5_f5(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyNumpad5)
        data->key->pad_5 = 0;
    if (event.key.code == sfKeyNumpad6)
        data->key->pad_6 = 0;
    if (event.key.code == sfKeyNumpad7)
        data->key->pad_7 = 0;
    if (event.key.code == sfKeyNumpad8)
        data->key->pad_8 = 0;
    if (event.key.code == sfKeyNumpad9)
        data->key->pad_9 = 0;
    if (event.key.code == sfKeyF1)
        data->key->f1 = 0;
    if (event.key.code == sfKeyF2)
        data->key->f2 = 0;
    if (event.key.code == sfKeyF3)
        data->key->f3 = 0;
    if (event.key.code == sfKeyF4)
        data->key->f4 = 0;
    if (event.key.code == sfKeyF5)
        data->key->f5 = 0;
}

void key_released_f6_f15(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyF6)
        data->key->f6 = 0;
    if (event.key.code == sfKeyF7)
        data->key->f7 = 0;
    if (event.key.code == sfKeyF8)
        data->key->f8 = 0;
    if (event.key.code == sfKeyF9)
        data->key->f9 = 0;
    if (event.key.code == sfKeyF10)
        data->key->f10 = 0;
    if (event.key.code == sfKeyF11)
        data->key->f11 = 0;
    if (event.key.code == sfKeyF12)
        data->key->f12 = 0;
    if (event.key.code == sfKeyF13)
        data->key->f13 = 0;
    if (event.key.code == sfKeyF14)
        data->key->f14 = 0;
    if (event.key.code == sfKeyF15)
        data->key->f15 = 0;
}