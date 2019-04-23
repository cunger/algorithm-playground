#include <stdbool.h>

/*
A stack of blocks is specified by two parameters:
  int weights[SIZE]   : vector containing the weights of all blocks
  int positions[SIZE] : vector containing the positions of the block's
                        centers of gravity
*/

/* Number of blocks on the stack. */
#define SIZE 7

/*
Notes on referring to blocks on a stack:
The index of a block on the stack is zero-based, and is counted from bottom
to top. So the lowest block has index 0, and the topmost block has index
SIZE - 1.

When referring to a part of the stack, the start and end index refer to the
top and bottom index to include, respectively.
*/
void sanity_check(int bottom, int top);

/* Determine whether a stack of blocks is stable. */
bool is_stable(int weights[SIZE], int positions[SIZE]);

/* Determine whether two blocks on top of each other are stable. */
bool are_stable(double position_top, double position_bottom, int weight_bottom);

/* Find the index of the topmost unstable block on a stack.
   Returns a negative number if the stack is stable. */
int find_topmost_unstable(int weights[SIZE], int positions[SIZE]);

/* Determine the first position to the left or right of a block,
   for which the stack becomes unstable. */
int find_first_unstable_position_to_left(int weights[SIZE], int positions[SIZE], int block);
int find_first_unstable_position_to_right(int weights[SIZE], int positions[SIZE], int block);

/* Determine the total weight and position of a part of the stack. */
int joint_weight(int weights[SIZE], int bottom, int top);
double joint_position(int weights[SIZE], int positions[SIZE], int bottom, int top);
