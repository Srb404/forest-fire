#ifndef GRID_H
#define GRID_H

#define X 50
#define Y 130
#define TREE_CHANCE 0.01
#define FIRE_CHANCE 0.001
#define STEPS 100
#define TIME 500000

enum Cell {
    EMPTY = 0,
    TREE = 1,
    BURNING = 2,
    NEW_TREE = 10,
    NEW_BURNING = 20
};

void populate(int matrix[X][Y]);
void display(int matrix[X][Y]);
void burn(int matrix[X][Y]);
void events(int matrix[X][Y]);

#endif