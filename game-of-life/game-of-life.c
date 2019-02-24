#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "game-of-life.h"

Grid* init_generation(void) {
    srand(time(NULL));

    Grid* grid = calloc(GRID_HEIGHT * GRID_WIDTH, sizeof(Cell));
    assert(grid);

    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int column = 0; column < GRID_WIDTH; column++) {
            *grid[row][column] = random_cell(PRIOR_PROBABILITY_TO_BE_ALIVE);
        }
    }

    return grid;
}

Grid* next_generation(const Grid* grid, evolution evolve) {
    Grid* next_grid = (Grid*) calloc(GRID_WIDTH * GRID_HEIGHT, sizeof(Cell));
    assert(next_grid);

    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int column = 0; column < GRID_WIDTH; column++) {
            Cell neighbors[NUMBER_OF_NEIGHBORS] = {
                get_cell(grid, row - 1, column - 1),
                get_cell(grid, row - 1, column),
                get_cell(grid, row - 1, column + 1),
                get_cell(grid, row, column - 1),
                /* get_cell(row, column) is the cell itself, not a neighbor. */
                get_cell(grid, row, column + 1),
                get_cell(grid, row + 1, column - 1),
                get_cell(grid, row + 1, column),
                get_cell(grid, row + 1, column + 1)
            };

            *next_grid[row][column] = evolve(neighbors);
        }
    }

    return next_grid;
}

Cell evolve_cell(const Cell neighbors[NUMBER_OF_NEIGHBORS]) {
    int number_of_alive_neighbors = count_alive(neighbors, NUMBER_OF_NEIGHBORS);
    if (number_of_alive_neighbors < LOWER_POPULATION_BOUND ||
        number_of_alive_neighbors > UPPER_POPULATION_BOUND) {
        return DEAD;
    } else {
        return ALIVE;
    }
}

Cell random_cell(double prior_probability_to_be_alive) {
    if (prior_probability_to_be_alive == 0) return DEAD;
    if (prior_probability_to_be_alive == 1) return ALIVE;

    double random = (double) rand() / (double) ((unsigned) RAND_MAX + 1);
    return (random < prior_probability_to_be_alive ? ALIVE : DEAD);
}

int out_of_bounds(int row, int column) {
    return row < 0 || column < 0 || row == GRID_HEIGHT || column == GRID_WIDTH;
}

Cell get_cell(const Grid* grid, int row, int column) {
    return out_of_bounds(row, column) ? DEAD : *grid[row][column];
}

int count_alive(const Cell cells[], int size) {
    int count = 0;

    int i;
    for (i = 0; i < size; i++) {
        if (cells[i] == ALIVE) {
            count++;
        }
    }

    return count;
}

void display(const Grid* grid) {
  for (int row = 0; row < GRID_HEIGHT; row++) {
      for (int column = 0; column < GRID_WIDTH; column++) {
          printf("%c ", *grid[row][column]);
      }

      printf("\n");
  }
}

void destroy(Grid* grid) {
    free(grid);
}
