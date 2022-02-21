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

int check_line(char *buffer)
{
    if (my_strlen(buffer) > 8 || buffer[1] != ':' || buffer[4] != ':')
        return (0);
    if (buffer[0] < '2' || buffer[0] > '5')
        return (0);
    if (buffer[2] > 'H' || buffer[2] < 'A' || buffer[3] < '1'
    || buffer[3] > '8')
        return (0);
    if (buffer[5] > 'H' || buffer[5] < 'A' || buffer[6] < '1'
    || buffer[6] > '8')
        return (0);
    return (1);
}

int check_map(char *path)
{
    FILE *fd = fopen(path, "r");
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t read;
    int lines = 0;

    if (fd == NULL)
        return (0);
    read = getline(&buffer, &bufsize, fd);
    while (read != -1) {
        if (check_line(buffer) == 0)
            return (0);
        lines++;
        read = getline(&buffer, &bufsize, fd);
    }
    free(buffer);
    fclose(fd);
    if (lines != 4)
        return (0);
    return (1);
}
