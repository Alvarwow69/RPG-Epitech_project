/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** test_key_left_click_alt
*/

#include "rpg.h"

char *test_key_left_click_g(sfKeyCode test)
{
    if (-2 == test)
        return ("Left Click");
    if (-3 == test)
        return ("Right Click");
    if (sfKeyA == test)
        return ("A");
    if (sfKeyB == test)
        return ("B");
    if (sfKeyC == test)
        return ("C");
    if (sfKeyD == test)
        return ("D");
    if (sfKeyE == test)
        return ("E");
    if (sfKeyF == test)
        return ("F");
    if (sfKeyG == test)
        return ("G");
    return (NULL);
}

char *test_key_h_p(sfKeyCode test)
{
    if (sfKeyH == test)
        return ("H");
    if (sfKeyI == test)
        return ("I");
    if (sfKeyJ == test)
        return ("J");
    if (sfKeyK == test)
        return ("K");
    if (sfKeyL == test)
        return ("L");
    if (sfKeyM == test)
        return ("M");
    if (sfKeyN == test)
        return ("N");
    if (sfKeyO == test)
        return ("O");
    if (sfKeyP == test)
        return ("P");
    return (NULL);
}

char *test_key_q_z(sfKeyCode test)
{
    if (sfKeyQ == test)
        return ("Q");
    if (sfKeyR == test)
        return ("R");
    if (sfKeyS == test)
        return ("S");
    if (sfKeyT == test)
        return ("T");
    if (sfKeyU == test)
        return ("U");
    if (sfKeyV == test)
        return ("V");
    if (sfKeyW == test)
        return ("W");
    if (sfKeyY == test)
        return ("Y");
    if (sfKeyZ == test)
        return ("Z");
    return (NULL);
}

char *test_key_0_8(sfKeyCode test)
{
    if (sfKeyNum0 == test)
        return ("0");
    if (sfKeyNum1 == test)
        return ("1");
    if (sfKeyNum2 == test)
        return ("2");
    if (sfKeyNum3 == test)
        return ("3");
    if (sfKeyNum4 == test)
        return ("4");
    if (sfKeyNum5 == test)
        return ("5");
    if (sfKeyNum6 == test)
        return ("6");
    if (sfKeyNum7 == test)
        return ("7");
    if (sfKeyNum8 == test)
        return ("8");
    return (NULL);
}

char *test_key_9_alt(sfKeyCode test)
{
    if (sfKeyNum9 == test)
        return ("9");
    if (sfKeyEscape == test)
        return ("ESC");
    if (sfKeyLControl == test)
        return ("CTRl");
    if (sfKeyLShift == test)
        return ("SHIFT");
    if (sfKeyLAlt == test)
        return ("ALT");
    if (sfKeyLSystem == test)
        return ("SYST");
    if (sfKeyRControl == test)
        return ("CTRL");
    if (sfKeyRShift == test)
        return ("SHIFT");
    if (sfKeyRAlt == test)
        return ("ALT");
    return (NULL);
}
