/*
** EPITECH PROJECT, 2021
** navy
** File description:
** print positions
*/

#include "../include/my.h"
#include "../include/navy.h"

void print_map(char **map)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    char tmp[17] = {0};

    for (int c = 0; c < 8; c++) {
        for (int d = 0; d < 16; d++) {
            tmp[d] = d % 2 == 0 ? map[c][d / 2] : ' ';
        }
        my_printf("%i|%s\n", c + 1, tmp);
    }
}

void print_positions(char **map, char **enemy_map)
{
    my_printf("\nmy positions:\n");
    print_map(map);
    my_printf("\nenemy's positions:\n");
    print_map(enemy_map);
    my_printf("\n");
}
