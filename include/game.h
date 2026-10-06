#ifndef GAME_H
#define GAME_H

#include "board.h"

int moveLeft(int board[BOARD_SIZE][BOARD_SIZE]);
int moveRight(int board[BOARD_SIZE][BOARD_SIZE]);
int moveUp(int board[BOARD_SIZE][BOARD_SIZE]);
int moveDown(int board[BOARD_SIZE][BOARD_SIZE]);

int isGameOver(int board[BOARD_SIZE][BOARD_SIZE]);

#endif