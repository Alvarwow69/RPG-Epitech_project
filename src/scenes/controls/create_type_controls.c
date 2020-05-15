/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** create_type_controls
*/

#include "rpg.h"

void create_type_controls(global_data_t *data)
{
    add_type_controls(data, "controls_editor", "Editor");
    add_type_controls(data, "controls_inventory", "Inventory");
    add_type_controls(data, "controls_movement_ship", "Movement Ship");
    add_type_controls(data, "controls_movement_player", "Movement Player");
    add_type_controls(data, "controls_gameplay", "Gameplay");
}