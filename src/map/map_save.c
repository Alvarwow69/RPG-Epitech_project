/*
** EPITECH PROJECT, 2020
** map_save.c
** File description:
** 
*/

#include "rpg.h"

void free_save(map_save_t *map, scene_t *scene)
{
    for (int i = 0; i < scene->map_height; i++) {
        free(map->background_block[i]);
        free(map->background_ore[i]);
        free(map->ground_block[i]);
        free(map->ground_ore[i]);
    }
    free(map->background_block);
    free(map->background_ore);
    free(map->ground_block);
    free(map->ground_ore);
}

void put_in_file(map_save_t *map, scene_t *scene, node_t *node)
{
    char *name_save = NULL;
    FILE *fd = fopen(concat_fstring("./save/save_map_%s", node->scene), "w+");

    for (int i = 0; i < scene->map_height; i++) {
        fwrite(":", sizeof(char), 1, fd);
        for (int c = 0; c < scene->map_width; c++) {
            name_save = concat_fstring("%i-%i/%i-%i",
            map->background_block[i][c],
            map->background_ore[i][c],
            map->ground_block[i][c],
            map->ground_ore[i][c]);
            fwrite(name_save, sizeof(char), str_len(name_save), fd);
            fwrite(":", sizeof(char), 1, fd);
        }
        fwrite("-1:\n", sizeof(char), 4, fd);
    }
    fclose(fd);
}

void choose_layer(game_object_t *game, map_save_t *map, char **name)
{
    switch (game->layer) {
    case -2:
        map->background_block[get_number(name[2])][get_number(name[1])]
        = get_number(name[3]);
        break;
    case -1:
        map->background_ore[get_number(name[2])][get_number(name[1])]
        = get_number(name[3]);
        break;
    case 1:
        map->ground_block[get_number(name[2])][get_number(name[1])]
        = get_number(name[3]);
        break;
    case 2:
        map->ground_ore[get_number(name[2])][get_number(name[1])]
        = get_number(name[3]);
        break;
    default:
        my_printf("%sError to save the map!\n", RED);
    }
}

void map_save(global_data_t *data, char *node_name)
{
    map_save_t *map = malloc(sizeof(map_save_t));
    node_t *node = node_get(data, node_name);
    scene_t *scene = scene_get(data, node->scene);
    char **name = NULL;
    game_object_t *game = node->gameobjects;

    preprare_lists(map, scene);
    while (game && !cmp_string(game->node, node_name)) {
        name = str_to_tab(game->name, "-");
        choose_layer(game, map, name);
        game = game->next;
    }
    put_in_file(map, scene, node);
    free_save(map, scene);
}