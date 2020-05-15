/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_pressed_A_COMMA
*/

#include "rpg.h"

void key_pressed_a_j(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyA)
        data->key->a = 1;
    if (event.key.code == sfKeyB)
        data->key->b = 1;
    if (event.key.code == sfKeyC)
        data->key->c = 1;
    if (event.key.code == sfKeyD)
        data->key->d = 1;
    if (event.key.code == sfKeyE)
        data->key->e = 1;
    if (event.key.code == sfKeyF)
        data->key->f = 1;
    if (event.key.code == sfKeyG)
        data->key->g = 1;
    if (event.key.code == sfKeyH)
        data->key->h = 1;
    if (event.key.code == sfKeyI)
        data->key->i = 1;
    if (event.key.code == sfKeyJ)
        data->key->j = 1;
}

void key_pressed_k_t(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyK)
        data->key->k = 1;
    if (event.key.code == sfKeyL)
        data->key->l1 = 1;
    if (event.key.code == sfKeyM)
        data->key->m = 1;
    if (event.key.code == sfKeyN)
        data->key->n = 1;
    if (event.key.code == sfKeyO)
        data->key->o1 = 1;
    if (event.key.code == sfKeyP)
        data->key->p = 1;
    if (event.key.code == sfKeyQ)
        data->key->q = 1;
    if (event.key.code == sfKeyR)
        data->key->r = 1;
    if (event.key.code == sfKeyS)
        data->key->s = 1;
    if (event.key.code == sfKeyT)
        data->key->t = 1;
}

void key_pressed_u_num3(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyU)
        data->key->u = 1;
    if (event.key.code == sfKeyV)
        data->key->v = 1;
    if (event.key.code == sfKeyW)
        data->key->w = 1;
    if (event.key.code == sfKeyX)
        data->key->x = 1;
    if (event.key.code == sfKeyY)
        data->key->y = 1;
    if (event.key.code == sfKeyZ)
        data->key->z = 1;
    if (event.key.code == sfKeyNum0)
        data->key->num0 = 1;
    if (event.key.code == sfKeyNum1)
        data->key->num1 = 1;
    if (event.key.code == sfKeyNum2)
        data->key->num2 = 1;
    if (event.key.code == sfKeyNum3)
        data->key->num3 = 1;
}

void key_pressed_num4_lalt(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyNum4)
        data->key->num4 = 1;
    if (event.key.code == sfKeyNum5)
        data->key->num5 = 1;
    if (event.key.code == sfKeyNum6)
        data->key->num6 = 1;
    if (event.key.code == sfKeyNum7)
        data->key->num7 = 1;
    if (event.key.code == sfKeyNum8)
        data->key->num8 = 1;
    if (event.key.code == sfKeyNum9)
        data->key->num9 = 1;
    if (event.key.code == sfKeyEscape)
        data->key->esc = 1;
    if (event.key.code == sfKeyLControl)
        data->key->lctrl = 1;
    if (event.key.code == sfKeyLShift)
        data->key->lmaj = 1;
    if (event.key.code == sfKeyLAlt)
        data->key->lalt = 1;
}

void key_pressed_lsystem_comma(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyLSystem)
        data->key->lsys = 1;
    if (event.key.code == sfKeyRControl)
        data->key->rctrl = 1;
    if (event.key.code == sfKeyRShift)
        data->key->rmaj = 1;
    if (event.key.code == sfKeyRAlt)
        data->key->ralt = 1;
    if (event.key.code == sfKeyRSystem)
        data->key->rsys = 1;
    if (event.key.code == sfKeyMenu)
        data->key->menu = 1;
    if (event.key.code == sfKeyLBracket)
        data->key->lbracket = 1;
    if (event.key.code == sfKeyRBracket)
        data->key->rbracket = 1;
    if (event.key.code == sfKeySemiColon)
        data->key->semicolon = 1;
    if (event.key.code == sfKeyComma)
        data->key->comma = 1;
}