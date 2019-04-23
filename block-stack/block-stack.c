#include <stdbool.h>
#include <assert.h>
#include "block-stack.h"

void sanity_check(int bottom, int top) {
  assert(bottom >= 0 && bottom < SIZE);
  assert(top >= 0 && top < SIZE);
  assert(bottom <= top);
}

bool is_stable(int weights[SIZE], int positions[SIZE]) {
  return find_topmost_unstable(weights, positions) < 0;
}

int find_topmost_unstable(int weights[SIZE], int positions[SIZE]) {
  /* A stack containing one or no block is trivially stable.
     For more blocks, start with the top two, and then move
     to the bottom of the stack, checking whether each upper
     part of the stack is stable. */

  bool stable = true;

  int top = SIZE - 1;
  int bottom = top - 1;

  while (bottom > 0 && stable) {
    /* Weight and position of bottom block. */
    int weight_bottom = weights[bottom];
    double position_bottom = (double) positions[bottom];

    /* Center of gravity of all blocks on top combined. */
    double position_top = joint_position(weights, positions, bottom + 1, top);

    /* Compare bottom block and the combined blocks above. */
    stable = are_stable(position_top, position_bottom, weight_bottom);
    bottom--;
  }

  if (stable) {
    return -1;
  } else {
    return bottom;
  }
}

bool are_stable(double position_top, double position_bottom, int weight_bottom) {
  /* Check whether the two specified blocks are stable:
     Determine the left- and right-most positions at which the upper block
     could rest on the lower block, and check whether it is positioned
     within these boundaries. */
  double left_bound  = position_bottom - (double) weight_bottom / 2;
  double right_bound = position_bottom + (double) weight_bottom / 2;

  return position_top > left_bound && position_top < right_bound;
}

int joint_weight(int weights[SIZE], int bottom, int top) {
  sanity_check(bottom, top);

  int total_weight = 0;
  int i;
  for (i = bottom; i <= top; i++) {
    total_weight += weights[i];
  }

  return total_weight;
}

double joint_position(int weights[SIZE], int positions[SIZE], int bottom, int top) {
  sanity_check(bottom, top);

  int total_weight = joint_weight(weights, bottom, top);
  int joint = 0;
  int i;
  for (i = bottom; i <= top; i++) {
    joint += positions[i] * weights[i];
  }

  return (double) joint / total_weight;
}
