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

  return 0;
}
