#include <stdio.h>
#include "sort.h"

int main(void) {

  int arr[5] = { 3, 2, 0, 6, 5 };

  printf("    Unsorted: {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  sort(arr, 5, increasing);
  printf("Sorted (inc): {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  sort(arr, 5, decreasing);
  printf("Sorted (dec): {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  return 0;
}
