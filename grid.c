#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

int matrixFuture[X][Y];

void populate(int matrix[X][Y], enum Cell cell) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            matrix[i][j] = cell;
        }
    }
}

void normalizePopulation(int matrix[X][Y]) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (rand() % 2 == 0) matrix[i][j] = EMPTY;
        }
    }
}

#define C_EMPTY       "\033[38;5;236m"  // ciemny szary  - pusta ziemia
#define C_TREE        "\033[38;5;34m"   // zielony       - drzewo
#define C_NEW_TREE    "\033[38;5;46m"   // jasnozielony  - swieze drzewo
#define C_BURNING     "\033[38;5;202m"  // pomaranczowy  - ogien
#define C_NEW_BURNING "\033[38;5;226m"  // zolty         - swiezo zapalone
#define C_RESET       "\033[0m"

void display(int matrix[X][Y]) {
    system("clear");
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
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

void thunder(int matrix[X][Y]) {
    int row = rand() % X;
    int col = rand() % Y;
    if (matrix[row][col] == TREE) matrix[row][col] = BURNING;
}

void naturalEvents(int matrix[X][Y]) {
    float random;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (matrix[i][j] == EMPTY) {
                random = (rand() % 1000 + 1) / 1000.0;
                if (random <= p) matrix[i][j] = NEW_TREE;
            }
            else if (matrix[i][j] == TREE) {
                random = (rand() % 10000 + 1) / 10000.0;
                if (random <= f) matrix[i][j] = NEW_BURNING;
            }
        }
    }
}

void newNaturalEventsRecolour(int matrix[X][Y]) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (matrix[i][j] == NEW_TREE) matrix[i][j] = TREE;
            else if (matrix[i][j] == NEW_BURNING) matrix[i][j] = BURNING;
        }
    }
}

void burn(int matrix[X][Y]) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (matrix[i][j] == BURNING) {
                matrix[i][j] = EMPTY;
                if (i > 0 && matrix[i - 1][j] == TREE) matrixFuture[i - 1][j] = BURNING;
                if (i < X - 1 && matrix[i + 1][j] == TREE) matrixFuture[i + 1][j] = BURNING;
                if (j > 0 && matrix[i][j - 1] == TREE) matrixFuture[i][j - 1] = BURNING;
                if (j < Y - 1 && matrix[i][j + 1] == TREE) matrixFuture[i][j + 1] = BURNING;
            }
        }
    }

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (matrixFuture[i][j] == BURNING) {
                matrixFuture[i][j] = EMPTY;
                matrix[i][j] = BURNING;
            }
        }
    }
}