#include <stdio.h>
#include "game-of-life.h"

int main(void) {
    Grid* grid = init_generation();

    printf("\n------ Generation 0 -----\n\n");
    display(grid);

    int n;
    for (n = 1; n <= NUMBER_OF_GENERATIONS; n++) {
        grid = next_generation(grid, evolve_cell);

        printf("\n------ Generation %d -----\n\n", n);
        display(grid);
    }

    destroy(grid);

    return 0;
}
