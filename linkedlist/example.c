#include <stdio.h>
#include "linkedlist.h"

int main() {
  node third  = { 3, NULL };
  node second = { 2, &third };
  node first  = { 1, &second };

  linkedlist numbers = &first;

  pretty_print(numbers);
  printf("length: %d\n", length(numbers));

  linkedlist numbers_again = init(1);

  pretty_print(numbers_again);
  printf("length: %d\n", length(numbers_again));

  add(&numbers_again, 2);
  add(&numbers_again, 3);

  pretty_print(numbers_again);
  printf("length: %d\n", length(numbers_again));

  destroy(&numbers_again);

  return 0;
}
