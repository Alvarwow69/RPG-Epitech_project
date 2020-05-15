/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#define INV_SCALE (sfVector2f){2, 2}

#define ACTIVE_COUNT 5
#define INV_COUNT 21
#define SLOT_COUNT (int)(ACTIVE_COUNT + INV_COUNT + 5)
#define SLOT_HELM 0
#define SLOT_CHEST 1
#define SLOT_PANTS 2
#define SLOT_RING1 3
#define SLOT_RING2 4
#define SLOT_ACTIVE (int[]){5, 6, 7, 8, 9}
#define SLOT_INV (int[]){10, 11, 12, 13, 14, 15\
                     , 16, 17, 18, 19, 20, 21\
                     , 22, 23, 24, 25, 26, 27\
                     , 28, 29, 30, 31}
#define PSTAT_COUNT 9

typedef struct inventory_rsc_prefab_s inventory_rsc_prefab_t;
typedef struct pstat_list_s pstat_list_t;

typedef enum inventory_ressources_id {
    IRSC_RING_SLOT,
    IRSC_HELM_SLOT,
    IRSC_CHEST_SLOT,
    IRSC_PANTS_SLOT,
    IRSC_ACTIVE_SLOT,
    IRSC_TRASH,
    IRSC_INV_SLOT,
    IRSC_HP_BAR,
    IRSC_XP_BAR,
    IRSC_CLOSE_CROSS,
    IRSC_PSTAT_ADD,
    IRSC_PSTAT_VIT,
    IRSC_PSTAT_MSTR,
    IRSC_PSTAT_RSTR,
    IRSC_PSTAT_MDEF,
    IRSC_PSTAT_RDEF,
    IRSC_PSTAT_ACC,
    IRSC_PSTAT_LUCK,
    IRSC_PSTAT_DEXT,
    IRSC_PSTAT_CEL,
    IRSC_PSTAT_AVL
} inventory_rsc_id;

#include "entity.h"
#include "gameobject.h"

struct inventory_rsc_prefab_s {
    inventory_rsc_id id;
    void (*action)(global_data_t *, button_t *button);
    sfVector2f *pos;
    sfIntRect normal;
    sfIntRect hover;
    sfIntRect click;
};

struct pstat_list_s {
    inventory_rsc_id id;
    char *name;
    void (*action)(global_data_t *gdata, text_t *text);
};

extern const inventory_rsc_prefab_t inv_rsc[];
extern const pstat_list_t pstat_list[];

void create_inventory_screen(global_data_t *gdata, char *scene);

void player_scene_event(global_data_t *gdata);

void inventory_update(global_data_t *gdata);

void open_inventory(global_data_t *gdata);
void close_inventory(global_data_t *gdata, button_t *button);
void change_item(global_data_t *gdata, button_t *button);
void inv_action(global_data_t *gdata, button_t *button);
void inventory_trash(global_data_t *gdata, button_t *button);

#endif