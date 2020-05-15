/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** vector.c
*/

#include "rpg.h"

sfVector2f scale_vector(sfVector2f vector, sfVector2f scale)
{
    sfVector2f result = {vector.x * scale.x\
, vector.y * scale.y};
    return (result);
}

sfVector2f add_vectorf(sfVector2f vector1, sfVector2f vector2)
{
    sfVector2f result = (sfVector2f)\
{vector1.x + vector2.x
        , vector1.y + vector2.y};

    return (result);
}

sfVector2i add_vectori(sfVector2i vector1, sfVector2i vector2)
{
    sfVector2i result = (sfVector2i)\
{vector1.x + vector2.x
        , vector1.y + vector2.y};
    return (result);
}

sfIntRect add_recti(sfIntRect rect1, sfIntRect rect2)
{
    sfIntRect result = (sfIntRect)\
{rect1.left + rect2.left
        , rect1.top + rect2.top
        , rect1.height + rect2.height
        , rect1.width + rect2.width};
    return (result);
}

sfIntRect add_recti_vectori(sfIntRect rect, sfVector2i vector)
{
    sfIntRect result = (sfIntRect) \
{rect.left + vector.x
        , rect.top + vector.y
        , rect.width
        , rect.height};
    return (result);
}