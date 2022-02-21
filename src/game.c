/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "../include/my.h"
#include "../include/navy.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int game_winner(char **map, char **enemy_map)
{
    int enemy = 0;
    int player = 0;

    for (int l = 0; l < 8; l++) {
        for (int c = 0; c < 8; c++) {
            player = map[l][c] == 'x' ? player + 1 : player;
            enemy = enemy_map[l][c] == 'x' ? enemy + 1 : enemy;
        }
    }
    if (player == 14)
        return (2);
    if (enemy == 14)
        return (1);
    return (0);
}

int put_hit(char **map, int message, char ch)
{
    int line = (message - 1) / 8;
    int col = (message - 1) % 8;

    if (col == -1)
        col = 7;
    if (ch) {
        map[line][col] = ch;
        return (0);
    }
    else {
        if (map[line][col] == '.') {
            map[line][col] = 'o';
            return (2);
        } else {
            map[line][col] = 'x';
            return (1);
        }
    }
}

void turn_one(char **pos, char **enemy_map)
{
    int to_send;
    int received = 0;

    usleep(10667);
    if (game.winner != 0)
        return;
    if (game.player == 1)
        print_positions(pos, enemy_map);
    else
        my_printf("\n");
    to_send = get_user_input();
    send_message(to_send);
    received = receive_message(1);
    received = received < 50 ? 41 : received;
    put_hit(enemy_map, to_send, received == 41 ? 'x' : 'o');
    my_printf("%c%c: %s\n", get_pos_col(to_send), get_pos_line(to_send),
    received == 41 ? "hit" : "missed");
    usleep(10667);
}

void turn_two(char **pos, char **enemy_map)
{
    int received = 0;
    int hit = 0;

    usleep(10667);
    if (game.winner != 0)
        return;
    if (game.player == 2)
        print_positions(pos, enemy_map);
    else
        my_printf("\n");
    received = receive_message(0);
    hit = put_hit(pos, received, (char)0);
    send_message(hit == 1 ? 42 : 84);
    my_printf("%c%c: %s\n", get_pos_col(received), get_pos_line(received),
    hit == 1 ? "hit" : "missed");
    usleep(10667);
}

int start_game(char **pos)
{
    char **enemy_map = get_empty_map();

    if (game.player == 2) {
        turn_two(pos, enemy_map);
    }
    while (game.winner == 0) {
        turn_one(pos, enemy_map);
        game.winner = game_winner(pos, enemy_map);
        turn_two(pos, enemy_map);
        game.winner = game_winner(pos, enemy_map);
    }
    print_positions(pos, enemy_map);
    free(pos);
    free(enemy_map);
    return (game.winner - 1);
}
