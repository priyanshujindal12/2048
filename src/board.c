#include <stdlib.h>
#include "board.h"
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}


void addRandomTile(int board[BOARD_SIZE][BOARD_SIZE])
{
    int emptyCells = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCells++;
            }
        }
    }

  
    if (emptyCells == 0) {
        return;
    }

    // Select a random empty cell
    int randomIndex = rand() % emptyCells;

    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {

            if (board[i][j] == 0) {

                if (count == randomIndex) {

                    if (rand() % 10 == 0) {
                        board[i][j] = 4;
                    } else {
                        board[i][j] = 2;
                    }

                    return;
                }

                count++;
            }
        }
    }
}


void resetBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}