/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** thread.c
*/

#include "rpg.h"

sfFtp *connect_ftp(void)
{
    sfFtp *ftp = sfFtp_create();
    sfFtpResponse *response = NULL;

    my_printf("%sConnection to %sftp server %s...%s\n"
        , LCYAN, PURPLE, LCYAN, RESET);
    response = sfFtp_connect(ftp, dl_ip, dl_port, (sfTime){10});
    if (sfFtpResponse_isOk(response) == sfFalse)
        return (my_printf(NO_CONNECT), NULL);
    my_printf("%sSuccessfully connected.%s\n", LGREEN, RESET);
    sfFtpResponse_destroy(response);
    return (ftp);
}

int login_and_move(sfFtp *ftp)
{
    sfFtpResponse *response = NULL;
    const char *message = NULL;

    response = sfFtp_loginAnonymous(ftp);
    message = sfFtpResponse_getMessage(response);
    if (sfFtpResponse_isOk(response) == sfFalse)
        return (my_printf("%s%s%s", LRED, message, RESET), 84);
    my_printf("%sSuccessfuly login to.%s\n", LGREEN, RESET);
    response = sfFtp_changeDirectory(ftp, "kbJwVChK/ressources_csfml/");
    message = sfFtpResponse_getMessage(response);
    if (sfFtpResponse_isOk(response) == sfFalse)
        return (my_printf("%s%s%s", LRED, message, RESET), 84);
    my_printf(MOVE_DIR);
    sfFtpResponse_destroy(response);
    return (0);
}

void download(sfFtp *ftp)
{
    sfFtpResponse *response = NULL;

    for (int ctr = 0; download_rsc_prefab[ctr].id != DL_RSC_END; ctr += 1) {
        if (open(concat_fstring("%s%s", download_rsc_prefab[ctr].path
            , download_rsc_prefab[ctr].name), O_RDONLY) >= 0)
            continue;
        my_printf(DL_PROCESS(download_rsc_prefab[ctr].name));
        response = sfFtp_download(ftp, download_rsc_prefab[ctr].name
            , download_rsc_prefab[ctr].path, sfFtpAscii);
        if (sfFtpResponse_isOk(response) == sfFalse)
            my_printf(DL_ERROR(download_rsc_prefab[ctr].name));
        else
            my_printf("%sSuccessfully download.%s\n", LGREEN, RESET);
    }
    sfFtpResponse_destroy(response);
}

void download_from_ftp(void *data)
{
    (void)(data);
    sfFtp *ftp = connect_ftp();

    if (ftp == NULL)
        return;
    if (login_and_move(ftp) == 84) {
        sfFtp_disconnect(ftp);
        return;
    }
    download(ftp);
    sfFtp_disconnect(ftp);
}

int main(void)
{
    sfThread *download_thread = sfThread_create(&download_from_ftp, NULL);
    sfRenderWindow *rwindow = sfRenderWindow_create((sfVideoMode){600, 300, 32}, "Test", sfClose, NULL);
    sfEvent event;
    sfTexture *txt = sfTexture_createFromFile("rsc/back.png", NULL);
    sfSprite *spr = sfSprite_create();

    sfSprite_setTexture(spr, txt, sfTrue);
    sfSprite_setPosition(spr, (sfVector2f){0, 0});
    sfThread_launch(download_thread);
    while (sfRenderWindow_isOpen(rwindow)) {
        while (sfRenderWindow_pollEvent(rwindow, &event)) {
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
                sfThread_terminate(download_thread);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(rwindow);
            sfRenderWindow_clear(rwindow, sfBlack);
            sfRenderWindow_drawSprite(rwindow, spr, NULL);
            sfRenderWindow_display(rwindow);
        }
    }
    sfThread_terminate(download_thread);
    sfThread_destroy(download_thread);
    return (0);
}