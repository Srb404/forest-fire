#ifndef GRID_H
#define GRID_H

#define ROWS 30
#define COLS 35
#define TREE_CHANCE 0.01
#define FIRE_CHANCE 0.001
#define STEPS 100
#define TIME 50000

enum Cell {
    EMPTY = 0,
    TREE = 1,
    BURNING = 2,
    NEW_TREE = 10,
    NEW_BURNING = 20
};

void populate(int matrix[ROWS][COLS]);
void display(int matrix[ROWS][COLS]);
void burn(int matrix[ROWS][COLS]);
void events(int matrix[ROWS][COLS]);

#endif