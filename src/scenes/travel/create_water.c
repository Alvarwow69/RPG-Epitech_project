/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** create_water
*/

#include "rpg.h"

void create_water_0_18(global_data_t *data)
{
    set_water(data, "water_node", "water0", (sfVector2i) {1125, 375});
    set_water(data, "water_node", "water1", (sfVector2i) {1050, 500});
    set_water(data, "water_node", "water2", (sfVector2i) {975, 625});
    set_water(data, "water_node", "water3", (sfVector2i) {900, 750});
    set_water(data, "water_node", "water4", (sfVector2i) {825, 875});
    set_water(data, "water_node", "water5", (sfVector2i) {750, 1000});
    set_water(data, "water_node", "water6", (sfVector2i) {675, 1125});
    set_water(data, "water_node", "water7", (sfVector2i) {1050, 250});
    set_water(data, "water_node", "water8", (sfVector2i) {975, 375});
    set_water(data, "water_node", "water9", (sfVector2i) {900, 500});
    set_water(data, "water_node", "water10", (sfVector2i) {825, 625});
    set_water(data, "water_node", "water11", (sfVector2i) {750, 750});
    set_water(data, "water_node", "water12", (sfVector2i) {975, 125});
    set_water(data, "water_node", "water13", (sfVector2i) {900, 0});
    set_water(data, "water_node", "water14", (sfVector2i) {825, -125});
    set_water(data, "water_node", "water15", (sfVector2i) {900, 250});
    set_water(data, "water_node", "water16", (sfVector2i) {825, 375});
    set_water(data, "water_node", "water17", (sfVector2i) {750, 500});
    set_water(data, "water_node", "water18", (sfVector2i) {675, 625});
}

void create_water_19_36(global_data_t *data)
{
    set_water(data, "water_node", "water19", (sfVector2i) {825, 125});
    set_water(data, "water_node", "water20", (sfVector2i) {750, 0});
    set_water(data, "water_node", "water21", (sfVector2i) {600, 500});
    set_water(data, "water_node", "water22", (sfVector2i) {525, 625});
    set_water(data, "water_node", "water23", (sfVector2i) {450, 750});
    set_water(data, "water_node", "water24", (sfVector2i) {525, 375});
    set_water(data, "water_node", "water25", (sfVector2i) {450, 500});
    set_water(data, "water_node", "water26", (sfVector2i) {375, 625});
    set_water(data, "water_node", "water27", (sfVector2i) {750, -250});
    set_water(data, "water_node", "water28", (sfVector2i) {675, -125});
    set_water(data, "water_node", "water29", (sfVector2i) {600, 0});
    set_water(data, "water_node", "water30", (sfVector2i) {675, -375});
    set_water(data, "water_node", "water31", (sfVector2i) {600, -250});
    set_water(data, "water_node", "water32", (sfVector2i) {525, -125});
    set_water(data, "water_node", "water33", (sfVector2i) {600, -500});
    set_water(data, "water_node", "water34", (sfVector2i) {525, -625});
    set_water(data, "water_node", "water35", (sfVector2i) {450, -750});
    set_water(data, "water_node", "water36", (sfVector2i) {375, -625});
}

void create_water_36_54(global_data_t *data)
{
    set_water(data, "water_node", "water37", (sfVector2i) {300, -500});
    set_water(data, "water_node", "water38", (sfVector2i) {525, 125});
    set_water(data, "water_node", "water39", (sfVector2i) {450, 250});
    set_water(data, "water_node", "water40", (sfVector2i) {375, 375});
    set_water(data, "water_node", "water41", (sfVector2i) {300, 500});
    set_water(data, "water_node", "water42", (sfVector2i) {450, -0});
    set_water(data, "water_node", "water43", (sfVector2i) {375, -125});
    set_water(data, "water_node", "water44", (sfVector2i) {300, -250});
    set_water(data, "water_node", "water45", (sfVector2i) {225, -375});
    set_water(data, "water_node", "water46", (sfVector2i) {225, -125});
    set_water(data, "water_node", "water48", (sfVector2i) {225, 375});
    set_water(data, "water_node", "water49", (sfVector2i) {150, -250});
    set_water(data, "water_node", "water50", (sfVector2i) {150, 0});
    set_water(data, "water_node", "water51", (sfVector2i) {150, 250});
    set_water(data, "water_node", "water52", (sfVector2i) {75, -125});
    set_water(data, "water_node", "water53", (sfVector2i) {75, 125});
    set_water(data, "water_node", "water54", (sfVector2i) {0, 0});
}

void create_water(global_data_t *data)
{
    create_water_0_18(data);
    create_water_19_36(data);
    create_water_36_54(data);
}