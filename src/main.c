#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "display.h"
#include "game.h"

int main(void)
{
    srand((unsigned int)time(NULL));

    Game game;

    initializeGame(&game);

    addRandomTile(game.board);
    addRandomTile(game.board);

    printBoard(&game);

    printf("\nTesting move left...\n");

    moveLeft(&game);

    printBoard(&game);

    printf("\nScore: %d\n", game.score);
    printf("High Score: %d\n", game.highScore);

    return 0;
}