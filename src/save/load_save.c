/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** load_save
*/

#include "rpg.h"

int find_size_file(int fd)
{
    int i = 0;
    char actual;
    int res = read(fd, &actual, 1);

    if (res == 1) {
        while (res == 1) {
            i++;
            res = read(fd, &actual, 1);
        }
    }
    return (i);
}

char* read_save(int fd, int size)
{
    int i = 0;
    char *save = malloc(sizeof(char) * (size+1));
    char actual;
    int res = read(fd, &actual, 1);

    if (res == 1) {
        while (res == 1) {
            save[i]=actual;
            i++;
            res = read(fd, &actual, 1);
        }
    }
    save[i]='\0';
    return (save);
}

char *find_number_ligne(char *str, int i)
{
    char *number;
    int tmp = 0;
    int cmp = 0;
    for (; tmp < i; cmp++)
        if (str[cmp] == ',')
            tmp++;
    number = concat_fstring("%c", 48);
    for (; str[cmp] != ',' && str[cmp] != '\0'; cmp++)
        number = concat_fstring("%s%c", number, str[cmp]);
    return (number);
}

void load_save_nbr(global_data_t *data, player_t *player)
{
    (void)data;
    for (int i = 0, y = 5; i != 5; i++, y++) {
        player->save->tab_id_item[y] = get_number(find_number_ligne(player->save->save_map[6], i));
        player->save->nbr_item[y] = get_number(&find_number_ligne(player->save->save_map[6], i)[4]);
    }
    for (int i = 0, y = 10; i != 7; i++, y++) {
        player->save->tab_id_item[y] = get_number(find_number_ligne(player->save->save_map[7], i));
        player->save->nbr_item[y] = get_number(&find_number_ligne(player->save->save_map[7], i)[4]);
    }
    for (int i = 0, y = 17; i != 7; i++, y++) {
        player->save->tab_id_item[y] = get_number(find_number_ligne(player->save->save_map[8], i));
        player->save->nbr_item[y] = get_number(&find_number_ligne(player->save->save_map[8], i)[4]);
    }
    for (int i = 0, y = 24; i != 7; i++, y++) {
        player->save->tab_id_item[y] = get_number(find_number_ligne(player->save->save_map[9], i));
        player->save->nbr_item[y] = get_number(&find_number_ligne(player->save->save_map[9], i)[4]);
    }
}

void load_save(global_data_t *data)
{
    int save = open("save/save_player", O_RDWR);
    player_t *player = gameobject_get(data, "player_go")->object.player;

    player->save->size = find_size_file(save);
    close(save);
    save = open("save/save_player", O_RDWR);
    player->save->save_txt = read_save(save, player->save->size);
    close(save);
    player->save->save_map = str_to_tab(player->save->save_txt, "\n");
    for (int i = 0; i != 5; i ++) {
        player->save->tab_id_item[i] = get_number(player->save->save_map[i+1]);
        player->save->nbr_item[i] = get_number(&player->save->save_map[i+1][2]);
    }
    load_save_nbr(data, player);
    
    player->save->value[0].act = get_number(find_number_ligne(player->save->save_map[10], 0));
    player->save->value[0].max = get_number(find_number_ligne(player->save->save_map[10], 1));

    player->save->value[1].act = get_number(find_number_ligne(player->save->save_map[11], 0));
    player->save->value[1].max = get_number(find_number_ligne(player->save->save_map[11], 1));

    player->save->value[2].act = get_number(find_number_ligne(player->save->save_map[12], 0));
    player->save->value[2].max = get_number(find_number_ligne(player->save->save_map[12], 1));
    for (int i = 0, y = 13; i != 8; i ++, y++)
        player->save->properties[i] = get_number(player->save->save_map[y]);
}
