#include "maximum-subarray.h"

int find_max_cross_sum(const int array[], int start_index, int center_index, int end_index);

int max_subarray(const int array[], int start_index, int end_index) {
  if (start_index == end_index) {
    return max_of(0, array[start_index]);
  }

  int center_index = start_index + (end_index - start_index) / 2;

  int max_sum_left  = max_subarray(array, start_index, center_index);
  int max_sum_right = max_subarray(array, center_index + 1, end_index);
  int max_sum_cross = find_max_cross_sum(array, start_index, center_index, end_index);

  return max_of(max_sum_cross, max_of(max_sum_left, max_sum_right));
}

int find_max_cross_sum(const int array[], int start_index, int center_index, int end_index) {
  /* Walk from center index to the left, and determine greatest sum. */
  int max_sum_left = 0;
  int current_sum_left = 0;
  int i;
  for (i = center_index; i >= start_index; i--) {
    current_sum_left += array[i];
    if (current_sum_left > max_sum_left) {
      max_sum_left = current_sum_left;
    }
  }

  /* Walk from center index to the right, and determine greatest sum. */
  int max_sum_right = 0;
  int current_sum_right = 0;
  int j;
  for (j = center_index + 1; j <= end_index; j++) {
    current_sum_right += array[j];
    if (current_sum_right > max_sum_right) {
      max_sum_right = current_sum_right;
    }
  }

  /* Return sum of both. */
  return max_sum_left + max_sum_right;
}
