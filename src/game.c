#include "game.h"

void initializeGame(Game *game)
{
    initializeBoard(game->board);

    game->score = 0;
    game->highScore = 0;
}

static int moveLineLeft(int line[BOARD_SIZE], int *score)
{
    int original[BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        original[i] = line[i];
    }

    // removing zeros for better user expereience
    int position = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != 0) {
            line[position++] = line[i];
        }
    }

    while (position < BOARD_SIZE) {
        line[position++] = 0;
    }

    /* Merge equal tiles like 2 2  4 4  */
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        if (line[i] != 0 && line[i] == line[i + 1]) {

            line[i] *= 2;

            
            *score += line[i]; // add valu1e to score

            line[i + 1] = 0;

            i++;
        }
    }

    // after merger removing zeros for better user expereience
    position = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != 0) {
            line[position++] = line[i];
        }
    }

    while (position < BOARD_SIZE) {
        line[position++] = 0;
    }

//check if line change or nor if not then game is over
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != original[i]) {
            return 1;
        }
    }

    return 0;
}

static void updateHighScore(Game *game)
{
    if (game->score > game->highScore) {
        game->highScore = game->score;
    }
}

int moveLeft(Game *game)
{
    int changed = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {

        if (moveLineLeft(game->board[row], &game->score)) {
            changed = 1;
        }
    }

    updateHighScore(game);

    return changed;
}

int moveRight(Game *game)
{
    int changed = 0;
    int line[BOARD_SIZE];

    for (int row = 0; row < BOARD_SIZE; row++) {

        /* Reverse row */
        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = game->board[row][BOARD_SIZE - 1 - i];
        }

        if (moveLineLeft(line, &game->score)) {
            changed = 1;
        }

        /* Reverse back */
        for (int i = 0; i < BOARD_SIZE; i++) {
            game->board[row][BOARD_SIZE - 1 - i] = line[i];
        }
    }

    updateHighScore(game);

    return changed;
}

int moveUp(Game *game)
{
    int changed = 0;
    int line[BOARD_SIZE];

    for (int column = 0; column < BOARD_SIZE; column++) {

        /* Copy column */
        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = game->board[i][column];
        }

        if (moveLineLeft(line, &game->score)) {
            changed = 1;
        }

        /* Copy back */
        for (int i = 0; i < BOARD_SIZE; i++) {
            game->board[i][column] = line[i];
        }
    }

    updateHighScore(game);

    return changed;
}

int moveDown(Game *game)
{
    int changed = 0;
    int line[BOARD_SIZE];

    for (int column = 0; column < BOARD_SIZE; column++) {

       
        for (int i = 0; i < BOARD_SIZE; i++) {
            line[i] = game->board[BOARD_SIZE - 1 - i][column];
        }

        if (moveLineLeft(line, &game->score)) {
            changed = 1;
        }

  
        for (int i = 0; i < BOARD_SIZE; i++) {
            game->board[BOARD_SIZE - 1 - i][column] = line[i];
        }
    }

    updateHighScore(game);

    return changed;
}

int isGameOver(const Game *game)
{
    for (int row = 0; row < BOARD_SIZE; row++) {

        for (int column = 0; column < BOARD_SIZE; column++) {

            /* Empty cell means game is not over */
            if (game->board[row][column] == 0) {
                return 0;
            }

            /* Check horizontal neighbour */
            if (column < BOARD_SIZE - 1 &&
                game->board[row][column] ==
                game->board[row][column + 1]) {
                return 0;
            }

            /* Check vertical neighbour */
            if (row < BOARD_SIZE - 1 &&
                game->board[row][column] ==
                game->board[row + 1][column]) {
                return 0;
            }
        }
    }

    return 1;
}