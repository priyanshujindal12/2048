#include <stdio.h>

#define SIZE 4

int main() {
    int board[SIZE][SIZE] = {0};

    printf("2048 Game\n\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}