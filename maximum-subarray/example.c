#include <stdio.h>
#include <assert.h>
#include "maximum-subarray.h"

int main(void) {

  int example1[3] = { 1, -2, 3 };
  int example2[6] = { -2, 4, -1, 2, 1, -5 };
  int example3[8] = { -2, -3, 4, -1, -2, 1, 5, -3 };

  /* Checking that sum() works correctly. */

  assert(sum(example2, 0, 5) == -1);
  assert(sum(example2, 1, 1) == 4);
  assert(sum(example2, 1, 4) == 6);
  assert(sum(example2, 0, -1) == 0);

  /* Checking that max_subarray() works correctly. */

  assert(max_subarray(example1, 0, 2) == 3);
  assert(max_subarray(example2, 0, 5) == 6);
  assert(max_subarray(example3, 0, 7) == 7);

  int positives1[4] = { 1, 2, 3, 4 };
  int positives2[1] = { 1 };

  assert(max_subarray(positives1, 0, 3) == 10);
  assert(max_subarray(positives2, 0, 0) == 1);

  int negatives1[3] = { -1, -2, -3 };
  int negatives2[1] = { -1 };

  assert(max_subarray(negatives1, 0, 2) == 0);
  assert(max_subarray(negatives2, 0, 0) == 0);

  return 0;
}
