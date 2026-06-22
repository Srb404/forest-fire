#ifndef GRID_H
#define GRID_H

#define X 10
#define Y 10
#define p 0.01
#define f 0.001

enum Cell {
    EMPTY  = 0,
    TREE   = 1,
    BURNING = 2,
    NEW_TREE = 10,
    NEW_BURNING = 100
};

void populate(int matrix[X][Y]);
void display(int matrix[X][Y]);
void burn(int matrix[X][Y]);
void naturalEvents(int matrix[X][Y]);

#endif
