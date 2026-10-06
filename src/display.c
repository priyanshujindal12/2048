#include <stdio.h>

#include "display.h"


static int findLength(int number)
{
    int length = 0;

    if (number == 0) {
        return 1;
    }

    while (number != 0) {
        length++;
        number /= 10;
    }

    return length;
}

void printBoard(const Game *game){
    printf("\n");
    printf("\t\t\t\t\t===============2048==============\n");
    printf("\t\t\t\t\tYOUR SCORE=%d\n", game->score);
    printf("\t\t\t\t\tHIGH SCORE=%d\n", game->highScore);
    printf("\t\t\t\t\t---------------------------------\n");

    for (int i = 0; i < BOARD_SIZE; i++) {

        for (int j = 0; j < BOARD_SIZE; j++) {

            if (j == 0) {
                printf("\t\t\t\t\t|");
            }

            if (game->board[i][j] != 0) {

                int length = findLength(game->board[i][j]);

                for (int k = 0; k < 4 - length; k++) {
                    printf(" ");
                }

                printf("%d", game->board[i][j]);

                for (int k = 0; k < 4 - length; k++) {
                    printf(" ");
                }

                printf("|");

            } else {

                for (int k = 0; k < 7; k++) {
                    printf(" ");
                }

                printf("|");
            }
        }

        if (i != BOARD_SIZE - 1) {
            printf("\n");
            printf("\t\t\t\t\t---------------------------------\n");
        }
    }

    printf("\n");
    printf("\t\t\t\t\t---------------------------------\n");

    printf("\t\t\t\t\tPREV -> P\n");
    printf("\t\t\t\t\tRESTART -> R\n");
    printf("\t\t\t\t\tEXIT -> U\n");

    printf("\t\t\t\t\tENTER YOUR CHOICE -> W,S,A,D\n");
}