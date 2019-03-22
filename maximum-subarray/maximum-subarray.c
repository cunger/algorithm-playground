#include "maximum-subarray.h"

int sum(const int array[], int start_index, int end_index) {
  int sum = 0;
  int i;
  for (i = start_index; i <= end_index; i++) {
    sum += array[i];
  }

  return sum;
}
