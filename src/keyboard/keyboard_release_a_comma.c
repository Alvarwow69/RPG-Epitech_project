/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_pressed
*/

#include "rpg.h"

void key_released_a_j(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyA)
        data->key->a = 0;
    if (event.key.code == sfKeyB)
        data->key->b = 0;
    if (event.key.code == sfKeyC)
        data->key->c = 0;
    if (event.key.code == sfKeyD)
        data->key->d = 0;
    if (event.key.code == sfKeyE)
        data->key->e = 0;
    if (event.key.code == sfKeyF)
        data->key->f = 0;
    if (event.key.code == sfKeyG)
        data->key->g = 0;
    if (event.key.code == sfKeyH)
        data->key->h = 0;
    if (event.key.code == sfKeyI)
        data->key->i = 0;
    if (event.key.code == sfKeyJ)
        data->key->j = 0;
}

void key_released_k_t(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyK)
        data->key->k = 0;
    if (event.key.code == sfKeyL)
        data->key->l1 = 0;
    if (event.key.code == sfKeyM)
        data->key->m = 0;
    if (event.key.code == sfKeyN)
        data->key->n = 0;
    if (event.key.code == sfKeyO)
        data->key->o1 = 0;
    if (event.key.code == sfKeyP)
        data->key->p = 0;
    if (event.key.code == sfKeyQ)
        data->key->q = 0;
    if (event.key.code == sfKeyR)
        data->key->r = 0;
    if (event.key.code == sfKeyS)
        data->key->s = 0;
    if (event.key.code == sfKeyT)
        data->key->t = 0;
}

void key_released_u_num3(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyU)
        data->key->u = 0;
    if (event.key.code == sfKeyV)
        data->key->v = 0;
    if (event.key.code == sfKeyW)
        data->key->w = 0;
    if (event.key.code == sfKeyX)
        data->key->x = 0;
    if (event.key.code == sfKeyY)
        data->key->y = 0;
    if (event.key.code == sfKeyZ)
        data->key->z = 0;
    if (event.key.code == sfKeyNum0)
        data->key->num0 = 0;
    if (event.key.code == sfKeyNum1)
        data->key->num1 = 0;
    if (event.key.code == sfKeyNum2)
        data->key->num2 = 0;
    if (event.key.code == sfKeyNum3)
        data->key->num3 = 0;
}

void key_released_num4_lalt(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyNum4)
        data->key->num4 = 0;
    if (event.key.code == sfKeyNum5)
        data->key->num5 = 0;
    if (event.key.code == sfKeyNum6)
        data->key->num6 = 0;
    if (event.key.code == sfKeyNum7)
        data->key->num7 = 0;
    if (event.key.code == sfKeyNum8)
        data->key->num8 = 0;
    if (event.key.code == sfKeyNum9)
        data->key->num9 = 0;
    if (event.key.code == sfKeyEscape)
        data->key->esc = 0;
    if (event.key.code == sfKeyLControl)
        data->key->lctrl = 0;
    if (event.key.code == sfKeyLShift)
        data->key->lmaj = 0;
    if (event.key.code == sfKeyLAlt)
        data->key->lalt = 0;
}

void key_released_lsystem_comma(sfEvent event, global_data_t *data)
{
    if (event.key.code == sfKeyLSystem)
        data->key->lsys = 0;
    if (event.key.code == sfKeyRControl)
        data->key->rctrl = 0;
    if (event.key.code == sfKeyRShift)
        data->key->rmaj = 0;
    if (event.key.code == sfKeyRAlt)
        data->key->ralt = 0;
    if (event.key.code == sfKeyRSystem)
        data->key->rsys = 0;
    if (event.key.code == sfKeyMenu)
        data->key->menu = 0;
    if (event.key.code == sfKeyLBracket)
        data->key->lbracket = 0;
    if (event.key.code == sfKeyRBracket)
        data->key->rbracket = 0;
    if (event.key.code == sfKeySemiColon)
        data->key->semicolon = 0;
    if (event.key.code == sfKeyComma)
        data->key->comma = 0;
}