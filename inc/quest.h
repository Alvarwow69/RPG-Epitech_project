/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "rpg.h"

typedef struct quest_setting_s quest_setting_t;
typedef struct quest_gest_s quest_gest_t;
typedef struct reward_quest_s reward_quest_t;
typedef union quest quest;

typedef enum {
    HUNT_TQ,
    HARVST_TQ,
    FIND_TQ
} type_quest_e;

typedef enum {
    HUNT1_IDQ,
    HUNT_SNOW1_IDQ,
    FIND1_IDQ,
    FIND2_IDQ,
    QUEST_END
} id_quest_e;

struct reward_quest_s
{
    int gold;
    int xp;
};

typedef struct
{
    int how_many;
    monster_id type_mob;
    int actual;
    char *name_mob;
}hunt_t;

typedef struct
{
    int how_many;
    item_id type_item;
    int actual;
    char *name_item;
}find_item_t;

struct quest_gest_s
{
    int quest_accomplished;
    int can_move;
    int active;
    int accepted;
    sfVector2i mouse_pos_click;
    sfVector2i mouse_pos_click_diff;
    sfVector2f origin_quest_pos;
};

union quest{
    hunt_t hunt;
    find_item_t find_item;
};

struct quest_setting_s
{
    char *name;
    id_quest_e id_quest;
    char *scene_name;
    type_quest_e type_quest;
    int owner_png; //ajout enum
    int target_pnj; //ajout enum
    reward_quest_t reward_quest;
    quest quest;
    char *description;
    quest_gest_t gest;
};

typedef struct
{
    int actif;
    int tmp;
}tab_quest_t;

typedef struct 
{
    int nbr;
    int one_quest_move;
    int nbr_quest;
    tab_quest_t *tab_quest;
    quest_setting_t *quest_setting;
}quest_t;

extern const quest_setting_t quest_setting[];

void init_quest(global_data_t *data);
void create_quest(global_data_t *data, quest_setting_t setting);
quest_t *initialize_quest(void);
void tab_quest_load(global_data_t *data);
void tab_quest_unload(global_data_t *data);
void quest_event(global_data_t *data);
void verif_quest(global_data_t *data, collide_object_t *cobj);
void quest_success(global_data_t *data, quest_setting_t setting);
void accepte_quest(global_data_t *data, button_t *button);
void create_quest_accept(global_data_t *data, quest_setting_t setting);
void refuse_quest(global_data_t *data, button_t *button);
void create_quest_refuse(global_data_t *data, quest_setting_t setting);
void resume_quest(global_data_t *data, button_t *button);
void verif_quest_find(global_data_t *data, inventory_t *inv);
void verif_quest_find(global_data_t *data, inventory_t *inv);

#define GEST_QUEST {0, 0, 0, 0, {0, 0}, {0, 0}, {0, 0}}

#endif