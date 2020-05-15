/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** collide_shape_destroy.c
*/

#include "rpg.h"

void collide_shape_remove_from_block_list(global_data_t *gdata, collide_shape_t *cshape)
{
    collide_shape_t *tmp = cshape->next;
    collide_shape_t *tmp_prev = cshape->prev;

    if (cmp_string(gdata->objects->cshape_block->name, cshape->name) == 0) {
        if (gdata->objects->cshape_block->next != NULL)
            gdata->objects->cshape_block = gdata->objects->cshape_block->next;
        else
            gdata->objects->cshape_block = NULL;
    }
    if (cshape->prev != NULL)
        cshape->prev->next = tmp;
    if (cshape->next != NULL)
        cshape->next->prev = tmp_prev;
}

void collide_shape_remove_from_other_list(global_data_t *gdata, collide_shape_t *cshape)
{
    collide_shape_t *tmp = cshape->next;
    collide_shape_t *tmp_prev = cshape->prev;

    if (cmp_string(gdata->objects->cshape_other->name, cshape->name) == 0) {
        if (gdata->objects->cshape_other->next != NULL)
            gdata->objects->cshape_other = gdata->objects->cshape_other->next;
        else
            gdata->objects->cshape_other = NULL;
    }
    if (cshape->prev != NULL)
        cshape->prev->next = tmp;
    if (cshape->next != NULL)
        cshape->next->prev = tmp_prev;
}

void collide_shape_destroy(global_data_t *gdata, char *name)
{
    collide_shape_t *cshape = collide_shape_get(gdata, name);

    if (cshape->type == CTYPE_BLOCK)
        collide_shape_remove_from_block_list(gdata, cshape);
    else
        collide_shape_remove_from_other_list(gdata, cshape);
    sfVertexArray_destroy(cshape->array);
    if (cshape->points != NULL)
        free(cshape->points);
    for (collide_object_t *obj = cshape->collision_list
    ; obj != NULL; obj = cshape->collision_list) {
        cshape->collision_list = obj->next;
        free(obj);
    }
    free(cshape);
}