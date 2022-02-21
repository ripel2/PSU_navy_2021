/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Get user input
*/

#include "../include/navy.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int pos_to_int(char *pos)
{
    int nbr = 42;
    int line = 0;
    int col = 0;
    int res = 0;

    if (my_strlen(pos) > 3)
        return (-1);
    if (pos[0] > 'H' || pos[0] < 'A' || my_is_nbr(pos[1]) == 0)
        return (-1);
    nbr = my_getnbr(&pos[1]);
    if (nbr > 8 || nbr < 1)
        return (-1);
    col = pos[0] - 'A';
    line = pos[1] - '1' ;
    res = line * 8 + col + 1;
    return (res);
}

int get_user_input(void)
{
    int msg = -1;
    char *buffer = NULL;
    size_t bufsize = 32;

    do {
        my_printf("attack: ");
        getline(&buffer, &bufsize, stdin);
        msg = pos_to_int(buffer);
        if (msg <= 0) {
            my_printf("wrong position\n");
        }
    } while (msg <= 0);
    free(buffer);
    return (msg);
}

char get_pos_col(int pos)
{
    int c = (pos - 1) % 8;

    if (c < 0)
        c = 8;
    return ('A' + c);
}

char get_pos_line(int pos)
{
    pos--;
    return ('1' + (pos) / 8);
}
