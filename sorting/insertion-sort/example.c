#include <stdio.h>
#include "../../linkedlist/linkedlist.h"
#include "sort.h"

int main(void) {

  // Insertion sort for arrays.

  int arr1[0] = {};
  sort(arr1, 0);

  int arr2[1] = { 1 };
  sort(arr2, 1);
  printf("{%d}\n", arr2[0]);

  int arr3[5] = { 3, 2, 0, 6, 5 };

  printf("{%d, %d, %d, %d, %d}\n", arr3[0], arr3[1], arr3[2], arr3[3], arr3[4]);

  sort(arr3, 5);

  printf("{%d, %d, %d, %d, %d}\n", arr3[0], arr3[1], arr3[2], arr3[3], arr3[4]);

  // Insertion sort for linked lists.

  // Edge case: list with only one element is already sorted.

  linkedlist singleton = init(1);

  pretty_print(singleton);
  sort_ll(&singleton);
  pretty_print(singleton);

  destroy(&singleton);

  // Simple example.

  linkedlist simple = init(1);
  add(3, simple);
  add(2, simple);

  pretty_print(simple);
  sort_ll(&simple);
  pretty_print(simple);

  destroy(&simple);

  // Intricate example, where sorting needs to insert either at the beginning
  // or end of the subsequence.

  linkedlist numbers = init(5);
  add(2, numbers);
  add(0, numbers);
  add(9, numbers);
  add(3, numbers);

  pretty_print(numbers);
  sort_ll(&numbers);
  pretty_print(numbers);

  destroy(&numbers);

  return 0;
}
