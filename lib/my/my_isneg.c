/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** Prints either N if a given number is negative or P if it is positive.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
}
