#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "grid.h"

int main(void) {
    srand(time(NULL));

    int matrix[X][Y];

    populate(matrix);
    display(matrix);

    const int steps = 10;
    const int time = 500000; // 0.5 s
    for (int i = 0; i < steps + 1; i++) {
        burn(matrix);
        naturalEvents(matrix);
        display(matrix);
        usleep(time);
    }

    printf("Wykonane kroki: [%i] \n", steps);
    return 0;
}
