/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** travel_layer
*/

#include "rpg.h"


void set_layer_0_18(global_data_t *data)
{
    gameobject_set_layer(data, "water0", 31);
    gameobject_set_layer(data, "water1", 29);
    gameobject_set_layer(data, "water2", 27);
    gameobject_set_layer(data, "water3", 25);
    gameobject_set_layer(data, "water4", 23);
    gameobject_set_layer(data, "water5", 21);
    gameobject_set_layer(data, "water6", 19);
    gameobject_set_layer(data, "water7", 29);
    gameobject_set_layer(data, "water8", 27);
    gameobject_set_layer(data, "water9", 25);
    gameobject_set_layer(data, "water10", 23);
    gameobject_set_layer(data, "water11", 21);
    gameobject_set_layer(data, "water12", 27);
    gameobject_set_layer(data, "water13", 25);
    gameobject_set_layer(data, "water14", 23);
    gameobject_set_layer(data, "water15", 25);
    gameobject_set_layer(data, "water16", 23);
    gameobject_set_layer(data, "water17", 21);
    gameobject_set_layer(data, "water18", 19);
}

void set_layer_19_36(global_data_t *data)
{
    gameobject_set_layer(data, "water19", 23);
    gameobject_set_layer(data, "water20", 21);
    gameobject_set_layer(data, "water21", 17);
    gameobject_set_layer(data, "water22", 15);
    gameobject_set_layer(data, "water23", 13);
    gameobject_set_layer(data, "water24", 15);
    gameobject_set_layer(data, "water25", 13);
    gameobject_set_layer(data, "water26", 11);
    gameobject_set_layer(data, "water27", 21);
    gameobject_set_layer(data, "water28", 19);
    gameobject_set_layer(data, "water29", 17);
    gameobject_set_layer(data, "water30", 19);
    gameobject_set_layer(data, "water31", 17);
    gameobject_set_layer(data, "water32", 15);
    gameobject_set_layer(data, "water33", 17);
    gameobject_set_layer(data, "water34", 15);
    gameobject_set_layer(data, "water35", 13);
    gameobject_set_layer(data, "water36", 11);
}

void set_layer_37_54(global_data_t *data)
{
    gameobject_set_layer(data, "water37", 9);
    gameobject_set_layer(data, "water38", 15);
    gameobject_set_layer(data, "water39", 13);
    gameobject_set_layer(data, "water40", 11);
    gameobject_set_layer(data, "water41", 9);
    gameobject_set_layer(data, "water42", 13);
    gameobject_set_layer(data, "water43", 11);
    gameobject_set_layer(data, "water44", 9);
    gameobject_set_layer(data, "water45", 7);
    gameobject_set_layer(data, "water46", 7);
    gameobject_set_layer(data, "water48", 7);
    gameobject_set_layer(data, "water49", 5);
    gameobject_set_layer(data, "water50", 5);
    gameobject_set_layer(data, "water51", 5);
    gameobject_set_layer(data, "water52", 3);
    gameobject_set_layer(data, "water53", 3);
    gameobject_set_layer(data, "water54", 1);
}

void set_layer(global_data_t *data)
{
    set_layer_0_18(data);
    set_layer_19_36(data);
    set_layer_37_54(data);
    gameobject_set_layer(data, "jungle", 19);
    gameobject_set_layer(data, "snow", 13);
    gameobject_set_layer(data, "cave", 17);
    gameobject_set_layer(data, "sand", 9);
}
