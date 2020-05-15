/*
** EPITECH PROJECT, 2019
** main_unload.c
** File description:
** 
*/

#include "rpg.h"

void main_unload(global_data_t *data)
{
    node_destroy(data, "interface");
}