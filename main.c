#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "grid.h"

int matrix[ROWS][COLS];

int main(void) {
    srand(time(NULL));

    populate(matrix);
    display(matrix);

    for (int i = 0; i < STEPS; i++) {
        events(matrix);
        burn(matrix);
        display(matrix);
        printf("Steps: [%i/%i] \n", i + 1, STEPS);
        usleep(TIME);
    }
    return 0;
}
