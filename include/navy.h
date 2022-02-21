/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#pragma once

typedef struct game {
    int player;
    int pid_1;
    int pid_2;
    int sigcount;
    int sig2;
    int last_hit;
    int winner;
} game_t;

extern game_t game;

int check_map(char *path);
char **get_map(char *path);
char **get_empty_map(void);
void print_map(char **map);
void print_positions(char **map, char **enemy_map);

int player_one(char **map);
int player_two(int pid, char **map);

int start_game(char **pos);

void send_message(int msg);
int receive_message(int);

int get_user_input(void);
char get_pos_col(int pos);
char get_pos_line(int pos);
