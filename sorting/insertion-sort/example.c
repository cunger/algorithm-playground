#include "../../linkedlist/linkedlist.h"
#include "sort.h"

int main(void) {

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

  linkedlist numbers = init(5);
  add(2, numbers);
  add(0, numbers);
  add(9, numbers);
  add(3, numbers);

  pretty_print(numbers);
  sort(&numbers);
  pretty_print(numbers);

  destroy(&numbers);

  return 0;
}
