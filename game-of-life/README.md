
This is an implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life).

## Build and run

```
$ make build
$ ./run
```

Parameters like the size of the grid, the prior probability of a cell to be alive when randomly initialized, the over- and underpopulation thresholds, as well as the number of generations can be adapted in `config.h`. 

## Test

```
$ make test
```
