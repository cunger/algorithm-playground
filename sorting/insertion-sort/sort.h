/* A comparison function compares two integers x and y,
   and returns -1 if x < y, 1 if y < x, and 0 otherwise. */
typedef int (*comparison)(int, int);

/* Sort array of integers in custom order,
   according to a given comparison function. */
void sort(int sequence[], int size, comparison compare);

/* Utility comparison functions. */
int increasing(int x, int y);
int decreasing(int x, int y);

/* Sort array of integers in increasing order. */
void sort_inc(int sequence[], int size);

/* Sort array of integers in decreasing order. */
void sort_dec(int sequence[], int size);
