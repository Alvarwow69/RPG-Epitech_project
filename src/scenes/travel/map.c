/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** map
*/

#include "rpg.h"

void map_travel(global_data_t *data, int y, int x)
{
    data->travel->map[y][x] = '.';
    if ((x == 5 && y == 7) || (x == 5 && y == 8) || \
(x == 6 && y == 7) || (x == 6 && y == 8))
        data->travel->map[y][x] = '1';
    if ((x == 2 && y == 5) || (x == 2 && y == 6) || \
(x == 3 && y == 5) || (x == 3 && y == 6))
        data->travel->map[y][x] = '2';
    if ((x == 4 && y == 2) || (x == 4 && y == 3) || \
(x == 5 && y == 2) || (x == 5 && y == 3))
        data->travel->map[y][x] = '3';
    if ((x == 1 && y == 1) || (x == 1 && y == 2) || \
(x == 2 && y == 1) || (x == 2 && y == 2))
        data->travel->map[y][x] = '4';
}

void create_map_travel(global_data_t *data)
{
    for (int y = 0; y != 10; y ++) {
        for (int x = 0; x != 7; x ++) {
            map_travel(data, y, x);
        }
    }
}