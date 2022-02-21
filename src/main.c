/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Main entry point for the navy project
*/

#include "../include/my.h"
#include "../include/navy.h"
#include <stdlib.h>

void put_usage(void)
{
    my_putstr("USAGE\n"
    "\t./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "\tfirst_player_pid: only for the 2nd player. pid of the first player.\n"
    "\tnavy_positions: file representing the positions of the ships.\n");
}

int check_args(int ac, char **av)
{
    if (ac == 1 || ac > 3) {
        my_putstr_err("./navy: no or too much arguments given\n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        put_usage();
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int pid = -1;
    char **map;

    if (check_args(ac, av) == 84)
        return (84);
    pid = my_getnbr(av[1]);
    if (ac == 2 && check_map(av[1])) {
        map = get_map(av[1]);
        if (map == NULL)
            return (84);
        return (player_one(map));
    }
    if (ac == 3 && pid > 0 && check_map(av[2])) {
        map = get_map(av[2]);
        if (map == NULL)
            return (84);
        return (player_two(pid, map));
    }
    return (84);
}
