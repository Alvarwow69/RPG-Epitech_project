/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** save
*/

#include "rpg.h"

void my_putnbr_file(int nb, FILE *save)
{
    int pow = 1;

    if (nb < 0) {
        nb *= -1;
        fwrite("-" , 1 , 1 , save);
    }
    for (int temp_nb = nb; (temp_nb / 10) != 0; pow *= 10)
        temp_nb /= 10;
    for (int temp = 0; pow > 0; pow /= 10) {
        temp = nb / pow + 48;
        nb %= pow;
        fwrite(&temp , 1 , 1 , save);
    }
}

void my_putchar_file(char c, FILE *save)
{
    fwrite(&c , 1 , 1 , save);
}

void my_putstr_file(char *str, FILE *save)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_file(str[i], save);
}

void create_save2(global_data_t *data, FILE *save, player_t *player)
{
    (void)data;
    my_putstr_file("\n", save);
    for (int i = 10; i != 17; i++) {
        my_putnbr_file(player->save->tab_id_item[i], save);
       my_putstr_file(":", save);
        my_putnbr_file(player->save->nbr_item[i], save);
        my_putstr_file(",", save);
    }
    my_putstr_file("\n", save);
    for (int i = 17; i != 24; i++) {
        my_putnbr_file(player->save->tab_id_item[i], save);
       my_putstr_file(":", save);
        my_putnbr_file(player->save->nbr_item[i], save);
        my_putstr_file(",", save);
    }
    my_putstr_file("\n", save);
    for (int i = 24; i != 31; i++) {
        my_putnbr_file(player->save->tab_id_item[i], save);
       my_putstr_file(":", save);
        my_putnbr_file(player->save->nbr_item[i], save);
        my_putstr_file(",", save);
    }
}

void create_save(global_data_t *data)
{
    player_t *player = gameobject_get(data, "player_go")->object.player;
    FILE *save;
    save = fopen("save/save_player", "w+");
    my_putstr_file("Player\n", save);

    for (int i = 0; i != 5; i++) {
        my_putnbr_file(player->save->tab_id_item[i], save);
        my_putstr_file(":", save);
        my_putnbr_file(player->save->nbr_item[i], save);
        my_putstr_file("\n", save);
    }
    for (int i = 5; i != 10; i++) {
        my_putnbr_file(player->save->tab_id_item[i], save);
       my_putstr_file(":", save);
        my_putnbr_file(player->save->nbr_item[i], save);
        my_putstr_file(",", save);
    }
    create_save2(data, save, player);
    my_putstr_file("\n", save);

    my_putnbr_file(player->save->value[0].act, save);
    my_putstr_file(",", save);
    my_putnbr_file(player->save->value[0].max, save);
    my_putstr_file(",", save);
    my_putstr_file("\n", save);

    my_putnbr_file(player->save->value[1].act, save);
    my_putstr_file(",", save);
    my_putnbr_file(player->save->value[1].max, save);
    my_putstr_file(",", save);
    my_putstr_file("\n", save);

    my_putnbr_file(player->save->value[2].act, save);
    my_putstr_file(",", save);
    my_putnbr_file(player->save->value[2].max, save);
    my_putstr_file(",", save);
    my_putstr_file("\n", save);

    for (int i = 0; i != 8; i++) {
        my_putnbr_file(player->save->properties[i], save);
        my_putstr_file("\n", save);
    }
    fclose(save);
}
