/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** colide_shape_create.c
*/

#include "rpg.h"

void place_collide_shape(global_data_t *gdata, collide_shape_t *cshape, collision_type type)
{
    if (type == CTYPE_BLOCK) {
        cshape->prev = NULL;
        cshape->next = gdata->objects->cshape_block;
        if (gdata->objects->cshape_block != NULL)
            gdata->objects->cshape_block->prev = cshape;
        gdata->objects->cshape_block = cshape;
    } else {
        cshape->prev = NULL;
        cshape->next = gdata->objects->cshape_other;
        if (gdata->objects->cshape_other != NULL)
            gdata->objects->cshape_other->prev = cshape;
        gdata->objects->cshape_other = cshape;
    }
}

collide_shape_t *collide_shape_create(global_data_t *gdata, char *name, char *go_name, collision_type type)
{
    collide_shape_t *cshape = malloc(sizeof(collide_shape_t));
    game_object_t *go = gameobject_get(gdata, go_name);

    if (cshape == NULL || go == NULL) {
        my_printf("%scollide_shape_create: can't create %s%s%s collide"
        " shape.%s\n", LRED, PURPLE, go_name, LRED, RESET);
        return (NULL);
    }
    my_printf("%sCreate collide shape %s%s%s.%s\n", LBLUE, PURPLE, name, LBLUE, RESET);
    cshape->name = string_dup(name);
    cshape->type = type;
    cshape->go = go;
    cshape->max = (sfIntRect){0, 0, 0, 0};
    cshape->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(cshape->array, sfLinesStrip);
    cshape->count_point = 0;
    cshape->points = NULL;
    cshape->is_draw = true;
    cshape->is_active = true;
    cshape->collision_list = NULL;
    place_collide_shape(gdata, cshape, type);
    return (cshape);
}