/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** collide_shape_get.c
*/

#include "rpg.h"

collide_shape_t *collide_shape_get(global_data_t *gdata, char *name)
{
    for (collide_shape_t *tmp = gdata->objects->cshape_block; tmp != NULL; tmp = tmp->next)
        if (cmp_string(tmp->name, name) == 0)
            return (tmp);
    for (collide_shape_t *tmp = gdata->objects->cshape_other; tmp != NULL; tmp = tmp->next)
        if (cmp_string(tmp->name, name) == 0)
            return (tmp);
    my_printf("%scollide_shape_get: can't find %s%s%s.%s\n"
    , LRED, PURPLE, name, LRED, RESET);
    return (NULL);
}