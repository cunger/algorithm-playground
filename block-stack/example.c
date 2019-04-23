#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "block-stack.h"

int main(void) {
  bool stable;

  int stable_weights[SIZE]   = { 9, 9, 5, 7, 7, 5, 3 };
  int stable_positions[SIZE] = { 0, -1, -3, -3, -5, -7, -9 };

  stable = is_stable(stable_weights, stable_positions);

  printf("stable? %d\n", stable);
  assert(stable);

  int unstable_weights[SIZE]   = { 9, 9, 5, 7, 7, 5, 3 };
  int unstable_positions[SIZE] = { 0, -1, -7, -3, -5, -7, -9 };

  stable = is_stable(unstable_weights, unstable_positions);

  printf("stable? %d\n", stable);
  assert(!stable);

  return 0;
}
