/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** create_collide_objects.c
*/

#include "rpg.h"

void take_offset(collide_shape_t *cshape1, sfVector2f pos1
                , collide_shape_t *cshape2, sfVector2f pos2)
{
    sfVector2f tmp = {0, 0};

    if (cshape1->collision_list->left == true) {
        cshape1->collision_list->left_offset.x = (cshape2->max.width + pos2.x) - (cshape1->max.left + pos1.x);
    }
    if (cshape1->collision_list->right == true) {
        cshape1->collision_list->right_offset.x = (cshape2->max.left + pos2.x) - (cshape1->max.width + pos1.x);
    }
    if (cshape1->collision_list->top == true) {
        cshape1->collision_list->top_offset.y = (cshape2->max.height + pos2.y) - (cshape1->max.top + pos1.y);
    }
    if (cshape1->collision_list->bottom == true) {
        cshape1->collision_list->bottom_offset.y = (cshape2->max.top + pos2.y) - (cshape1->max.height + pos1.y);
    }

    if (cshape2->collision_list->left == true) {
        tmp = get_point(cshape1, cshape2, (sfVector2f){1, 0}, pos1, pos2);
        cshape2->collision_list->left_offset.x = tmp.x;
    }
    if (cshape2->collision_list->right == true) {
        tmp = get_point(cshape1, cshape2, (sfVector2f){-1, 0}, pos1, pos2);
        cshape2->collision_list->right_offset.x = tmp.x;
    }
    if (cshape2->collision_list->top == true) {
        tmp = get_point(cshape1, cshape2, (sfVector2f){0, 1}, pos1, pos2);
        cshape2->collision_list->top_offset.y = tmp.y;
    }
    if (cshape2->collision_list->bottom == true) {
        tmp = get_point(cshape1, cshape2, (sfVector2f){0, -1}, pos1, pos2);
        cshape2->collision_list->bottom_offset.y = tmp.y;
    }
}

