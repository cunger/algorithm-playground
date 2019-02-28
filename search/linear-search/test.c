#include "search.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
  int targetValue = 1;

  int sequencePos1[6] = {1, 0, 0, 0, 0, 0};
  assert(indexOf(targetValue, sequencePos1, 6) == 0);

  int sequencePos2[6] = {0, 0, 0, 0, 0, 1};
  assert(indexOf(targetValue, sequencePos2, 6) == 5);

  int sequencePos3[6] = {0, 0, 1, 0, 0, 0};
  assert(indexOf(targetValue, sequencePos3, 6) == 2);

  int sequencePos4[6] = {0, 0, 1, 0, 1, 0};
  assert(indexOf(targetValue, sequencePos4, 6) == 2);

  int sequenceNeg1[6] = {0, 0, 2, 0, 4, 0};
  assert(indexOf(targetValue, sequenceNeg1, 6) == -1);

  int sequenceNeg2[0] = {};
  assert(indexOf(targetValue, sequenceNeg2, 0) == -1);

  printf("All tests succeeded.\n");
}
