/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** quest_prefab
*/

#include "rpg.h"

const quest_setting_t quest_setting[] = {
    {"Chasse au lilodon", HUNT1_IDQ, "map", HUNT_TQ, PNJID_VILLAGER_1, PNJID_VILLAGER_1, {22, 10}, {{1, MSTID_LILODON, 0, "Lilodon"}}, "Des createure\ndetruise notre\nvillage peux\ntu nous aider?", GEST_QUEST},
    {"Raporter une pioche", FIND1_IDQ, "map", FIND_TQ, PNJID_VILLAGER_2, PNJID_VILLAGER_2, {25, 50}, {{1, IID_PICKAXE, 0, "Pickaxe"}}, "J'ai besoin d'une\npioche ramene\nen moi une! (Un mineur sans\npioche c'est\npas ideal)", GEST_QUEST},
    {"Donner 5 patates", FIND2_IDQ, "map", FIND_TQ, PNJID_VILLAGER_3,
     PNJID_VILLAGER_3, {10, 37}, {{5, IID_POTATO, 0, "Patate"}},
     "J'ai faim! Mais je\nne sais je ne sais\npas ou il ya des\npommes de terre.",
     GEST_QUEST},
    {"Tuer un lilodon", HUNT_SNOW1_IDQ, "snow", HUNT_TQ, PNJID_SNOW_2,
    PNJID_SNOW_2, {33, 75}, {{1, MSTID_LILODON, 0, "Lilodon"}},
    "Un monstre terrorise\nmon chez moi aide moi\n mon ami!!",
    GEST_QUEST},
    {"QUEST_END", QUEST_END, "main", \
    0, 0, 0, {0, 0}, \
    {{0, 0, 0, NULL}}, GEST_QUEST}
};