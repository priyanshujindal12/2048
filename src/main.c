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

    char choice;

    while (1) {

        printBoard(&game);

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        int changed = 0;

        switch (choice) {

            case 'w':
            case 'W':
                changed = moveUp(&game);
                break;

            case 'a':
            case 'A':
                changed = moveLeft(&game);
                break;

            case 's':
            case 'S':
                changed = moveDown(&game);
                break;

            case 'd':
            case 'D':
                changed = moveRight(&game);
                break;

            case 'r':
            case 'R':
                initializeGame(&game);
                addRandomTile(game.board);
                addRandomTile(game.board);
                continue;

            case 'u':
            case 'U':
                printf("\nThanks for playing!\n");
                return 0;

            default:
                printf("\nInvalid choice. Use W, A, S, D, R or U.\n");
                continue;
        }

        /*
         * Only add a new tile if the board actually changed.
         */
        if (changed) {
            addRandomTile(game.board);
        }

        /*
         * Check whether no more moves are possible.
         */
        if (isGameOver(&game)) {
            printBoard(&game);

            printf("\n==============================\n");
            printf("          GAME OVER!\n");
            printf("==============================\n");
            printf("Final Score: %d\n", game.score);

            break;
        }
    }

    return 0;
}