/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Main entry point for the navy project
*/

#include "../include/navy.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

game_t game;

void sighandler(int sig, siginfo_t *si, void *ptr)
{
    if (game.player == 1)
        game.pid_2 = si->si_pid;
    else
        game.pid_1 = si->si_pid;
}

void init_player(struct sigaction *sa, int player)
{
    int pid = getpid();

    game.player = player;
    game.pid_1 = 0;
    game.pid_2 = 0;
    game.winner = 0;
    if (game.player == 1)
        game.pid_1 = pid;
    else
        game.pid_2 = pid;
    sa->sa_flags = SA_SIGINFO;
    sa->sa_sigaction = sighandler;
    sigemptyset(&sa->sa_mask);
    my_printf("my_pid: %i\n", pid);
}

int player_one(char **map)
{
    struct sigaction sa;
    int result = 0;

    init_player(&sa, 1);
    my_printf("waiting for enemy connection...\n");
    sigaction(SIGUSR1, &sa, NULL);
    while (game.pid_2 == 0)
        pause();
    kill(game.pid_2, SIGUSR1);
    my_printf("\nenemy connected\n");
    result = start_game(map);
    if (result == 0)
        my_printf("I won\n");
    else
        my_printf("Enemy won\n");
    return (result);
}

int player_two(int pid, char **map)
{
    struct sigaction sa;
    int result = 0;

    init_player(&sa, 2);
    kill(pid, SIGUSR1);
    sigaction(SIGUSR1, &sa, NULL);
    while (game.pid_1 == 0)
        pause();
    my_printf("successfully connected\n");
    result = start_game(map);
    if (result == 0)
        my_printf("I won\n");
    else
        my_printf("Enemy won\n");
    return (result);
}
