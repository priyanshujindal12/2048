#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 4

void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]);

void addRandomTile(int board[BOARD_SIZE][BOARD_SIZE]);

void resetBoard(int board[BOARD_SIZE][BOARD_SIZE]);

#endif