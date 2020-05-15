/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** head.c
*/

#include "rpg.h"

sfIntRect pnj_set_helm_rect(pnj_t *pnj, move move, armor_id id)
{
    sfVector2i offset = {0, 0};
    int rect_id = pnj->anim->txt->tile_rect.left
                  / pnj->anim->txt->tile_rect.width + 1;

    switch (move) {
        case M_STAND:
            offset = head_offset_list[HEAD_OFS_STAND].offset;
            break;
        case M_SEET:
            offset = head_offset_list[HEAD_OFS_SEET].offset;
            break;
        case M_SNICK:
            offset = head_offset_list[HEAD_OFS_SNICK].offset;
            break;
        case M_WALK:
            offset = head_offset_list[rect_id + HEAD_OFS_WALK_BEGIN].offset;
            break;
        case M_RUN:
            offset = head_offset_list[rect_id + HEAD_OFS_RUN_BEGIN].offset;
            break;
        case M_JUMP:
            offset = head_offset_list[rect_id + HEAD_OFS_JUMP_BEGIN].offset;
            break;
        default:
            break;
    }
    offset = add_vectori(helm[id.helm].offset, offset);
    return (add_recti_vectori((sfIntRect){0, 0, 129, 129}, offset));
}