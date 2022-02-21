
# Navy

A battleship game that uses signals to communicate 

## About this project

This project is an introduction to signals in C,
where we have to use them to communicate the player's actions.

## How to use

First compile with the Makefile

```sh
make
```

Then launch the program by typing
```sh
./navy pos1
```

To connect the second player, launch the program in another terminal and
input the first player's PID before the map
```sh
./navy <pid> pos2
```

To exit the program, finish the game or Ctrl+C

## Features

- Checks the PID before connecting
- Doesn't accept bad positions
- Returns the game status when the program ends
