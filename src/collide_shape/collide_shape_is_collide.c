/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** colide_shape_is_colide.c
*/

#include "rpg.h"

sfVector2f support_function(collide_shape_t *shape, sfVector2f d, sfVector2f pos)
{
    sfVector2f result;
    int tmp = 0;
    int check = 0;
    int index = 0;

    if (shape->count_point == 0)
        return (my_printf("%s%s hasn't any point%s\n"
        , LRED, shape->go->name, RESET), (sfVector2f){0, 0});
    tmp = ((shape->points[0].x + pos.x) * d.x)
    + ((shape->points[0].y + pos.y) * d.y);
    for (int ctr = 1; ctr < shape->count_point; ctr += 1) {
        check = ((shape->points[ctr].x + pos.x) * d.x)
        + ((shape->points[ctr].y + pos.y) * d.y);
        if (check > tmp) {
            tmp = check;
            index = ctr;
        }
    }
    result.x = shape->points[index].x + pos.x;
    result.y = shape->points[index].y + pos.y;
    return (result);
}

sfVector2f get_normale_vector(sfVector2f point_a, sfVector2f point_b
                             , sfVector2f origin)
{
    sfVector2f u = (sfVector2f){0, 0};
    sfVector2f v = (sfVector2f){0, 0};
    sfVector2f n = (sfVector2f){0, 0};
    float det = 0;
    float norme = 0;

    u.x = point_b.x - point_a.x;
    u.y = point_b.y - point_a.y;
    v.x = origin.x - point_a.x;
    v.y = origin.y - point_a.y;
    det = u.x * v.y - u.y * v.x;
    n.x = -u.y * (det);
    n.y = u.x * (det);
    norme = sqrt(n.x * n.x + n.y * n.y);
    n.x /= norme;
    n.y /= norme;
    return (n);
}

sfVector2f get_point(collide_shape_t *shape1, collide_shape_t *shape2
                    , sfVector2f d, sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f point1 = (sfVector2f){0, 0};
    sfVector2f point2 = (sfVector2f){0, 0};
    sfVector2f result = (sfVector2f){0, 0};

    point1 = support_function(shape1, d, pos1);
    point2 = support_function(shape2, (sfVector2f){-d.x, -d.y}, pos2);
    result.x = point1.x - point2.x;
    result.y = point1.y - point2.y;
    return (result);
}

bool check_simplex(sfVector2f *fpoint)
{
    float det1 = fpoint[2].x * fpoint[0].y - fpoint[2].y * fpoint[0].x;
    float det2 = fpoint[0].x * fpoint[1].y - fpoint[0].y * fpoint[1].x;
    float det3 = fpoint[1].x * fpoint[2].y - fpoint[1].y * fpoint[2].x;

    if ((det1 <= 0 && det2 <= 0 && det3 <= 0)
    ||(det1 >= 0 && det2 >= 0 && det3 >= 0))
        return (true);
    return (false);
}

bool check_basic_collide(collide_shape_t *shape1, sfVector2f pos1
                        , collide_shape_t *shape2, sfVector2f pos2)
{
    if (shape1 == NULL)
        return (my_printf("%sbasic_collide: Shape1 doesn't exist%s\n", LRED, RESET), false);
    if (shape2 == NULL)
        return (my_printf("%sbasic_collide: Shape2 doesn't exist%s\n", LRED, RESET), false);
    if((shape2->max.left + pos2.x    >= shape1->max.width + pos1.x)
    || (shape2->max.width + pos2.x   <= shape1->max.left + pos1.x)
    || (shape2->max.top + pos2.y     >= shape1->max.height + pos1.y)
    || (shape2->max.height + pos2.y  <= shape1->max.top + pos1.y))
        return (false);
    else
        return (true);
}

bool collide_shape_is_collide(collide_shape_t *shape1, sfVector2f pos1
                             , collide_shape_t *shape2, sfVector2f pos2)
{
    sfVector2f fpoint[3] =\
    {(sfVector2f){0, 0}, (sfVector2f){0, 0}, (sfVector2f){0, 0}};
    sfVector2f d = (sfVector2f){0, 1};
    sfVector2f u = (sfVector2f){0, 0};
    sfVector2f v = (sfVector2f){0, 0};

    if (check_basic_collide(shape1, pos1, shape2, pos2) == false)
        return (false);
    fpoint[0] = get_point(shape1, shape2, d, pos1, pos2);
    d = (sfVector2f){-fpoint[0].x, -fpoint[0].y};
    fpoint[1] = get_point(shape1, shape2, d, pos1, pos2);
    u = (sfVector2f){fpoint[1].x - fpoint[0].x, fpoint[1].y - fpoint[0].y};
    v = (sfVector2f){-fpoint[1].x, -fpoint[1].y};
    if (((u.x * v.x) + (u.y * v.y)) > 0)
        return (false);
    d = get_normale_vector(fpoint[0], fpoint[1], (sfVector2f){0, 0});
    fpoint[2] = get_point(shape1, shape2, d, pos1, pos2);
    if (check_simplex(fpoint) == false)
        return(false);
    return (true);
}