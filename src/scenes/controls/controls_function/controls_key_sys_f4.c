/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_key_sys_f4
*/

#include "rpg.h"

char *test_key_sys_slash(sfKeyCode test)
{
    if (sfKeyRSystem == test)
        return ("SYST");
    if (sfKeyMenu == test)
        return ("MENU");
    if (sfKeyLBracket == test)
        return ("[");
    if (sfKeyRBracket == test)
        return ("]");
    if (sfKeySemiColon == test)
        return (";");
    if (sfKeyComma == test)
        return (",");
    if (sfKeyPeriod == test)
        return (".");
    if (sfKeyQuote == test)
        return ("'");
    if (sfKeySlash == test)
        return ("/");
    return (NULL);
}

char *test_key_backslash_up(sfKeyCode test)
{
    if (sfKeyBackSlash == test)
        return ("\\");
    if (sfKeyTilde == test)
        return ("~");
    if (sfKeyEqual == test)
        return ("=");
    if (sfKeyDash == test)
        return ("-");
    if (sfKeySpace == test)
        return ("' '");
    if (sfKeyReturn == test)
        return ("RETURN");
    if (sfKeyBack == test)
        return ("BACK");
    if (sfKeyTab == test)
        return ("TAB");
    if (sfKeyPageUp == test)
        return ("UP");
    return (NULL);
}

char *test_key_down_divide(sfKeyCode test)
{
    if (sfKeyPageDown == test)
        return ("DOWN");
    if (sfKeyEnd == test)
        return ("END");
    if (sfKeyHome == test)
        return ("HOME");
    if (sfKeyInsert == test)
        return ("INSERT");
    if (sfKeyDelete == test)
        return ("DEL");
    if (sfKeyAdd == test)
        return ("+");
    if (sfKeySubtract == test)
        return ("-");
    if (sfKeyMultiply == test)
        return ("*");
    if (sfKeyDivide == test)
        return ("/");
    return (NULL);
}

char *test_key_gauche_4(sfKeyCode test)
{
    if (sfKeyLeft == test)
        return ("GAUCHE");
    if (sfKeyRight == test)
        return ("DROITE");
    if (sfKeyUp == test)
        return ("HAUT");
    if (sfKeyDown == test)
        return ("BAS");
    if (sfKeyNumpad0 == test)
        return ("0");
    if (sfKeyNumpad1 == test)
        return ("1");
    if (sfKeyNumpad2 == test)
        return ("2");
    if (sfKeyNumpad3 == test)
        return ("3");
    if (sfKeyNumpad4 == test)
        return ("4");
    return (NULL);
}

char *test_key_5_f4(sfKeyCode test)
{
    if (sfKeyNumpad5 == test)
        return ("5");
    if (sfKeyNumpad6 == test)
        return ("6");
    if (sfKeyNumpad7 == test)
        return ("7");
    if (sfKeyNumpad8 == test)
        return ("8");
    if (sfKeyNumpad9 == test)
        return ("9");
    if (sfKeyF1 == test)
        return ("F1");
    if (sfKeyF2 == test)
        return ("F2");
    if (sfKeyF3 == test)
        return ("F3");
    if (sfKeyF4 == test)
        return ("F4");
    return (NULL);
}
