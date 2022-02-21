/*
** EPITECH PROJECT, 2021
** navy
** File description:
** communications
*/

#include "../include/my.h"
#include "../include/navy.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void comhandler(int sig, siginfo_t *si, void *ptr)
{
    if (sig == SIGUSR1)
        game.sigcount++;
    if (sig == SIGUSR2)
        game.sig2++;
}

void send_message(int msg)
{
    int pid = game.player == 1 ? game.pid_2 : game.pid_1;

    for (int c = 0; c < msg; c++) {
        kill(pid, SIGUSR1);
        usleep(1667);
    }
    usleep(1667);
    kill(pid, SIGUSR2);
}

int receive_message(int answer)
{
    struct sigaction sa;
    int msg = 0;

    if (game.winner != 0)
        return (-1);
    if (answer == 0)
        my_printf("waiting for enemy's attack...\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = comhandler;
    sigemptyset(&sa.sa_mask);
    game.sig2 = 0;
    game.sigcount = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (game.sig2 < 1)
        pause();
    game.sig2 = 0;
    msg = game.sigcount;
    game.sigcount = 0;
    return (msg);
}
