/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_test_key1
*/

#include "rpg.h"

char *test_key_f5_f13(sfKeyCode test)
{
    if (sfKeyF5 == test)
        return ("F5");
    if (sfKeyF6 == test)
        return ("F6");
    if (sfKeyF7 == test)
        return ("F7");
    if (sfKeyF8 == test)
        return ("F8");
    if (sfKeyF9 == test)
        return ("F9");
    if (sfKeyF10 == test)
        return ("F10");
    if (sfKeyF11 == test)
        return ("F11");
    if (sfKeyF12 == test)
        return ("F12");
    if (sfKeyF13 == test)
        return ("F13");
    return (NULL);
}

char *test_key_f14_count(sfKeyCode test)
{
    if (sfKeyF14 == test)
        return ("F14");
    if (sfKeyF15 == test)
        return ("F15");
    if (sfKeyPause == test)
        return ("PAUSE");
    if (sfKeyCount == test)
        return ("COUNT");
    return (NULL);
}

char *text_key_left_slash(sfKeyCode test)
{
    if (test_key_left_click_g(test) != NULL)
        return (test_key_left_click_g(test));
    if (test_key_h_p(test) != NULL)
        return (test_key_h_p(test));
    if (test_key_q_z(test) != NULL)
        return (test_key_q_z(test));
    if (test_key_0_8(test) != NULL)
        return (test_key_0_8(test));
    if (test_key_9_alt(test) != NULL)
        return (test_key_9_alt(test));
    if (test_key_sys_slash(test) != NULL)
        return (test_key_sys_slash(test));
    return (NULL);
}

char *text_key(global_data_t *data, char *name_ctrl)
{
    sfKeyCode test = get_controls(data, name_ctrl);

    if (text_key_left_slash(test) != NULL)
        return (text_key_left_slash(test));
    if (test_key_backslash_up(test) != NULL)
        return (test_key_backslash_up(test));
    if (test_key_down_divide(test) != NULL)
        return (test_key_down_divide(test));
    if (test_key_gauche_4(test) != NULL)
        return (test_key_gauche_4(test));
    if (test_key_5_f4(test) != NULL)
        return (test_key_5_f4(test));
    if (test_key_f5_f13(test) != NULL)
        return (test_key_f5_f13(test));
    if (test_key_f14_count(test) != NULL)
        return (test_key_f14_count(test));
    return ("bug");
}
