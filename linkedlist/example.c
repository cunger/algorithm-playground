#include <stdio.h>
#include "linkedlist.h"

int main() {
  linkedlist numbers = init(1);

  pretty_print(numbers);
  printf("length: %d\n", length(numbers));

  add(2, numbers);
  add(3, numbers);

  pretty_print(numbers);
  printf("length: %d\n", length(numbers));

  printf("get(0): %d\n", get(0, numbers)->data);
  printf("get(1): %d\n", get(1, numbers)->data);
  printf("get(2): %d\n", get(2, numbers)->data);

  insert_after(0, 4, numbers);
  insert_after(3, 5, numbers);

  pretty_print(numbers);

  delete(1, numbers);

  pretty_print(numbers);

  // Insertion and deletion at out-of-bounds index leaves list untouched.

  insert_after(9, 0, numbers);
  pretty_print(numbers);

  delete(8, numbers);
  pretty_print(numbers);

  // Clean up.

  destroy(&numbers);

  return 0;
}
