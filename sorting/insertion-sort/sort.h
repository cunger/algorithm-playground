/* A comparison function compares two integers x and y,
   and returns -1 if x < y, 1 if y < x, and 0 otherwise. */
typedef int (*comparison)(int, int);

/* Utility comparison functions. */
int increasing(int x, int y);
int decreasing(int x, int y);

/* Sort array of integers according to a given comparison function. */
void sort(int sequence[], int size, comparison compare);
