#include "../comparison.h"

/*
Sort array of integers according to a given comparison function.
*/
void sort(int sequence[], int size, comparison compare);

/*
Find minimum element in a subarray of `sequence`.
Returns the index of the minimum element, and -1 if the subarray is empty.
*/
int find_minimum(const int sequence[], int from_index, int to_index, comparison compare);

/*
Swap two elements in an array.
*/
void swap(int sequence[], int index1, int index2);
