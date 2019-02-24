#include "config.h"

typedef char Cell;
typedef Cell Grid[GRID_HEIGHT][GRID_WIDTH];

#define ALIVE 'O'
#define DEAD  'X'

#define NUMBER_OF_NEIGHBORS 8

Cell random_cell(double prior_probability_to_be_alive);

/*
Helper function for retrieving a cell from a grid, which is like
*grid[row][column] but with an additional out-of-bounds check.
This simplifies retrieving the neighbors of a cell, as now all
cells can be treated equal, retrieving eight neighbors, independent
of whether they are at the edge of the grid or not. Neighbors that
are outside of the grid are treated like DEAD cells.
*/
Cell get_cell(const Grid* grid, int row, int column);

Cell evolve_cell(const Cell neighbors[NUMBER_OF_NEIGHBORS]);
typedef Cell (*evolution) (const Cell neighbors[NUMBER_OF_NEIGHBORS]);

Grid* init_generation(void);
Grid* next_generation(const Grid* grid, evolution evolve);

int count_alive(const Cell cells[], int size);

void display(const Grid* grid);
void destroy(Grid* grid);
