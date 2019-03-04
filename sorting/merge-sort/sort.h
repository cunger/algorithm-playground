#include "../comparison.h"

/* Sort array of integers according to a given comparison function. */
void sort(int sequence[], int size, comparison compare);

/* Helper functions implementing merge sort. */
void merge_sort(int sequence[], int start_index, int end_index, comparison compare);
void merge(int sequence[], int start_index, int center_index, int end_index, comparison compare);
