#include "sort.h"

void sort(int sequence[], int size, comparison compare) {
  merge_sort(sequence, 0, size - 1, compare);
}

void merge_sort(int sequence[], int i, int k, comparison compare) {
  if (i == k) return;

  // Determine center index.
  int j = i + (k - i) / 2;

  // Sort left subarray and right subarray, and then merge them.
  merge_sort(sequence, i, j, compare);
  merge_sort(sequence, j + 1, k, compare);
  merge(sequence, i, j, k, compare);
}

void merge(int sequence[], int i, int j, int k, comparison compare) {
  int sorted[(k - i) + 1];

  int left = i;
  int right = j + 1;
  int index = 0;

  while (left <= j && right <= k) {
    if (compare(sequence[left], sequence[right]) < 0) {
      sorted[index] = sequence[left];
      left++;
    } else {
      sorted[index] = sequence[right];
      right++;
    }

    index++;
  }

  // Copy remaining elements.

  while (left <= j) {
    sorted[index] = sequence[left];
    left++;
    index++;
  }

  while (right <= k) {
    sorted[index] = sequence[right];
    right++;
    index++;
  }

  // Transfer elements from sorted into sequence.

  for (index = i; index <= k; index++) {
    sequence[index] = sorted[index - i];
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
