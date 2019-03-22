#include "maximum-subarray.h"

int max_subarray(const int array[], int start_index, int end_index) {
  int max_sum = 0;
  int max_sum_up_to_n = 0;

  int n;
  for (n = start_index; n <= end_index; n++) {
    max_sum_up_to_n = max_of(0, max_sum_up_to_n + array[n]);

    if (max_sum_up_to_n > max_sum) {
      max_sum = max_sum_up_to_n;
    }
  }

  return max_sum;
}
