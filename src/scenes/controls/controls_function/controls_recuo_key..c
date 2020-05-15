/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_test_key2
*/

#include "rpg.h"

sfKeyCode recup_key(global_data_t *data)
{
    (void)data;
    int i = 0;
    while (sfMouse_isButtonPressed(sfMouseLeft));

    while (sfKeyboard_isKeyPressed(i) == 0) {
        i ++;
        if (i == sfKeyCount)
            i = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return (-2);
            break;
        }
        if (sfMouse_isButtonPressed(sfMouseRight)) {
            return (-3);
            break;
        }
    }
    for (int i = 0; i != sfKeyCount; i++)
        if (sfKeyboard_isKeyPressed(i))
            return (i);
    return (-1);
}