void check(collide_shape_t *cshape1, sfVector2f pos1
        , collide_shape_t *cshape2, sfVector2f pos2)
{
    if (cshape1->max.left + pos1.x < cshape2->max.left + pos2.x
    && cshape1->max.width + pos1.x < cshape2->max.width + pos2.x) {
        cshape1->collision_list->right = true;
        cshape2->collision_list->left = true;
    }

    if (cshape1->max.width + pos1.x > cshape2->max.width + pos2.x
    && cshape1->max.left + pos1.x > cshape2->max.left + pos2.x) {
        cshape1->collision_list->left = true;
        cshape2->collision_list->right = true;
    }

    if (cshape1->max.top + pos1.y < cshape2->max.top + pos2.y
    && cshape1->max.height + pos1.y < cshape2->max.height + pos2.y) {
        cshape1->collision_list->bottom = true;
        cshape2->collision_list->top = true;
    }

    if (cshape1->max.height + pos1.y > cshape2->max.height + pos2.y
    && cshape1->max.top + pos1.y > cshape2->max.top + pos2.y) {
        cshape1->collision_list->top = true;
        cshape2->collision_list->bottom = true;
    }

    bool left = cshape1->collision_list->left;
    bool right = cshape1->collision_list->right;
    bool top = cshape1->collision_list->top;
    bool bottom = cshape1->collision_list->bottom;
    sfVector2f tmp = {0, 0};

    if (bottom == true) {
        tmp.y = ABS((cshape2->max.top + pos2.y) - (cshape1->max.height + pos1.y));
        if (left == true) {
            tmp.x = ABS((cshape2->max.width + pos2.x) - (cshape1->max.left + pos1.x));
            if (tmp.x < tmp.y)
                cshape1->collision_list->bottom = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.left + 1000 + pos1.x > cshape2->max.left + pos2.x)
            //    cshape1->collision_list->left = false;
        }
        if (right == true) {
            tmp.x = ABS((cshape2->max.left + pos2.x) - (cshape1->max.width + pos1.x));
            if (tmp.x < tmp.y)
                cshape1->collision_list->bottom = false;
            else
                cshape1->collision_list->right = false;
            //if (cshape1->max.width - 1000 + pos1.x < cshape2->max.width + pos2.x)
            //    cshape1->collision_list->right = false;
        }
    }
    if (top == true) {
        tmp.y = ABS((cshape2->max.height + pos2.y) - (cshape1->max.top + pos1.y));
        if (left == true) {
            tmp.x = ABS((cshape2->max.width + pos2.x) - (cshape1->max.left + pos1.x));
            if (tmp.x < tmp.y)
                cshape1->collision_list->top = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.left + 1000 + pos1.x > cshape2->max.left + pos2.x)
            //    cshape1->collision_list->left = false;
        }
        if (right == true) {
            tmp.x = ABS((cshape2->max.left + pos2.x) - (cshape1->max.width + pos1.x));
            if (tmp.x < tmp.y)
                cshape1->collision_list->top = false;
            else
                cshape1->collision_list->right = false;
            //if (cshape1->max.width - 1000 + pos1.x < cshape2->max.width + pos2.x)
            //    cshape1->collision_list->right = false;
        }
    }

    if (right == true) {
        tmp.x = ABS((cshape2->max.left + pos2.x) - (cshape1->max.width + pos1.x));
        if (top == true) {
            tmp.y = ABS((cshape2->max.height + pos2.y) - (cshape1->max.top + pos1.y));
            if (tmp.x < tmp.y)
                cshape1->collision_list->top = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.top + 1000 + pos1.y > cshape2->max.top + pos2.y)
            //    cshape1->collision_list->top = false;
        }
        if (bottom == true) {
            tmp.y = ABS((cshape2->max.top + pos2.y) - (cshape1->max.height + pos1.y));
            if (tmp.x < tmp.y)
                cshape1->collision_list->bottom = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.height + 1000 + pos1.y < cshape2->max.height + cshape2->max.left + pos2.x - cshape1->max.width + pos1.x
        }
    }
    if (left == true) {
        tmp.x = ABS((cshape2->max.width + pos2.x) - (cshape1->max.left + pos1.x));
        if (top == true) {
            tmp.y = ABS((cshape2->max.height + pos2.y) - (cshape1->max.top + pos1.y));
            if (tmp.x < tmp.y)
                cshape1->collision_list->top = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.top + 1000 + pos1.y > cshape2->max.top + pos2.y)
            //    cshape1->collision_list->top = false;
        }
        if (bottom == true) {
            tmp.y = ABS((cshape2->max.top + pos2.y) - (cshape1->max.height + pos1.y));
            if (tmp.x < tmp.y)
                cshape1->collision_list->bottom = false;
            else
                cshape1->collision_list->left = false;
            //if (cshape1->max.height + 1000 + pos1.y < cshape2->max.height + pos2.y)
            //    cshape1->collision_list->bottom = false;
        }
    }

    take_offset(cshape1, pos1, cshape2, pos2);
}

void create_collide_objects(collide_shape_t *cshape1, sfVector2f pos1
                            , collide_shape_t *cshape2, sfVector2f pos2)
{
    collide_object_t *cobject1 = malloc(sizeof(collide_object_t));
    collide_object_t *cobject2 = malloc(sizeof(collide_object_t));

    if (cobject1 == NULL || cobject2 == NULL)
        return;
    cobject1->cshape = cshape2;
    cobject1->left = false;
    cobject1->left_offset = (sfVector2f){0, 0};
    cobject1->right = false;
    cobject1->right_offset = (sfVector2f){0, 0};
    cobject1->top = false;
    cobject1->top_offset = (sfVector2f){0, 0};
    cobject1->bottom = false;
    cobject1->bottom_offset = (sfVector2f){0, 0};
    cobject1->next = cshape1->collision_list;
    cshape1->collision_list = cobject1;

    cobject2->cshape = cshape1;
    cobject2->left = false;
    cobject2->left_offset = (sfVector2f){0, 0};
    cobject2->right = false;
    cobject2->right_offset = (sfVector2f){0, 0};
    cobject2->top = false;
    cobject2->top_offset = (sfVector2f){0, 0};
    cobject2->bottom = false;
    cobject2->bottom_offset = (sfVector2f){0, 0};
    cobject2->next = cshape2->collision_list;
    cshape2->collision_list = cobject2;
    check(cshape1, pos1, cshape2, pos2);
}