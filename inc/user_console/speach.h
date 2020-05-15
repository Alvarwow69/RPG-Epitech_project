/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** speach.h
*/

#ifndef SPEACH_H
#define SPEACH_H

#include "rpg.h"

// Speach for downloading file of ftp server ----------------------------------
#define NO_CONNECT concat_fstring("%sCan't connected to ftp server, "\
                   "please ask the support to %smaxime.payant@epitech.eu"\
                   "%s.%s\n", LRED, PURPLE, LRED, RESET)

#define MOVE_DIR concat_fstring("%sMoved to %sressources_csfml/%s "\
                 "directory.%s\n", LCYAN, PURPLE, LCYAN, RESET)

#define DL_PROCESS(str) concat_fstring("%sDownloading %s%s%s ...%s\n"\
                        , LCYAN, PURPLE, str, LCYAN, RESET)

#define DL_ERROR(str) concat_fstring("%sCan't download %s%s%s.%s"\
                      , LRED, PURPLE, str, LRED, RESET)
// ----------------------------------------------------------------------------

#endif