#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "grid.h"

int main(void) {
    srand(time(NULL));

    int matrix[X][Y];

    populate(matrix, TREE);
    normalizePopulation(matrix);
    display(matrix);

    int steps = 250;
    int time = 50000; // 0.05 s
    for (int i = 0; i < steps + 1; i++) {
        newNaturalEventsRecolour(matrix);
        burn(matrix);
        naturalEvents(matrix);
        display(matrix);
        usleep(time);
    }

    printf("Wykonane kroki: [%i] \n", steps);
    return 0;
}
