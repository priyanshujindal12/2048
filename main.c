#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#define SIZE 4
void addRandomTile(int board[SIZE][SIZE]) {
    int emptyCells = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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

    // Find that empty cell
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                if (count == randomIndex) {
                    // Randomly decide whether to place a 2 or a 4 (90% chance for 2, 10% chance for 4) most of the time 2 appears 
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
void printBoard(int board[SIZE][SIZE]) {
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("+------+------+------+------+\n");

        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("|      ");
            } else {
                printf("|  %4d", board[i][j]);
            }
        }

        printf("|\n");
    }

    printf("+------+------+------+------+\n");
}

int main() {

    int board[SIZE][SIZE] = {0};

    // Temporary values for testing
    board[0][0] = 2;
    board[0][2] = 4;
    board[1][1] = 8;
    board[2][3] = 16;
    board[3][0] = 32;

    printf("=========== 2048 ===========\n");

    printBoard(board);

    return 0;
}