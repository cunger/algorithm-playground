/*
A comparison function compares two integers x and y, and returns
  -1 if x should come before y,
   1 if y should come before x,
   0 otherwise.
*/
typedef int (*comparison)(int, int);

/* Utility comparison functions for increasing and decreasing order. */
int increasing(int x, int y);
int decreasing(int x, int y);
