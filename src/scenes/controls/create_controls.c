/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** create_controls
*/

#include "rpg.h"

void create_controls(global_data_t *data)
{
//gameplay
    add_controls(data, "Hotbar Slot 1", "controls_gameplay", sfKeyNum1);
    add_controls(data, "Hotbar Slot 2", "controls_gameplay", sfKeyNum2);
    add_controls(data, "Hotbar Slot 3", "controls_gameplay", sfKeyNum3);
    add_controls(data, "Hotbar Slot 4", "controls_gameplay", sfKeyNum4);
    add_controls(data, "Hotbar Slot 5", "controls_gameplay", sfKeyNum5);
    add_controls(data, "Attaque", "controls_gameplay", -2);
    add_controls(data, "Parade", "controls_gameplay", -3);
    add_controls(data, "Interact", "controls_gameplay", sfKeyF);
    add_controls(data, "Pause", "controls_gameplay", sfKeyEscape);

//Editor

    add_controls(data, "Move up", "controls_editor", sfKeyZ);
    add_controls(data, "Move down", "controls_editor", sfKeyS);
    add_controls(data, "Move left", "controls_editor", sfKeyD);
    add_controls(data, "Move right", "controls_editor", sfKeyQ);
    add_controls(data, "Change level/background", "controls_editor", sfKeyB);


//movement_player
    add_controls(data, "Jump", "controls_movement_player", sfKeyZ);
    add_controls(data, "Droite", "controls_movement_player", sfKeyD);
    add_controls(data, "Gauche", "controls_movement_player", sfKeyQ);
    add_controls(data, "Acroupir", "controls_movement_player", sfKeyS);
    add_controls(data, "Courir", "controls_movement_player", sfKeyLControl);


//movement_ship
    add_controls(data, "Nord", "controls_movement_ship", sfKeyZ);
    add_controls(data, "Est", "controls_movement_ship", sfKeyD);
    add_controls(data, "West", "controls_movement_ship", sfKeyQ);
    add_controls(data, "Sud", "controls_movement_ship", sfKeyS);

//inventory
    add_controls(data, "Ouvrir Inventaire", "controls_inventory", sfKeyA);
    add_controls(data, "Quest", "controls_inventory", sfKeyP);
}