#include "game.h"
static int moveLineLeft(int line[BOARD_SIZE])
{
    int original[BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        original[i] = line[i];
    }

    // Remove zeros
    int position = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != 0) {
            line[position++] = line[i];
        }
    }

    while (position < BOARD_SIZE) {
        line[position++] = 0;
    }

    // Merge equal tiles
    for (int i = 0; i < BOARD_SIZE - 1; i++) {

        if (line[i] != 0 && line[i] == line[i + 1]) {

            line[i] *= 2;

            line[i + 1] = 0;

            i++;
        }
    }

    // Remove zeros again
    position = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != 0) {
            line[position++] = line[i];
        }
    }

    while (position < BOARD_SIZE) {
        line[position++] = 0;
    }

    // Check whether anything changed
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != original[i]) {
            return 1;
        }
    }

    return 0;
}


int moveLeft(int board[BOARD_SIZE][BOARD_SIZE])
{
    int changed = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {

        if (moveLineLeft(board[row])) {
            changed = 1;
        }
    }

    return changed;
}


int moveRight(int board[BOARD_SIZE][BOARD_SIZE])
{
    int changed = 0;

    int line[BOARD_SIZE];

    for (int row = 0; row < BOARD_SIZE; row++) {

        // Reverse row
        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = board[row][BOARD_SIZE - 1 - i];
        }

        if (moveLineLeft(line)) {
            changed = 1;
        }

        // Reverse back
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[row][BOARD_SIZE - 1 - i] = line[i];
        }
    }

    return changed;
}


int moveUp(int board[BOARD_SIZE][BOARD_SIZE])
{
    int changed = 0;

    int line[BOARD_SIZE];

    for (int column = 0; column < BOARD_SIZE; column++) {

        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = board[i][column];
        }

        if (moveLineLeft(line)) {
            changed = 1;
        }

        for (int i = 0; i < BOARD_SIZE; i++) {
            board[i][column] = line[i];
        }
    }

    return changed;
}


int moveDown(int board[BOARD_SIZE][BOARD_SIZE])
{
    int changed = 0;

    int line[BOARD_SIZE];

    for (int column = 0; column < BOARD_SIZE; column++) {

        // Read column from bottom to top
        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = board[BOARD_SIZE - 1 - i][column];
        }

        if (moveLineLeft(line)) {
            changed = 1;
        }

        // Write back bottom to top
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[BOARD_SIZE - 1 - i][column] = line[i];
        }
    }

    return changed;
}


int isGameOver(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++) {

        for (int column = 0; column < BOARD_SIZE; column++) {

            // Empty cell means moves are still possible
            if (board[row][column] == 0) {
                return 0;
            }

            // Check right neighbor
            if (column < BOARD_SIZE - 1 &&
                board[row][column] == board[row][column + 1]) {
                return 0;
            }

            // Check bottom neighbor
            if (row < BOARD_SIZE - 1 &&
                board[row][column] == board[row + 1][column]) {
                return 0;
            }
        }
    }

    return 1;
}