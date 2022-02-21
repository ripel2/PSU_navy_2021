/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Map functions
*/

#include "../include/navy.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int abs(int nb)
{
    return (nb >= 0 ? nb : -1 * nb);
}

int check_length(char *buffer)
{
    int offset = buffer[0] - '0';
    int x1 = buffer[2] - 'A';
    int y1 = buffer[3] - '1';
    int x2 = buffer[5] - 'A';
    int y2 = buffer[6] - '1';

    if (x1 != x2 && y1 != y2)
        return (1);
    if (x1 == x2 && (abs(y2 - y1) + 1) != offset)
        return (1);
    if (y1 == y2 && (abs(x2 - x1) + 1) != offset)
        return (1);
    return (0);
}

int put_boat(char *buffer, char **map, int *boats)
{
    int offset = buffer[0] - '0';
    int x1 = buffer[2] - 'A';
    int y1 = buffer[3] - '1';

    if (check_length(buffer) == 1)
        return (1);
    if (boats[offset] == 1)
        return (1);
    boats[offset] = 1;
    for (int o = 0; o < offset; o++) {
        if (map[y1][x1] != '.')
            return (1);
        map[y1][x1] = '0' + offset;
        y1 = buffer[2] == buffer[5] ? y1 + 1 : y1;
        x1 = buffer[3] == buffer[6] ? x1 + 1 : x1;
    }
    return (0);
}

char **get_map(char *path)
{
    char **map = get_empty_map();
    FILE *fd = fopen(path, "r");
    char *buffer = NULL;
    size_t bufsize = 32;
    int *boats = malloc(sizeof(long) * 6);

    if (fd == NULL)
        return (NULL);
    for (int c = 0; c < 6; c++, boats[c] = 0);
    getline(&buffer, &bufsize, fd);
    for (int c = 0; c < 4; c++) {
        if (put_boat(buffer, map, boats) == 1)
            return (NULL);
        getline(&buffer, &bufsize, fd);
    }
    return (map);
}

char **get_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 8);

    for (int c = 0; c < 8; c++) {
        map[c] = malloc(sizeof(char) * 9);
        my_strcpy(map[c], "........");
    }
    return (map);
}
