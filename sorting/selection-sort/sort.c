#include "sort.h"

void sort(int sequence[], int size, comparison compare) {
  /* Index to be advanced through the whole array.
     The elements up to the index are sorted, all
     following ones are still to sort. */
  int index;

  for (index = 0; index < size; index++) {
    int min_index = find_minimum(sequence, index, size - 1, compare);
    swap(sequence, index, min_index);
  }
}

int find_minimum(const int sequence[], int from_index, int to_index, comparison compare) {
  int min_index = from_index;
  int min_value = sequence[from_index];
  int i;
  for (i = from_index + 1; i <= to_index; i++) {
    if (compare(sequence[i], min_value) < 0) {
      min_index = i;
    }
  }

  return min_index;
}

void swap(int sequence[], int index1, int index2) {
  int temp = sequence[index1];
  sequence[index1] = sequence[index2];
  sequence[index2] = temp;
}
