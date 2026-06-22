#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "grid.h"

int matrix[X][Y];

int main(void) {
    srand(time(NULL));

    populate(matrix);
    display(matrix);

    for (int i = 0; i < STEPS + 1; i++) {
        events(matrix);
        burn(matrix);
        display(matrix);
        usleep(TIME);
        printf("Kroki: [%i/%i] \n", i, STEPS);
    }
    return 0;
}
