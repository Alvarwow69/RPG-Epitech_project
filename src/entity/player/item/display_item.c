/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** display_item.c
*/

#include "rpg.h"

/*
void display_item_type(item_type type)
{
    switch (type) {
        case IT_NONE: printf("type : NONE\n"); break;
        case IT_HELM: printf("type : HELM\n"); break;
        case IT_CHEST: printf("type : CHEST\n"); break;
        case IT_PANTS: printf("type : PANTS\n"); break;
        case IT_RING: printf("type : RING\n"); break;
        default: break;
    }
}

void display_item_id(item_id id)
{
    switch (id) {
        case IID_NO_ITEM: printf("id : NO_ITEM\n"); break;
        case IID_NO_HELM: printf("id : NO_HELM\n"); break;
        case IID_NO_CHEST: printf("id : NO_CHEST\n"); break;
        case IID_NO_PANTS: printf("id : NO_PANTS\n"); break;
        case IID_NO_RING: printf("id : NO_RING\n"); break;
        case IID_ARMOR1_HELM: printf("id : ARMOR1_HELM\n"); break;
        case IID_ARMOR1_CHEST: printf("id : ARMOR1_CHEST\n"); break;
        case IID_ARMOR1_PANTS: printf("id : ARMOR1_PANTS\n"); break;
        default: break;
    }
}

void display_item(item_t *item)
{
    printf("\nname : %s\n", item->name);
    display_item_type(item->type);
    display_item_id(item->id);
    printf("go_name : %s\n", item->go_inv->name);
    printf("number : %i\n", item->number);
    printf("stat :\n");
    printf("\tvitality   : %i\n", item->stats->vit);
    printf("\tm.strenght : %i\n", item->stats->mstr);
    printf("\tr.strenght : %i\n", item->stats->rstr);
    printf("\tm.defense  : %i\n", item->stats->mdef);
    printf("\tr.defense  : %i\n", item->stats->rdef);
    printf("\taccuracy   : %i\n", item->stats->acc);
    printf("\tluck       : %i\n", item->stats->luck);
    printf("\tdexterity  : %i\n", item->stats->dext);
    printf("\tcelerity   : %i\n\n", item->stats->cel);
}
*/