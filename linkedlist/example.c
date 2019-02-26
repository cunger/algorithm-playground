#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"

int main() {
  linkedlist numbers = init(1);

  pretty_print(numbers);
  assert(length(numbers) == 1);

  add(2, numbers);
  add(3, numbers);

  pretty_print(numbers);
  assert(length(numbers) == 3);

  assert(get(-1, numbers) == NULL);
  assert(get(0, numbers)->data == 1);
  assert(get(1, numbers)->data == 2);
  assert(get(2, numbers)->data == 3);
  assert(get(3, numbers) == NULL);

  insert_after(0, 4, numbers);
  insert_after(3, 5, numbers);

  pretty_print(numbers);

  printf("delete(1)\n");
  delete(1, &numbers);
  pretty_print(numbers);

  printf("delete(0)\n");
  delete(0, &numbers);
  pretty_print(numbers);

  printf("delete(2)\n");
  delete(2, &numbers);
  pretty_print(numbers);

  // Insertion and deletion at out-of-bounds index leaves list untouched.

  insert_after(9, 0, numbers);
  pretty_print(numbers);

  delete(8, &numbers);
  pretty_print(numbers);

  // Moving a node.

  add(5, numbers);
  add(9, numbers);
  pretty_print(numbers);

  printf("move(2,1)\n");
  move(2, 1, &numbers);
  pretty_print(numbers);

  printf("move(1,1)\n");
  move(1, 1, &numbers);
  pretty_print(numbers);

  printf("move(2,0)\n");
  move(2, 0, &numbers);
  pretty_print(numbers);

  printf("move(3,1)\n");
  move(3, 1, &numbers);
  pretty_print(numbers);

  printf("move(3,0)\n");
  move(3, 0, &numbers);
  pretty_print(numbers);

  printf("move(0,3)\n");
  move(0, 3, &numbers);
  pretty_print(numbers);

  // Clean up.

  destroy(&numbers);

  // Insertion sort for linked lists.

  // Edge case: list with only one element is already sorted.

  linkedlist singleton = init(1);

  pretty_print(singleton);
  sort(&singleton);
  pretty_print(singleton);

  destroy(&singleton);

  // Simple example.

  linkedlist simple = init(1);
  add(3, simple);
  add(2, simple);

  pretty_print(simple);
  sort(&simple);
  pretty_print(simple);

  destroy(&simple);

  // Intricate example, where sorting needs to insert either at the beginning
  // or end of the subsequence.

  linkedlist intricate = init(5);
  add(2, intricate);
  add(0, intricate);
  add(9, intricate);
  add(3, intricate);

  pretty_print(intricate);
  sort(&intricate);
  pretty_print(intricate);

  destroy(&intricate);

  return 0;
}
