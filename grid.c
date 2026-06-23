#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

#define C_EMPTY       "\033[38;5;236m"
#define C_TREE        "\033[38;5;34m"
#define C_NEW_TREE    "\033[38;5;46m"
#define C_BURNING     "\033[38;5;202m"
#define C_NEW_BURNING "\033[38;5;226m"
#define C_RESET       "\033[0m"

void display(int matrix[ROWS][COLS]) {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (matrix[i][j]) {
                case EMPTY:
                    printf(C_EMPTY "▒▒" C_RESET);
                    break;
                case TREE:
                    printf(C_TREE "██" C_RESET);
                    break;
                case NEW_TREE:
                    printf(C_NEW_TREE "██" C_RESET);
                    break;
                case BURNING:
                    printf(C_BURNING "██" C_RESET);
                    break;
                case NEW_BURNING:
                    printf(C_NEW_BURNING "██" C_RESET);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void populate(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) matrix[i][j] = TREE;
            else matrix[i][j] = EMPTY;
        }
    }
}

void events(int matrix[ROWS][COLS]) {
    float random;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (matrix[i][j]) {
                case NEW_TREE:
                    matrix[i][j] = TREE;
                    break;
                case NEW_BURNING:
                    matrix[i][j] = BURNING;
                    break;
            }
            switch (matrix[i][j]) {
                case EMPTY:
                    random = (rand() % 1000 + 1) / 1000.0;
                    if (random <= TREE_CHANCE) matrix[i][j] = NEW_TREE;
                    break;
                case TREE:
                    random = (rand() % 10000 + 1) / 10000.0;
                    if (random <= FIRE_CHANCE) matrix[i][j] = NEW_BURNING;
                    break;
            }
        }
    }
}

void burn(int matrix[ROWS][COLS]) {
    int matrixFuture[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == BURNING) {
                matrix[i][j] = EMPTY;
                if (i > 0       && matrix[i - 1][j]     == TREE) matrixFuture[i - 1][j] = BURNING;
                if (i < ROWS - 1   && matrix[i + 1][j]     == TREE) matrixFuture[i + 1][j] = BURNING;
                if (j > 0       && matrix[i][j - 1]     == TREE) matrixFuture[i][j - 1] = BURNING;
                if (j < COLS - 1   && matrix[i][j + 1]     == TREE) matrixFuture[i][j + 1] = BURNING;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrixFuture[i][j] == BURNING) {
                matrixFuture[i][j] = EMPTY;
                matrix[i][j] = BURNING;
            }
        }
    }
}