#include <stdio.h>
#include <assert.h>
#include "game-of-life.h"

void print_cells(Cell cells[NUMBER_OF_NEIGHBORS]);

void test_random_cell(void);
void test_evolve_cell(void);

int main(void) {
    test_random_cell();
    test_evolve_cell();
}

void test_random_cell(void) {
    assert(random_cell(1) == ALIVE);
    assert(random_cell(0) == DEAD);

    srand(time(NULL));

    char cells[NUMBER_OF_NEIGHBORS] = {};
    int i;
    for (i = 0; i < NUMBER_OF_NEIGHBORS; i++) {
        cells[i] = random_cell(0.5);
    }

    printf("Random: ");
    print_cells(cells);

    assert(count_alive(cells, NUMBER_OF_NEIGHBORS) > 0);
    assert(count_alive(cells, NUMBER_OF_NEIGHBORS) < 8);
}

void test_evolve_cell(void) {
    int n;
    for (n = 0; n <= NUMBER_OF_NEIGHBORS; n++) {
        /* Create an array of eight neighbors,
           where n are alive and the rest is dead. */

        Cell neighbors[NUMBER_OF_NEIGHBORS];
        int i;
        for (i = 0; i < NUMBER_OF_NEIGHBORS; i++) {
            neighbors[i] = i < n ? ALIVE : DEAD;
        }

        print_cells(neighbors);

        /* Check whether the cell is now alive or dead. */

        if (n < LOWER_POPULATION_BOUND ||
            n > UPPER_POPULATION_BOUND) {
            printf("%d neighbors are alive, cell should be DEAD\n", n);
            assert(evolve_cell(neighbors) == DEAD);
        } else {
            printf("%d neighbors are alive, cell should be ALIVE\n", n);
            assert(evolve_cell(neighbors) == ALIVE);
        }
    }
}

void print_cells(Cell cells[NUMBER_OF_NEIGHBORS]) {
    int i;
    for (i = 0; i < NUMBER_OF_NEIGHBORS; i++) {
        printf("%c ", cells[i]);
    }
    printf("\n");
}
