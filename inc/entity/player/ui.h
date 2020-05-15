/*
** EPITECH PROJECT, 2019
** MUL_rpg_2019
** File description:
** ui.h
*/

#ifndef UI_H
#define UI_H

#define UI_SCALE (sfVector2f){1, 1}

typedef struct ui_rsc_prefab_s ui_rsc_prefab_t;

typedef enum ui_ressources_id {
    UIRSC_ACTIVE_SLOT1,
    UIRSC_ACTIVE_SLOT2,
    UIRSC_ACTIVE_SLOT3,
    UIRSC_ACTIVE_SLOT4,
    UIRSC_ACTIVE_SLOT5,
    UIRSC_SLOT
} ui_rsc_id;

#include "player.h"
#include "consumable.h"
#include "entity.h"

struct ui_rsc_prefab_s {
    ui_rsc_id id;
    sfVector2f pos;
    sfIntRect normal;
    sfIntRect select;
};

extern const ui_rsc_prefab_t ui_rsc[];

void init_ui(global_data_t *gdata, char *scene);
void ui_update(global_data_t *gdata);

void modify_satiety(global_data_t *gdata, properties_t *prop, int value);
void modify_vitality(global_data_t *gdata, properties_t *prop, int value);
void modify_money(global_data_t *gdata, properties_t *prop, int value);

#endif