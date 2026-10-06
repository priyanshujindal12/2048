#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int score;
    int highScore;
} Game;

void initializeGame(Game *game);

int moveLeft(Game *game);
int moveRight(Game *game);
int moveUp(Game *game);
int moveDown(Game *game);

int isGameOver(const Game *game);

#endif