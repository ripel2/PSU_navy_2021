/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** Copy of the strstr function
*/

#include <stdio.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int strlen;
    char *res = str;

    for (int c = 0; to_find[c] != '\0'; c++)
        strlen++;
    while (*res != '\0') {
        if (my_strncmp(res, to_find, strlen) == 0)
            return (res);
        res++;
    }
    return NULL;
}
