#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "board.h"


int main(void){
    srand((unsigned int)time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    addRandomTile(board);
    addRandomTile(board);
    int score = 0;
    int highScore = 0;
    printBoard(board, score, highScore);
    return 0;
}