#include "sort.h"

void sort_inc(int sequence[], int size) {
  sort(sequence, size, increasing);
}

void sort_dec(int sequence[], int size) {
  sort(sequence, size, decreasing);
}

void sort(int sequence[], int size, comparison compare) {
  int i;
  for (i = 1; i < size; i++) {
    int element = sequence[i];

    int j = i - 1;
    while (j >= 0 && compare(sequence[j], element) > 0) {
      sequence[j + 1] = sequence[j];
      j--;
    }

    sequence[j + 1] = element;
  }
}

int increasing(int x, int y) {
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

int decreasing(int x, int y) {
  if (x > y) return -1;
  if (x < y) return 1;
  return 0;
}
